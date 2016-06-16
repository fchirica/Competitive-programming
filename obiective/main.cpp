#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector <int> ini[32100], GTini[32100], G[32100];
bool vis[32100];
int N, M, cnt, st[32100];
int iniToG[32100];

const int DIM = (1 << 12);
char buff[DIM];
int poz = 0;

void read(int &numar) {
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    while ('0' <= buff[poz] && buff[poz] <= '9') {
        numar = numar * 10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    }
}

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = GTini[nod].begin(); it != GTini[nod].end(); ++it)
        if (!vis[*it])
            dfs(*it);
    st[++st[0]] = nod;
}

void dfs2(int nod) {
    vis[nod] = 1;
    iniToG[nod] = cnt;
    vector <int> :: iterator it;
    for (it = ini[nod].begin(); it != ini[nod].end(); ++it)
        if (!vis[*it])
            dfs2(*it);
        else
            if (iniToG[nod] != iniToG[*it])
                G[iniToG[nod]].push_back(iniToG[*it]);
}

void buildDAG() {
    for (int i = 1; i <= N; ++i)
        if (!vis[i])
            dfs(i);
    memset(vis, 0, sizeof(vis));
    for (int i = st[0]; i >= 1; --i)
        if (!vis[st[i]]) {
            ++cnt;
            dfs2(st[i]);
        }
    N = cnt;
    for (int i = 1; i <= N; ++i) {
        vector <int> :: iterator it;
        it = unique(G[i].begin(), G[i].end());
        G[i].resize(distance(G[i].begin(), it));
    }
}

int root, deg[32100];

void findRoot() {
    for (int i = 1; i <= N; ++i) {
        vector <int> :: iterator it;
        for (it = G[i].begin(); it != G[i].end(); ++it)
            ++deg[*it];
    }
    for (int i = 1; i <= N; ++i)
        if (deg[i] == 0)
            root = i;
}

vector <int> treeEdge[32100], forwardEdge[32100];
int Lev[2 * 32100], First[32100], nodeLev[32100], Lg[66000];
int rmq[16][65000];

void dfs3(int nod, int level) {
    Lev[++cnt] = level;
    First[nod] = cnt;
    nodeLev[nod] = level;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!First[*it]) {
            dfs3(*it, level + 1);
            treeEdge[nod].push_back(*it);
            Lev[++cnt] = level;
        } else
            forwardEdge[*it].push_back(nod);
}

void RMQ() {
    for (int i = 0; i <= cnt; ++i)
        rmq[0][i] = Lev[i];
    for (int i = 1; (1 << i) <= cnt; ++i)
        for (int j = 1; j + (1 << i) - 1 <= cnt; ++j)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
    for (int i = 2; i < 66000; ++i)
        Lg[i] = Lg[i / 2] + 1;
}

int LCA(int xx, int yy) {
    xx = First[xx];
    yy = First[yy];
    if (xx > yy)
        swap(xx, yy);
    int len = Lg[yy - xx + 1];
    return min(rmq[len][xx], rmq[len][yy - (1 << len) + 1]);
}

int up[16][65000];

void dfs4(int nod, int father) {
    vector <int> :: iterator it;
    for (it = treeEdge[nod].begin(); it != treeEdge[nod].end(); ++it)
        dfs4(*it, nod);
    if (father == -1)
        return ;
    int bestUp = father, bestLev = nodeLev[father];
    for (it = treeEdge[nod].begin(); it != treeEdge[nod].end(); ++it)
        if (nodeLev[up[0][*it]] < bestLev) {
            bestUp = up[0][*it];
            bestLev = nodeLev[up[0][*it]];
        }
    for (it = forwardEdge[nod].begin(); it != forwardEdge[nod].end(); ++it)
        if (nodeLev[*it] < bestLev) {
            bestUp = *it;
            bestLev = nodeLev[*it];
        }
    up[0][nod] = bestUp;
}

void levelAscensor() {
    for (int i = 1; (1 << i) <= N; ++i)
        for (int j = 1; j <= N; ++j)
            up[i][j] = up[i - 1][up[i - 1][j]];
}

int solveQuery(int xx, int yy) {
    xx = iniToG[xx];
    yy = iniToG[yy];
    int expected = LCA(xx, yy), res = 0;
    if (nodeLev[xx] == expected)
        return 0;
    for (int i = Lg[nodeLev[xx] - expected]; i >= 0; --i)
        if (up[i][xx] && nodeLev[up[i][xx]] > expected) {
            res += (1 << i);
            xx = up[i][xx];
        }
    return res + 1;
}

inline bool comp(int A, int B) {
    return A > B;
}

void sortareTopologika() {
    for (int i = 1; i <= N; ++i)
        sort(G[i].begin(), G[i].end(), comp);
}

int main() {
    freopen("obiective.in", "r", stdin);
    freopen("obiective.out", "w", stdout);

    read(N); read(M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        read(xx); read(yy);
        ini[xx].push_back(yy);
        GTini[yy].push_back(xx);
    }

    buildDAG();
    findRoot();
    sortareTopologika();
    cnt = 0;
    dfs3(root, 1);
    RMQ();
    dfs4(root, -1);
    levelAscensor();

    int Q;
    read(Q);
    while (Q--) {
        int xx, yy;
        read(xx); read(yy);
        printf("%d\n", solveQuery(xx, yy));
    }

    return 0;
}
