#include <stdio.h>
#include <string.h>

int A[512], B[512], C[512], F[512], cnt[512];
int dp[2][512][512];

const int mod = 666013;

inline int lsb(int X) {
    return X & -X;
}

void add(int &A, int B) {
    A += B;
    while (A >= mod)
        A -= mod;
}

int query(int nod) {
    int ans = 0;
    for (++nod; nod > 0; nod -= lsb(nod))
        add(ans, F[nod]);
    return ans;
}

void update(int nod, int val) {
    for (++nod; nod < 512; nod += lsb(nod))
        add(F[nod], val);
}

int main() {
    freopen("pedefe.in", "r", stdin);
    freopen("pedefe.out", "w", stdout);

    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);
    for (int i = 1; i <= K; ++i)
        scanf("%d", &C[i]);

    dp[0][0][0] = 1;
    for (int k = 0; k <= K; ++k) {
        memset(cnt, 0, sizeof(cnt));
        int cur = k % 2;
        for (int i = 1; i <= N; ++i) {
            memset(F, 0, sizeof(F));
            if (k == 0)
                update(0, 1);
            for (int j = 1; j <= M; ++j) {
                dp[1 - cur][i][j] = 0;
                if (A[i] == B[j]) {
                    int before = query(A[i]);
                    if (k < K && C[k + 1] == A[i])
                        add(dp[1 - cur][i][j], before);
                    else
                        add(dp[cur][i][j], before);
                } else
                    dp[cur][i][j] = 0;
                update(B[j], cnt[j]);
                add(cnt[j], dp[cur][i][j]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            add(res, dp[K & 1][i][j]);
    printf("%d", res);
    return 0;
}

