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
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

int m[6][6] = {
    {2, 1, 1, 0, 1, 2},
    {1, 2, 0, 1, 1, 2},
    {1, 1, 1, 0, 1, 2},
    {1, 1, 0, 1, 1, 2},
    {0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1}
};

int tmp[6][6], _B[6][6];
int mod;

void inm(int A[6][6], int B[6][6], int C[6][6]) { //C = A * B
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 6; ++k)
                C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j]) % mod;
        }
}

void copy(int A[6][6], int B[6][6]) {
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            A[i][j] = B[i][j];
}

void pw(int A[6][6], long long exp) {
    if (exp == 1)
        return ;
    copy(_B, A);
    pw(A, exp / 2);
    inm(A, A, tmp);
    copy(A, tmp);
    if (exp % 2) {
        inm(A, _B, tmp);
        copy(A, tmp);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int n, sx, sy, dx, dy;
    long long t;
    scanf("%d%d%d%d%d%I64d", &n, &sx, &sy, &dx, &dy, &t);
    mod = n;
    --sx; --sy;
    if (dx < 0)
        dx += n;
    if (dy < 0)
        dy += n;

    if (t == 0) {
        printf("%d %d", sx + 1, sy + 1);
        return 0;
    }

    pw(m, t);
    long long xx = (ll)m[0][0] * sx + (ll)m[0][1] * sy + (ll)m[0][2] * dx + (ll)m[0][3] * dy + m[0][5];
    long long yy = (ll)m[1][0] * sx + (ll)m[1][1] * sy + (ll)m[1][2] * dx + (ll)m[1][3] * dy + m[1][5];

    printf("%I64d %I64d", xx % n + 1, yy % n + 1);
    return 0;
}
