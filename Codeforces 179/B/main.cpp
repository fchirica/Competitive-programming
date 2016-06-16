#include <stdio.h>
#define MOD 1000000007

using namespace std;

long long N, dp[4][100100];
char s1[100100], s2[100100];

int solve(int poz, int type) {
    int rez = 0;
    if (s1[poz] == '?')
        for (int i = 0; i < 10; ++i) {
            s1[poz] = i + '0';
            rez += solve(poz, type);
            s1[poz] = '?';
        }
    else
    if (s2[poz] == '?') {
        for (int i = 0; i < 10; ++i) {
            s2[poz] = i + '0';
            rez += solve(poz, type);
            s2[poz] = '?';
        }
    }
    else {
        if (s1[poz] > s2[poz] && type == 2)
            rez += 1;
        if (s1[poz] == s2[poz] && type == 0)
            rez += 1;
        if (s1[poz] < s2[poz] && type == 1)
            rez += 1;
    }
    return rez;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d\n", &N);
    gets(s1 + 1);
    gets(s2 + 1);

    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        long long rq = solve(i, 0);
        long long low = solve(i, 1);
        long long upp = solve(i, 2);
        dp[0][i] = (dp[0][i - 1] * rq) % MOD;
        dp[1][i] = (((dp[0][i - 1] * low) % MOD) + dp[1][i - 1] * (rq + low)) % MOD;
        dp[2][i] = (((dp[0][i - 1] * upp) % MOD) + dp[2][i - 1] * (rq + upp)) % MOD;
        dp[3][i] = (((dp[3][i - 1] * (rq + low + upp)) % MOD) + dp[2][i - 1] * low + dp[1][i - 1] * upp) % MOD;
    }

    printf("%I64d", dp[3][N]);
    return 0;
}
