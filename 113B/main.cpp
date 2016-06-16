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

char S[2012], A[2012], B[2012];
int dp[2012][2012];
bool matchA[2012], matchB[2012];

bool match(int pos, int cnt, char x[]) {
    for (int i = 1; i <= cnt; ++i)
        if (x[i] != S[pos + i - 1])
            return 0;
    return 1;
}

int main() {
    gets(S + 1);
    gets(A + 1);
    gets(B + 1);

    int cntA = strlen(A + 1), cntB = strlen(B + 1), cntS = strlen(S + 1);
    for (int i = 1; i <= cntS - cntA + 1; ++i)
        if (match(i, cntA, A))
            matchA[i] = 1;
    for (int i = 1; i <= cntS - cntB + 1; ++i)
        if (match(i, cntB, B))
            matchB[i] = 1;

    for (int i = cntS; i >= 1; --i)
        for (int j = cntS; j >= 1; --j)
            if (S[i] == S[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = 0;

    int res = 0;

    for (int i = 1; i <= cntS; ++i) {
        if (matchA[i] == 0)
            continue;
        int delta = max(cntA - 1, cntB - 1);
        for (int j = 1; j < i; ++j)
            chmax(delta, dp[i][j]);
        for (int j = i + delta; j <= cntS; ++j)
            if (matchB[j - cntB + 1])
                ++res;
    }

    printf("%d", res);
    return 0;
}
