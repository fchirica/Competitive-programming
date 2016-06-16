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

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

int x[100010];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    srand(time(0));

    int n;
    scanf("%d", &n);
    x[n] = 1;
    for (int i = 1; i < n; ++i)
        x[i] = 1;
    sort(x + 1, x + n + 1);

    ll sum = 0;
    for (int i = 2; i <= n; ++i)
        sum += x[n] - x[i];
    if (x[1] <= sum) {
        printf("%d", x[n]);
        return 0;
    }

    x[1] = x[1] - sum;
    ll res = x[n] + x[1] / (n - 1) + (bool)(x[1] % (n - 1));
    printf("%I64d", res);
    return 0;
}
