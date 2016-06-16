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

char x[1000100];
int pref[1000100];

int solve() {
    int n = strlen(x + 1);
    for (int i = 2; i <= n; ++i) {
        int pf = pref[i - 1];
        while (1) {
            if (x[i] == x[pf + 1]) {
                ++pf;
                break;
            }
            if (pf == 0)
                break;
            pf = pref[pf];
        }
        pref[i] = pf;
    }
    for (int i = n; i >= 1; --i)
        if (pref[i] && i % (i - pref[i]) == 0)
            return i;
    return 0;
}

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i) {
        gets(x + 1);
        printf("%d\n", solve());
    }

    return 0;
}
