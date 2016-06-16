#include <stdio.h>
#include <vector>

using namespace std;

int col_cnt = 0;
int col[3000];

vector <int> G[222], inc[222];
int xx[3000], yy[3000], vis[3000];

int getFree(int nod) {
    for (int i = 1; i <= col_cnt + 1; ++i)
        vis[i] = 0;
    vector <int> :: iterator it;
    for (it = inc[nod].begin(); it != inc[nod].end(); ++it)
        vis[col[*it]] = 1;
    for (int i = 1; i <= col_cnt + 1; ++i)
        if (!vis[i])
            return i;
}

void dfs(int nod, int col1, int col2) {
    vector <int> :: iterator it;
    for (int i = 0; i < inc[nod].size(); ++i)
        if (col[inc[nod][i]] == col1) {
            dfs(G[nod][i], col2, col1);
            col[inc[nod][i]] = col2;
        }
}

int main() {
    freopen("colorare2.in", "r", stdin);
    freopen("colorare2.out", "w", stdout);

    int n, m, e;
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1; i <= e; ++i) {
        scanf("%d%d", &xx[i], &yy[i]);
        G[xx[i]].push_back(yy[i]);
        G[yy[i]].push_back(xx[i]);
        inc[xx[i]].push_back(i);
        inc[yy[i]].push_back(i);
    }

    for (int i = 1; i <= e; ++i) {
        int col1 = getFree(xx[i]);
        int col2 = getFree(yy[i]);
        if (col1 > col_cnt || col2 > col_cnt)
            ++col_cnt;
        dfs(yy[i], col1, col2);
        col[i] = col1;
    }

    printf("%d\n", col_cnt);
    for (int i = 1; i <= e; ++i)
        printf("%d\n", col[i]);
    return 0;
}
