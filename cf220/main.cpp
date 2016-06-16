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

ll d[100100], ways[100100];
char x[100100];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    d[0] = 0; ways[0] = 1;
    gets(x + 1);
    int n = strlen(x + 1);

    if (x[1] == '9')
        d[1] = ways[1] = 1;
    else
        d[1] = 0, ways[1] = 1;
    for (int i = 2; i <= n; ++i)
        if (x[i] == '9') {
            d[i] = d[i - 1] + 1;
            ways[i] = ways[i - 1];
        } else {
            if (x[i] + x[i - 1] - 2 * '0' == 9) {
                d[i] = d[i - 2] + 1;
                if (d[i - 1] > d[i]) {
                    d[i] = d[i - 1];
                    ways[i] = ways[i - 1];
                } else {
                    ways[i] = ways[i - 2];
                    if (d[i] == d[i - 1])
                        ways[i] += ways[i - 1];
                }
            } else
                d[i] = d[i - 1], ways[i] = ways[i - 1];
        }

    printf("%I64d", ways[n]);
    return 0;
}
