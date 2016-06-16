#include <stdio.h>

using namespace std;

const int EGAL = 0;
const int MIC = 1;
const int MARE = 2;
const int MICMARE = 3;
const int MAXN = 110000;
const int MOD = 1000000007;

long long N, pd[MAXN][4];
char s1[MAXN], s2[MAXN];

int getNr(int poz, int type) {
    int rez = 0;
    if (s1[poz] == '?')
        for (int i = 0; i < 10; ++i) {
            s1[poz] = i + '0';
            rez += getNr(poz, type);
            s1[poz] = '?';
        }
    else if (s2[poz] == '?') {
        for (int i = 0; i < 10; ++i) {
            s2[poz] = i + '0';
            rez += getNr(poz, type);
            s2[poz] = '?';
        }
    }
    else {
        if (s1[poz] > s2[poz] && type == MARE)
            rez += 1;
        if (s1[poz] == s2[poz] && type == EGAL)
            rez += 1;
        if (s1[poz] < s2[poz] && type == MIC)
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

    pd[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        long long nEGAL = getNr(i, EGAL);
        long long nMIC = getNr(i, MIC);
        long long nMARE = getNr(i, MARE);
        pd[i][EGAL] = (pd[i - 1][EGAL] * nEGAL) % MOD;
        pd[i][MIC] = (((pd[i - 1][EGAL] * nMIC) % MOD) + pd[i - 1][MIC] * (nEGAL + nMIC)) % MOD;
        pd[i][MARE] = (((pd[i - 1][EGAL] * nMARE) % MOD) + pd[i - 1][MARE] * (nEGAL + nMARE)) % MOD;
        pd[i][MICMARE] = (((pd[i - 1][MICMARE] * (nEGAL + nMIC + nMARE)) % MOD) + pd[i - 1][MARE] * nMIC + pd[i - 1][MIC] * nMARE) % MOD;
    }

    printf("%d", pd[N][MICMARE]);
    return 0;
}

