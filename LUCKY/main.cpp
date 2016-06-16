#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

bool bipartite;
int cntst, cnttmp, tmpx[200100], tmpy[200100], stx[200100], sty[200100];
int now, ord[100100], low[100100], col[100100];
bool isLucky[100100];

vector <int> G[100100], G2[100100];

void dfs2(int nod, int color) {
    vector <int> :: iterator it;
    col[nod] = color;
    if (bipartite == 0)
        return ;
    for (it = G2[nod].begin(); it != G2[nod].end(); ++it)
        if (col[*it] == -1)
            dfs2(*it, color ^ 1);
        else
            if (col[*it] != (color ^ 1)) {
                bipartite = 0;
                return ;
            }
}

void solveBiconnected(int xx, int yy) {
    int curx, cury;
    cnttmp = 0;
    do {
        curx = stx[cntst]; cury = sty[cntst];
        --cntst;
        tmpx[++cnttmp] = curx; tmpy[cnttmp] = cury;
    } while (!(curx == xx && cury == yy));
    for (int i = 1; i <= cnttmp; ++i) {
        G2[tmpx[i]].push_back(tmpy[i]);
        G2[tmpy[i]].push_back(tmpx[i]);
        col[tmpx[i]] = col[tmpy[i]] = -1;
    }
    bipartite = 1;
    dfs2(tmpx[1], 1);
    if (!bipartite)
        for (int i = 1; i <= cnttmp; ++i)
            isLucky[tmpx[i]] = isLucky[tmpy[i]] = 1;
    for (int i = 1; i <= cnttmp; ++i) {
        G2[tmpx[i]].clear();
        G2[tmpy[i]].clear();
    }
}

void dfs(int nod) {
    ord[nod] = low[nod] = ++now;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        stx[++cntst] = nod; sty[cntst] = *it;
        if (ord[*it] == 0) {
            dfs(*it);
            if (low[*it] < low[nod])
                low[nod] = low[*it];
            if (low[*it] >= ord[nod])
                solveBiconnected(nod, *it);
        } else
            if (ord[*it] < low[nod])
                low[nod] = ord[*it];
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= M; ++i) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            G[xx].push_back(yy);
            G[yy].push_back(xx);
        }
        now = cntst = cnttmp = 0;
        for (int i = 1; i <= N; ++i)
            if (!ord[i])
                dfs(i);
        int res = 0;
        for (int i = 1; i <= N; ++i)
            res += isLucky[i];
        printf("%d\n", res);
        for (int i = 1; i <= N; ++i) {
            ord[i] = low[i] = isLucky[i] = 0;
            G[i].clear();
        }
    }

    return 0;
}

