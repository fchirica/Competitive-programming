#include <stdio.h>
#include <string.h>
#define MOD 1000000000

int x[20100], dp[12][20100], Fenwick[20100];

inline int lsb(int X) {
	return X & -X;
}

inline void add(int &A, int B) {
	A += B;
	while (A >= MOD)
		A -= MOD;
}

inline int query(int X) {
	int ans = 0;
	for (; X > 0; X = X - lsb(X))
		add(ans, Fenwick[X]);
	return ans;
}

void update(int X, int amount, int N) {
	for (; X <= N; X = X + lsb(X))
		add(Fenwick[X], amount);
}

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	int i, j, N, K;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	
	for (i = 1; i <= N; i ++)
		dp[1][i] = 1;
	for (i = 2; i <= K; i ++) {
		memset(Fenwick, 0, sizeof(Fenwick));
		for (j = 1; j <= N; j ++) {
			dp[i][x[j]] = query(N) - query(x[j]);
			while (dp[i][x[j]] < 0)
				dp[i][x[j]] += MOD;
			update(x[j], dp[i - 1][x[j]], N);
		}
	}
	
	int sol = 0;
	for (i = 1; i <= N; i ++)
		add(sol, dp[K][i]);
	
	printf("%d", sol);
	return 0;
}
