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

char x[30100], rx[30100];
unsigned hx[30100], hrx[30100], pw[30100];

void buildHash(unsigned H[], char X[], int N) {
    for (int i = N; i >= 1; --i)
        H[i] = 71 * H[i + 1] + X[i];
    pw[0] = 1;
    for (int i = 1; i <= 30010; ++i)
        pw[i] = pw[i - 1] * 71;
}

unsigned get(int pos, int len, unsigned H[]) {
    return H[pos] - H[pos + len] * pw[len];
}

int main() {
    int K;
    scanf("%d\n", &K);
    gets(x + 1);
    int N = strlen(x + 1);
    for (int i = 1; i <= N; ++i)
        rx[N - i + 1] = x[i];

    buildHash(hx, x, N);
    buildHash(hrx, rx, N);

    int res = 0;
    for (int i = 1; i <= N - K + 1; ++i)
        if (get(i, K, hx) == get(N - i - K + 2, K, hrx))
            ++res;

    printf("%d", res);
    return 0;
}
