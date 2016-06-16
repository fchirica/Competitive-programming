#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct query {
    int x, y, ansx, ansy, ord;
} Q[500500];

vector <int> weak[500500];
int son[500500];
vector <int> GT[500500];
int whichWeak[500500];

void dfs1(int nod, int curComp) {
    whichWeak[nod] = curComp;
    vector <int> :: iterator it;
    for (it = weak[nod].begin(); it != weak[nod].end(); ++it)
        if (!whichWeak[*it])
            dfs1(*it, curComp);
}

inline bool comp(query A, query B) {
    return whichWeak[A.x] < whichWeak[B.x];
}

inline bool byIndex(query A, query B) {
    return A.ord < B.ord;
}

int cycle[500500], stk[500500];
bool vis[500500];
int visWeak[500500], visCycle[500500], weakComp[500500];
int cycleLink[500500];

void dfs2(int nod) {
    weakComp[++weakComp[0]] = nod;
    visWeak[nod] = 1;
    vector <int> :: iterator it;
    for (it = weak[nod].begin(); it != weak[nod].end(); ++it)
        if (!visWeak[*it])
            dfs2(*it);
}

void dfs3(int nod) {
    vector <int> :: iterator it;
    vis[nod] = 1;
    for (it = GT[nod].begin(); it != GT[nod].end(); ++it)
        if (!vis[*it])
            dfs3(*it);
    stk[++stk[0]] = nod;
}

void dfs4(int nod, int step) {
    visCycle[nod] = step;
    cycle[++cycle[0]] = nod;
    int next = son[nod];
    if (!visCycle[next])
        dfs4(next, step + 1);
}

int E[2 * 500500], First[500500], Lev[500500];
int nodeLevel[500500], RMQ[21][500500], lg[2 * 500500];

void dfs5(int nod, int level) {
    vector <int> :: iterator it;
    E[++E[0]] = nod;
    First[nod] = E[0];
    nodeLevel[nod] = level;
    Lev[E[0]] = level;
    for (it = GT[nod].begin(); it != GT[nod].end(); ++it) {
        if (*it == 923) {
            printf("MUIE");
        }
        dfs5(*it, level + 1);
        if (!cycleLink[*it])
            cycleLink[*it] = cycleLink[nod];
        E[++E[0]] = nod;
        Lev[E[0]] = level;
    }
}

void makeLog() {
    lg[1] = 0;
    for (int i = 2; i <= 1000100; ++i)
        lg[i] = lg[i / 2] + 1;
}

void makeRMQ() {
    for (int i = 1; i <= E[0]; ++i)
        RMQ[0][i] = i;
    for (int i = 1; (1 << i) <= E[0]; ++i)
        for (int j = 1; j + (1 << i) - 1 <= E[0]; ++j)
            if (Lev[RMQ[i - 1][j]] < Lev[RMQ[i - 1][j + (1 << (i - 1))]])
                RMQ[i][j] = RMQ[i - 1][j];
            else
                RMQ[i][j] = RMQ[i - 1][j + (1 << (i - 1))];
}

int LCA(int xx, int yy) {
    xx = First[xx];
    yy = First[yy];
    if (xx > yy)
        swap(xx, yy);
    int len = lg[yy - xx + 1];
    if (Lev[RMQ[len][xx]] < Lev[RMQ[len][yy - (1 << len) + 1]])
        return E[RMQ[len][xx]];
    return E[RMQ[len][yy - (1 << len) + 1]];
}

void loadTree(int nod) {
    weakComp[0] = 0;
    dfs2(nod);
    for (int i = 1; i <= weakComp[0]; ++i)
        if (!vis[weakComp[i]])
            dfs3(weakComp[i]);
    cycle[0] = 0;
    dfs4(stk[stk[0]], 1);
    GT[0].clear();
    for (int i = 1; i <= cycle[0]; ++i) {
        vector <int> :: iterator it;
        for (it = GT[cycle[i]].begin(); it != GT[cycle[i]].end(); ++it) {
            if (visCycle[*it])
                continue;
            cycleLink[*it] = cycle[i];
            GT[0].push_back(*it);
        }
    }
    E[0] = 0;
    dfs5(0, 0);
    makeRMQ();
}

int findCycleNode(int nod) {
    return cycleLink[nod];
}

int move(int X, int Y) {
    if (X <= Y)
        return Y - X;
    return cycle[0] - X + Y;
}

void solveQuery(int xx, int yy, int &ansx, int &ansy) {
    int lc = LCA(xx, yy);
    if (!visCycle[xx] && !visCycle[yy] && lc) {
        ansx = nodeLevel[xx] - nodeLevel[lc];
        ansy = nodeLevel[yy] - nodeLevel[lc];
        return ;
    }
    ansx = ansy = 0;
    if (!visCycle[xx]) {
        ansx = nodeLevel[xx];
        xx = findCycleNode(xx);
    }
    if (!visCycle[yy]) {
        ansy = nodeLevel[yy];
        yy = findCycleNode(yy);
    }
    xx = visCycle[xx]; yy = visCycle[yy];
    int ansx1 = ansx + move(xx, yy), ansx2 = ansx;
    int ansy1 = ansy, ansy2 = ansy + move(yy, xx);
    if (max(ansx1, ansy1) != max(ansx2, ansy2)) {
        if (max(ansx1, ansy1) < max(ansx2, ansy2))
            ansx = ansx1, ansy = ansy1;
        else
            ansx = ansx2, ansy = ansy2;
    } else {
        if (min(ansx1, ansy1) != min(ansx2, ansy2)) {
            if (min(ansx1, ansy1) < min(ansx2, ansy2))
                ansx = ansx1, ansy = ansy1;
            else
                ansx = ansx2, ansy = ansy2;
        } else {
            if (ansx1 >= ansy1)
                ansx = ansx1, ansy = ansy1;
            else
                ansx = ansx2, ansy = ansy2;
        }
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &son[i]);
        GT[son[i]].push_back(i);
        weak[i].push_back(son[i]);
        weak[son[i]].push_back(i);
    }

    int weakCnt = 0;
    for (int i = 1; i <= N; ++i)
        if (!whichWeak[i])
            dfs1(i, ++weakCnt);

    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &Q[i].x, &Q[i].y);
        Q[i].ord = i;
    }
    sort(Q + 1, Q + M + 1, comp);
    makeLog();

    for (int i = 1; i <= M; ++i) {
        if (Q[i].ord == 387) {
            int shit = 0;
            ++shit;
        }
        if (i == 1 || whichWeak[Q[i].x] != whichWeak[Q[i - 1].x])
            loadTree(Q[i].x);
        if (whichWeak[Q[i].x] != whichWeak[Q[i].y])
            Q[i].ansx = Q[i].ansy = -1;
        else {
            int ansx, ansy;
            solveQuery(Q[i].x, Q[i].y, ansx, ansy);
            Q[i].ansx = ansx; Q[i].ansy = ansy;
        }
    }

    sort(Q + 1, Q + M + 1, byIndex);
    for (int i = 1; i <= M; ++i)
        printf("%d %d\n", Q[i].ansx, Q[i].ansy);
    return 0;
}
