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

int pos, N, x[10100];

bool B(), C();

bool B() {
    if (pos > N)
        return 0;
    if (x[pos] == 2) {
        ++pos;
        return B();
    }
    if (x[pos] == 1) {
        if (x[pos + 2] != 3)
            return 0;
        pos += 4;
        return C();
    }
    return 0;
}

bool C() {
    if (pos > N)
        return 0;
    if (x[pos] == 2)
        return 1;
    if (x[pos] == 3) {
        ++pos;
        if (!B())
            return 0;
        ++pos;
        return C();
    }
    if (x[pos] == 1) {
        if (x[pos + 1] != 2)
            return 0;
        pos += 2;
        return 1;
    }
}

int main() {
    freopen("perle.in", "r", stdin);
    freopen("perle.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &x[i]);
        int sol = 0;
        sol |= (N == 1);
        pos = 1; sol |= (B() && pos == N);
        pos = 1; sol |= (C() && pos == N);
        printf("%d\n", sol);
    }
    return 0;
}
