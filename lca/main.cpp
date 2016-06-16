#include <bits/stdc++.h>

using namespace std;

int dad[17][100100];

vector <int> G[100100];

int height[100100];

void dfs(int nod, int h) {
    height[nod] = h;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        dfs(*it, h + 1);
}

int main() {
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
        int d;
        scanf("%d", &d);
        dad[0][i] = d;
        G[d].push_back(i);
    }

    int lim;
    for (lim = 0; (1 << lim) <= n; ++lim); --lim;
    dfs(1, 0);
    for (int i = 1; i <= lim; ++i)
        for (int j = 1; j <= n; ++j)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];

    while (m--) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        if (height[xx] > height[yy])
            swap(xx, yy);
        int dif = height[yy] - height[xx];
        for (int i = 0; i <= lim; ++i)
            if (dif & (1 << i))
                yy = dad[i][yy];
        if (xx != yy) {
            for (int i = lim; i >= 0; --i)
                if (dad[i][xx] != dad[i][yy]) {
                    xx = dad[i][xx];
                    yy = dad[i][yy];
                }
            printf("%d\n", dad[0][xx]);
        } else
            printf("%d\n", xx);
    }

    return 0;
}
