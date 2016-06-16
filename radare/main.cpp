#include <stdio.h>
#include <vector>
#define mod 31333

using namespace std;

vector <int> G[3100];
int timp, cost[3100], out[3100], L[6900], sum[3100], vis[3100], pw[3100];
int ways[3100][3600];

void dfs(int nod) {
    L[++timp] = nod;
    vis[nod] = sum[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            sum[nod] += sum[*it];
        }
    out[nod] = timp + 1;
}

void add(int &A, int B) {
    A += B;
    if (A >= mod)
        A -= mod;
}

int main() {
    freopen("radare.in", "r", stdin);
    freopen("radare.out", "w", stdout);

    int N, S;
    scanf("%d%d", &N, &S);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for (int i = 1; i <= N; ++i)
        scanf("%d", &cost[i]);

    dfs(1);
    pw[0] = 1;
    for (int i = 1; i <= N; ++i) {
        pw[i] = pw[i - 1] * 2;
        if (pw[i] >= mod)
            pw[i] -= mod;
    }

    ways[1][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= S; ++j)
            if (ways[i][j]) {
                int go = j + cost[L[i]];
                if (go <= S)
                    add(ways[i + 1][go], ways[i][j]);
                int ignore = ways[i][j] * pw[sum[L[i]] - 1] % mod;
                add(ways[out[L[i]]][j], ignore);
            }

    printf("%d", ways[N + 1][S]);
    return 0;
}
