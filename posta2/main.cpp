#include <stdio.h>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;

vector <pair <int, int> > G[100100];
bool isSpecial[100100], vis[100100];
int C[100100], sum[100100], grad[100100];

void dfs(int nod) {
    vector <pair <int, int> > :: iterator it;
    vis[nod] = 1;
    sum[nod] = isSpecial[nod];
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[it -> x]) {
            dfs(it -> x);
            sum[nod] += sum[it -> x];
        }
}

int main() {
    freopen("posta2.in", "r", stdin);
    freopen("posta2.out", "w", stdout);

    int N, M, K;
    scanf("%d%d", &N, &K);
    for (int i = 1; i < N; ++i) {
        int xx, yy, cost;
        scanf("%d%d%d", &xx, &yy, &cost);
        G[xx].push_back(make_pair(yy, cost));
        G[yy].push_back(make_pair(xx, cost));
    }
    for (int i = 1; i <= N; ++i)
        scanf("%d", &C[i]);
    for (int i = 1; i <= K; ++i) {
        int xx;
        scanf("%d", &xx);
        isSpecial[xx] = 1;
    }
    for (int i = 1; i <= N; ++i)
        if (isSpecial[i]) {
            dfs(i);
            break;
        }

    long long cost = 0;
    for (int xx = 1; xx <= N; ++xx) {
        vector <pair <int, int> > :: iterator it;
        if (sum[xx] == 0)
            continue;
        for (it = G[xx].begin(); it != G[xx].end(); ++it) {
            int yy = it -> x;
            if (sum[yy] == 0)
                continue;
            ++grad[xx];
            cost += it -> y;
        }
    }
    long long best = 0;
    for (int i = 1; i <= N; ++i)
        if (sum[i]) {
            cost += (grad[i] - 1) * C[i];
            if ((grad[i] - 1) * C[i] > best)
                best = (grad[i] - 1) * C[i];
        }

    printf("%lld", cost - best);
    return 0;
}
