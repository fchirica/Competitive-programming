#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int kNMax = 100100;

int myTest;
int ok;
int t;
vector <int> G[kNMax];
int ord[kNMax], eend[kNMax], vis[kNMax];
int subTree[kNMax];
bool gotX[kNMax], gotY[kNMax], gotZ[kNMax];
int _x, _y, _z;

void dfs(int nod) {
    ord[++t] = nod;
    vis[nod] = myTest;
    subTree[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (vis[*it] != myTest) {
            dfs(*it);
            subTree[nod] += subTree[*it];
            gotX[nod] |= gotX[*it];
            gotY[nod] |= gotY[*it];
            gotZ[nod] |= gotZ[*it];
        }
    if (subTree[nod] == _x)
        gotX[nod] = 1;
    if (subTree[nod] == _y)
        gotY[nod] = 1;
    if (subTree[nod] == _z)
        gotZ[nod] = 1;
    eend[nod] = t;
}

void doit(int x, int y, int n) {
    int lastT = -1;
    for (int i = n; i >= 1; --i)
        if (subTree[ord[i]] == y) {
            lastT = i;
            break;
        }
    for (int i = 1; i <= n; ++i)
        if (subTree[i] == x && eend[i] < lastT)
            ok = myTest;
    lastT = -1;
    for (int i = n; i >= 1; --i)
        if (subTree[ord[i]] == x) {
            lastT = i;
            break;
        }
    for (int i = 1; i <= n; ++i)
        if (subTree[i] == y && eend[i] < lastT)
            ok = myTest;
}

int main() {
    freopen("arbxyz.in", "r", stdin);
    freopen("arbxyz.out", "w", stdout);

    int t_cnt;
    scanf("%d", &t_cnt);

    for (myTest = 1; myTest <= t_cnt; ++myTest) {
        int n, x, y, z;
        scanf("%d%d%d%d", &n, &x, &y, &z);
        for (int i = 1; i < n; ++i) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            G[xx].push_back(yy);
            G[yy].push_back(xx);
        }
        memset(gotX, 0, sizeof(gotX));
        memset(gotY, 0, sizeof(gotY));
        memset(gotZ, 0, sizeof(gotZ));
        t = 0;
        _x = x; _y = y; _z = z;
        dfs(1);
        doit(x, y, n);
        if (ok != myTest)
            doit(y, z, n);
        if (ok != myTest)
            doit(x, z, n);
        if (ok != myTest) {
            for (int i = 1; i <= n; ++i) {
                if (subTree[i] == x + y && (gotX[i] || gotY[i]))
                    ok = myTest;
                if (subTree[i] == x + z && (gotX[i] || gotZ[i]))
                    ok = myTest;
                if (subTree[i] == y + z && (gotY[i] || gotZ[i]))
                    ok = myTest;
            }
        }
        printf("%d\n", (ok == myTest) ? 1 : 0);
        for (int i = 1; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}
