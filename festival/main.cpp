#include <stdio.h>
#include <vector>

using namespace std;

int fw[650][650];
int what[650][650];
vector <int> G[650];

int cntComp = 0;
int cur[650], vis[650];

void DFS(int nod) {
    vis[nod] = 1;
    cur[++cur[0]] = nod;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            DFS(*it);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i, j, k, N, M1, M2;
    scanf("%d%d%d", &N, &M1, &M2);
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j) {
            if (i == j)
                fw[i][j] = 0;
            else
                fw[i][j] = 1 << 25;
            what[i][j] = -1;
        }
    int x, y;
    for (i = 1; i <= M1; ++i) {
        scanf("%d%d", &x, &y);
        fw[x][y] = -1; fw[y][x] = 1;
        G[x].push_back(y); G[y].push_back(x);
    }
    for (i = 1; i <= M2; ++i) {
        scanf("%d%d", &x, &y);
        fw[x][y] = 0;
        G[x].push_back(y);
    }

    //Weakly connected components
    for (i = 1; i <= N; ++i)
        if (!vis[i]) {
            ++cntComp; cur[0] = 0;
            DFS(i);
            for (j = 1; j <= cur[0]; ++j)
                for (k = 1; k <= cur[0]; ++k)
                    what[cur[j]][cur[k]] = cntComp;
        }

    for (k = 1; k <= N; ++k)
        for (i = 1; i <= N; ++i)
            for (j = 1; j <= N; ++j) {
                if (fw[i][k] + fw[k][j] < fw[i][j])
                    fw[i][j] = fw[i][k] + fw[k][j];
            }

    for (i = 1; i <= N; ++i)
        if (fw[i][i] < 0) {
            printf("NIE");
            return 0;
        }
    int sol[650];
    for (i = 1; i <= cntComp; ++i)
        sol[i] = 0;
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= N; ++j)
            if (what[i][j] > -1 && fw[i][j] > sol[what[i][j]])
                sol[what[i][j]] = fw[i][j];
    int tot = 0;
    for (i = 1; i <= cntComp; ++i)
        tot += sol[i] + 1;
    printf("%d", tot);
    return 0;
}
