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

int x[100100];

multiset <pair <int, int> > H;

int A, B, in[1000100], dp[1000100];

int norm(int X) {
    return X - A + 1;
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    //#endif

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &x[i]);
    scanf("%d%d", &B, &A);
    sort(x + 1, x + N + 1);

    if (A == B) {
        printf("0");
        return 0;
    }

    for (int i = A; i <= B; ++i)
        in[norm(i)] = norm(i + 1);
    for (int i = 1; i <= N; ++i)
        if (x[i] != x[i - 1]) {
            int j = (A / x[i]) * x[i];
            while (j < A)
                j += x[i];
            for (; j <= B; j += x[i]) {
                chmax(in[norm(j)], norm(j + x[i] - 1));
                chmin(in[norm(j)], norm(B));
            }
        }

    H.insert(mp(0, in[1]));
    for (int i = 2; i <= B - A + 1; ++i) {
        while ((*H.begin()).y < i)
            H.erase(H.begin());
        dp[i] = (*H.begin()).x;
        H.insert(mp(dp[i] + 1, in[i]));
    }

    printf("%d", dp[B - A + 1] + 1);
    return 0;
}
