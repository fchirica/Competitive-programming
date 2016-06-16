//fucker

#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char tmp[201];
int N, K, full[201];

const int MOD = 666013;

string intersect(string A, string B) {
    string res;
    for (int i = 0; i < A.size(); ++i)
        if (A[i] == '?')
            res += B[i];
        else {
            if (B[i] != '?' && A[i] != B[i])
                return "";
            res += A[i];
        }
    return res;
}

int solve(string X) {
    bool isFull = true;
    for (int i = 0; i < X.size(); ++i)
        if (X[i] != '?')
            isFull = false;
    if (isFull)
        return full[X.size()];
    if (X.size() < 2)
        return 1;

    if (X.size() % 2) {
        string newX;
        for (int i = 0; i < X.size(); ++i)
            if (i != X.size() / 2)
                newX += X[i];
        if (X[X.size() / 2] == '?')
            return K * solve(newX) % MOD;
        return solve(newX);
    }

    string newX, half, other;
    for (int i = 0; i < X.size(); ++i)
        if (i != X.size() / 2)
            newX += X[i];
    for (int i = 0; i < X.size() / 2; ++i)
        half += X[i];
    for (int i = X.size() / 2; i < X.size(); ++i)
        other += X[i];
    if (X[X.size() / 2] == '?')
        return (K * solve(newX) - solve(intersect(half, other)) + MOD) % MOD;
    else
        return (solve(newX) - solve(intersect(half, other)) + MOD) % MOD;
}

int main() {
    freopen("hacker.in", "r", stdin);
    freopen("hacker.out", "w", stdout);

    scanf("%d%d\n", &N, &K);
    full[1] = K;
    for (int i = 2; i <= N; ++i)
        if (i % 2 == 0)
            full[i] = (full[i - 1] * K - full[i / 2] + MOD) % MOD;
        else
            full[i] = K * full[i - 1] % MOD;
    gets(tmp);
    printf("%d", solve(string(tmp)));

    return 0;
}
