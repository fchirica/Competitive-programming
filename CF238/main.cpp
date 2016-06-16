#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

bool used[1000100];
int res[1000100];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        used[x] = 1;
    }

    int N = 1000000;
    for (int i = 1; i <= N; ++i)
        if (used[i] && !used[N - i + 1])
            res[++res[0]] = N - i + 1;
    int cnt = 0;
    for (int i = 1; i <= N / 2; ++i)
        if (used[i] && used[N - i + 1])
            ++cnt;
    for (int i = 1; i <= N / 2; ++i)
        if (cnt > 0 && !used[i] && !used[N - i + 1]) {
            res[++res[0]] = i, res[++res[0]] = N - i + 1;
            --cnt;
        }
    printf("%d\n", res[0]);
    for (int i = 1; i <= res[0]; ++i)
        printf("%d ", res[i]);
    return 0;

}
