//stiu sa o rezolv, dar ma gandesc ca nu ar trebui sa stiu pentru cineva necalificat la ONI.
//asa ca luati de aici solutia cu random si incercati sa intelegeti de ce merge.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#define TRIES 100

using namespace std;

double startTime;

int C, bestPleasure;
int s[100100], p[100100], path[100100];
int ssum[100100], psum[100100], dad[100100];
bool vis[100100];
vector <int> G[100100];

void dfs(int nod) {
    vis[nod] = 1;
    ssum[nod] += s[nod];
    psum[nod] += p[nod];
    path[++path[0]] = nod;

    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            psum[*it] = psum[nod];
            ssum[*it] = ssum[nod];
            dad[*it] = nod;
            dfs(*it);
        }

    if (TRIES > path[0]) {
        for (int i = 1; i <= path[0]; ++i) {
            int nod2 = path[i];
            int mySum = ssum[nod] - ssum[dad[nod2]];
            int myPleasure = psum[nod] - psum[dad[nod2]];
            if (mySum <= C)
                if (myPleasure > bestPleasure)
                    bestPleasure = myPleasure;
        }
    }

    for (int i = 1; i <= TRIES; ++i) {
        int nod2 = (long long) rand() * rand() % path[0] + 1;
        nod2 = path[nod2];
        int mySum = ssum[nod] - ssum[dad[nod2]];
        int myPleasure = psum[nod] - psum[dad[nod2]];
        if (mySum <= C)
            if (myPleasure > bestPleasure)
                bestPleasure = myPleasure;
    }

    --path[0];
}

int main() {
    srand(12121);

    freopen("spiridusi.in", "r", stdin);
    freopen("spiridusi.out", "w", stdout);

    int n;
    scanf("%d%d", &n, &C);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]);

    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    memset(vis, 0, sizeof(vis));

    printf("%d", bestPleasure);
    return 0;
}
