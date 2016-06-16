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

int x[260100], pref[260100];
ll c[2601000];

int main() {
    freopen("zlego.in", "r", stdin);
    freopen("zlego.out", "w", stdout);

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &x[i]);
        for (int i = 1; i <= N; ++i)
            scanf("%lld", &c[i]);
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
        for (int i = N; i >= 1; --i)
            c[pref[i]] += c[i];
        for (int i = 1; i <= N; ++i)
            printf("%lld\n", c[i]);
    }

    return 0;
}
