#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector <pair <int, int> > G[100100];

int n, lim, ans;

int beer[100100];
bool vis[100100];
long long down[100100], closest[100100];

void dfs(int nod, int cup) {
    vis[nod] = 1;
    vector <pair <int, int> > :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[it -> first]) {
            dfs(it -> first, it -> second);
            down[nod] = min(down[nod], down[it -> first] - it -> second);
            closest[nod] = min(closest[nod], closest[it -> first] + it -> second);
        }

    if (nod == 1) {
        if (closest[nod] > down[nod])
            ++ans;
        return ;
    }
    if (closest[nod] <= down[nod])
        down[nod] = 1LL << 32;
    else
        if (down[nod] < cup) {
            ++ans;
            down[nod] = 1LL << 32;
            closest[nod] = 0;
        }
}

int solve(long long cmax) {
    ans = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        closest[i] = 1LL << 32;
        down[i] = cmax / beer[i];
    }
    dfs(1, 0);
    return ans;
}

void solveTest() {
    scanf("%d%d", &n, &lim);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &beer[i]);
    for (int i = 1; i < n; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        G[xx].push_back(make_pair(yy, cc));
        G[yy].push_back(make_pair(xx, cc));
    }

    long long st = 0, dr = 1LL << 40, res;
    while (st <= dr) {
        long long med = (st + dr) / 2;
        if (solve(med) <= lim) {
            res = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    printf("%lld\n", res);
    for (int i = 1; i <= n; ++i)
        G[i].clear();
}

int main() {
    freopen("berarii.in", "r", stdin);
    freopen("berarii.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--)
        solveTest();

    return 0;
}
