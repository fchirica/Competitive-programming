#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

int xx[350], yy[350], cc[350];
vector <pair <int, int> > G[222];
bool dp[1 << 8][201];

void dfs(int nod, int mask) {
    dp[mask][nod] = 1;
    vector <pair <int, int> > :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        int son = it -> first;
        if (mask & (1 << it -> second))
            continue ;
        int newMask = mask ^ (1 << it -> second);
        if (dp[newMask][son] == 0)
            dfs(son, newMask);
    }
}

void doit(int n, int m) {
    int nod, len;
    scanf("%d%d", &nod, &len);

    for (int iter = 1; iter <= 1500; ++iter) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
            cc[i] = rand() % len;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < G[i].size(); ++j) {
                for (int k = 1; k <= m; ++k) {
                    if (xx[k] == i && yy[k] == G[i][j].first) {
                        G[i][j].second = cc[k];
                        break;
                    }
                    if (yy[k] == i && xx[k] == G[i][j].first) {
                        G[i][j].second = cc[k];
                        break;
                    }
                }
            }
        dfs(nod, 0);
        if (dp[(1 << len) - 1][nod]) {
            printf("1\n");
            return ;
        }
    }
    printf("0\n");
}

int main() {
    srand(time(0));

    freopen("ciclu2.in", "r", stdin);
    freopen("ciclu2.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &xx[i], &yy[i]);
        G[xx[i]].push_back(make_pair(yy[i], 0));
        G[yy[i]].push_back(make_pair(xx[i], 0));
    }

    int q;
    scanf("%d", &q);
    while (q--)
        doit(n, m);
    return 0;
}
