#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

const int kNMAX = 100100;

int val[kNMAX];
vector <int> G[kNMAX];

int subTree[kNMAX], lev[kNMAX];
bool vis[kNMAX];

void dfs(int nod) {
    vis[nod] = 1;
    subTree[nod] = 1;

    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            lev[*it] = lev[nod] + 1;
            dfs(*it);
            subTree[nod] += subTree[*it];
        }
}

int cntLant, lungLant[kNMAX], incLant[kNMAX], tataLant[kNMAX];
int lantNod[kNMAX], pozNod[kNMAX];

vector <int> aint[kNMAX];

void dfs2(int nod, int lant) {
    ++lungLant[lant];
    lantNod[nod] = lant;
    pozNod[nod] = lungLant[lant];
    vis[nod] = 1;

    int bestSub = 0;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            if (subTree[*it] > bestSub)
                bestSub = subTree[*it];
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it] && subTree[*it] == bestSub) {
            dfs2(*it, lant);
            break;
        }
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            ++cntLant;
            incLant[cntLant] = *it;
            tataLant[cntLant] = nod;
            dfs2(*it, cntLant);
        }
}

void update(int lant, int nod, int st, int dr, int pos, int val) {
    if (st == dr) {
        aint[lant][nod] = val;
        return ;
    }

    int med = (st + dr) / 2;
    if (pos <= med)
        update(lant, 2 * nod, st, med, pos, val);
    else
        update(lant, 2 * nod + 1, med + 1, dr, pos, val);

    aint[lant][nod] = max(aint[lant][2 * nod], aint[lant][2 * nod + 1]);
}

int query(int lant, int nod, int st, int dr, int qst, int qdr) {
    if (qst > qdr)
        swap(qst, qdr);
    if (qst <= st && dr <= qdr)
        return aint[lant][nod];

    int med = (st + dr) / 2, res = 0;
    if (qst <= med)
        res = query(lant, 2 * nod, st, med, qst, qdr);
    if (med < qdr)
        res = max(res, query(lant, 2 * nod + 1, med + 1, dr, qst, qdr));

    return res;
}

int solve(int nod1, int nod2) {
    int res = 0;
    while (lantNod[nod1] != lantNod[nod2]) {
        if (lev[incLant[lantNod[nod1]]] < lev[incLant[lantNod[nod2]]])
            swap(nod1, nod2);
        res = max(res, query(lantNod[nod1], 1, 1, lungLant[lantNod[nod1]], 1, pozNod[nod1]));
        nod1 = tataLant[lantNod[nod1]];
    }

    res = max(res, query(lantNod[nod1], 1, 1, lungLant[lantNod[nod1]], pozNod[nod1], pozNod[nod2]));
    return res;
}

int main() {
    freopen("heavypath.in", "r", stdin);
    freopen("heavypath.out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    incLant[++cntLant] = 1;
    memset(vis, 0, sizeof(vis));
    dfs2(1, 1);

    for (int i = 1; i <= cntLant; ++i)
        aint[i].resize(4 * lungLant[i]);
    for (int i = 1; i <= n; ++i)
        update(lantNod[i], 1, 1, lungLant[lantNod[i]], pozNod[i], val[i]);

    for (int i = 1; i <= q; ++i) {
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        if (type == 0)
            update(lantNod[a], 1, 1, lungLant[lantNod[a]], pozNod[a], b);
        else
            printf("%d\n", solve(a, b));
    }

    return 0;
}
