#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int val[100100], vis[100100], path[100100], spec[100100], col[100100], deg[100100];
vector <int> G[100100];

void dfs(int nod) {
    vis[nod] = 1;
    path[++path[0]] = nod;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs(*it);
}

int cntVec(int nod) {
    int cnt = 0;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            ++cnt;
    return cnt;
}

int solvePath() {
    int sumEven = 0, sumOdd = 0;
    for (int i = 1; i <= path[0]; ++i)
        if (i % 2 == 0)
            sumEven += val[path[i]];
        else
            sumOdd += val[path[i]];
    return sumEven > sumOdd ? sumEven : sumOdd;
}

int main() {
    srand(12121);

    freopen("metrou.in", "r", stdin);
    freopen("metrou.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);

    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
        ++deg[xx]; ++deg[yy];
    }

    for (int i = 1; i <= n; ++i)
        if (deg[i] >= 3)
            spec[++spec[0]] = i;

    int sum = 0;
    int iter = 0;

    while (iter <= 100) {
        ++iter;

        for (int i = 1; i <= n; ++i)
            vis[i] = 0;

        int mySum = 0;
        for (int i = 1; i <= spec[0]; ++i) {
            col[i] = rand() % 2;
            if (col[i]) {
                mySum += val[spec[i]];
                vis[spec[i]] = 1;
            }
        }


        bool cannot = false;
        for (int i = 1; i <= spec[0]; ++i) {
            vector <int> :: iterator it;
            if (!col[i])
                continue;
            for (it = G[spec[i]].begin(); it != G[spec[i]].end(); ++it)
                if (vis[*it]) {
                    cannot = true;
                    break;
                }
        }
        if (cannot)
            continue;

        for (int i = 1; i <= spec[0]; ++i)
            vis[spec[i]] = 1;

        for (int i = 1; i <= spec[0]; ++i)
            if (col[i]) {
                vector <int> :: iterator it;
                for (it = G[spec[i]].begin(); it != G[spec[i]].end(); ++it)
                    vis[*it] = 1;
            }

        for (int i = 1; i <= n; ++i)
            if (vis[i] == 0 && cntVec(i) <= 1) {
                path[0] = 0;
                dfs(i);
                mySum += solvePath();
            }

        if (mySum > sum)
            sum = mySum;
    }

    printf("%d", sum);
    return 0;
}
