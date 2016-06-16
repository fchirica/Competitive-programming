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
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

int n, m;
ll a[100010],b[100010];

long long ab(long long x) {
    if(x > 0)
        return x;
    return -x;
}

ll func(int i, int x, int y) {
    return b[y] - b[x] + min(ab(a[i] - b[x]), ab(a[i] - b[y]));
}

int check(ll cmax) {
    /*int x, y = 0;

    for (int i = 1; i <= n; ++i) {
        x = y + 1; y = x;
        for (; func(i, x, y) <= val && y <= m; ++y);
        for (; func(i, x, y) >= val && x <= y; --y);
        if (y >= m)
            return 1;
    }
    return 0; */
    int x, y = 0;
    for(int i=1;i<=n; ++i) {
    x=y+1; y=x;
    for(;func(i,x,y)<=cmax && y<=m; ++y);
    for(;func(i,x,y)>cmax && x<=y; --y);
    if(y>=m) return 1;
    //cerr<<r<<' ';
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("I64d", &b[i]);

    ll st = 0, dr = 29000000000LL, med, ret = 0;
    while (st <= dr) {
        med = (st + dr) / 2;
        if (check(med)) {
            ret = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    printf("%I64d", ret);
    return 0;
}
