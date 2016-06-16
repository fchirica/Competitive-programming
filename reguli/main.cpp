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

ll x[500500];
int pref[500500];

int main() {
    freopen("reguli.in", "r", stdin);
    freopen("reguli.out", "w", stdout);

    int N;
    ll last;
    scanf("%d", &N); --N;
    for (int i = 0; i <= N; ++i) {
        scanf("%lld", &x[i]);
        ll cur = x[i];
        if (i)
            x[i] = x[i] - last;
        last = cur;
    }

    for (int i = 2; i <= N; ++i) {
        int pf = pref[i - 1];
        while (1) {
            if (x[pf + 1] == x[i]) {
                ++pf;
                break;
            }
            if (pf == 0)
                break;
            pf = pref[pf];
        }
        pref[i] = pf;
    }

    int cnt = N - pref[N];
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i)
        printf("%lld\n", x[i]);
    return 0;
}
