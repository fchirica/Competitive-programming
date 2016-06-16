#include <bits/stdc++.h>

using namespace std;

const int kNmax = 222;

int val[kNmax];
vector <int> G[kNmax];

int tt, in[kNmax], out[kNmax];
int h[kNmax], sum[kNmax];
bool vis[kNmax];

void dfs(int nod) {
    vis[nod] = 1;
    in[nod] = ++tt;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            h[*it] = h[nod] + 1;
            dfs(*it);
            sum[nod] += sum[*it];
        }
    out[nod] = ++tt;
    sum[nod] += val[nod];
}

bool is_father_son(int father, int son) {
    return in[father] <= in[son] && out[son] <= out[father];
}

int main() {
    freopen("petrica.in", "r", stdin);
    freopen("petrica.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);

    int res = 1e9;
    for (int i1 = 2; i1 <= n; ++i1)
        for (int i2 = 2; i2 <= n; ++i2)
            for (int i3 = 2; i3 <= n; ++i3) {
                if (i1 == i2 || i1 == i3 || i2 == i3)
                    continue;
                if (h[i1] <= h[i2] && h[i2] <= h[i3]) {
                    int sum1 = sum[i1];
                    int sum2 = sum[i2];
                    int sum3 = sum[i3];
                    if (is_father_son(i2, i3))
                        sum2 -= sum3;
                    if (is_father_son(i1, i2))
                        sum1 -= sum2;
                    if (is_father_son(i1, i3))
                        sum1 -= sum3;
                    int sum4 = sum[1] - sum1 - sum2 - sum3;
                    int allSums[] = {sum1, sum2, sum3, sum4};
                    int minSum, maxSum;
                    minSum = maxSum = sum1;
                    for (int i = 1; i < 4; ++i) {
                        minSum = min(minSum, allSums[i]);
                        maxSum = max(maxSum, allSums[i]);
                    }
                    if (maxSum - minSum < res)
                        res = maxSum - minSum;
                }
            }

    printf("%d", res);
    return 0;
}
