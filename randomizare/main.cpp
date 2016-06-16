#include <stdio.h>
#include <string.h>

int x[200200], perm[200200], vis[200200], cycle[200200], lenCycle[200200], seenLen[200200];
int AmodLen[200200], factM[1000], pwM[1000], resPerm[200200], usedLen[200200], maxPower[200200];
int factModLen[1000][1000], which[200200];

int fastPow(int A, int B, int M) {
    if (B == 0)
        return 1;

    int res = fastPow(A, B / 2, M);
    res = (long long) res * res % M;
    if (B % 2)
        res = (long long) res * A % M;
    return res;
}

int calcMmodLen(int M) {
    int res = 1;
    for (int i = 1; i <= factM[0]; ++i) {
        res = (res * (long long) factModLen[i][which[M]]) % M;
        if (res == 0)
            return 0;
    }
    return res;
}

void update(int pos) {
    for (int i = 1; i <= lenCycle[0]; ++i)
        factModLen[pos][i] = fastPow(factM[pos], pwM[pos], lenCycle[i]);
}

int main() {
    freopen("randomizare.in", "r", stdin);
    freopen("randomizare.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &perm[i]);

    int cntCycle = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            int len = 0, cur = i;
            do {
                ++len;
                vis[cur] = 1;
                cur = perm[cur];
            } while (!vis[cur]);

            if (seenLen[len])
                continue;
            seenLen[len] = 1;
            lenCycle[++cntCycle] = len;
            which[len] = cntCycle;
        }

    lenCycle[0] = cntCycle;
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            int len = 0, lungimeCicluCurent = 0;
            int cur = i;
            do {
                ++len;
                vis[cur] = 1;
                cycle[lungimeCicluCurent++] = cur;
                cur = perm[cur];
            } while (!vis[cur]);

            int A = AmodLen[len];
            int M = calcMmodLen(len);

            if (usedLen[len]) {
                for (int j = 0; j < lungimeCicluCurent; ++j)
                    resPerm[cycle[j]] = cycle[(j + A) % lungimeCicluCurent];
                continue;
            }

            usedLen[len] = 1;

            int k = 0, bestA = A, steps = 0;
            cur = A;
            while (vis[cycle[cur]] != 2) {
                if (x[cycle[bestA]] > x[cycle[cur]]) {
                    bestA = cur;
                    k = steps;
                }
                ++steps;
                vis[cycle[cur]] = 2;
                cur += M;
                if (cur >= lungimeCicluCurent)
                    cur -= lungimeCicluCurent;
            }

            for (int j = 0; j < lungimeCicluCurent; ++j)
                resPerm[cycle[j]] = cycle[(j + bestA) % lungimeCicluCurent];
            for (int j = 1; j <= cntCycle; ++j)
                AmodLen[lenCycle[j]] = (AmodLen[lenCycle[j]] + (long long) k * calcMmodLen(lenCycle[j])) % lenCycle[j];

            for (int factor = 2; factor * factor <= len; ++factor) {
                int pw = 0;
                while (len % factor == 0) {
                    ++pw;
                    len /= factor;
                }
                if (pw) {
                    if (maxPower[factor] == 0)
                        factM[++factM[0]] = factor;
                    if (pw > maxPower[factor])
                        maxPower[factor] = pw;
                }
            }

            if (len > 1) {
                if (maxPower[len] == 0)
                    factM[++factM[0]] = len;
                if (1 > maxPower[len])
                    maxPower[len] = 1;
            }

            for (int j = 1; j <= factM[0]; ++j)
                if (maxPower[factM[j]] != pwM[j]) {
                    pwM[j] = maxPower[factM[j]];
                    update(j);
                }
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", x[resPerm[i]]);

    return 0;
}
