#include <stdio.h>

int x[100100];
int cnt[1000100], VMAX, median;
long long sum[1000100], stot;

inline int lsb(int X) {
	return X & -X;
}

void updateSum(int X, int how) {
	for (; X <= VMAX; X = X + lsb(X))
		sum[X] += how;
}

void updatePos(int X, int how) {
	for (; X <= VMAX; X = X + lsb(X))
		cnt[X] += how;
}

int queryPos(int X) {
	int tot = 0;
	for (; X > 0; X = X - lsb(X))
		tot += cnt[X];
	return tot;
}

long long querySum(int X) {
	long long tot = 0;
	for (; X > 0; X = X - lsb(X))
		tot += sum[X];
	return tot;
}

long long calc(int K) {
	long long need = (K + 1) / 2, st = 1, dr = VMAX, med, sol;
	while (st <= dr) {
		med = (st + dr) / 2;
		int ret = queryPos(med);
		if (ret >= need) {
			//if (ret == need)
				sol = med;
			dr = med - 1;
		}
		else
			st = med + 1;
	}
	median = st;
	need = queryPos(median);
	long long pula = 1LL * need * median - querySum(median);
	pula += 1LL * (stot - querySum(median)) - (K - need) * median;
	return pula;
}

int main() {
	//..freopen("klo.in", "r", stdin);
	//freopen("klo.out", "w", stdout);
	
	int i, N, K;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; ++i) {
		scanf("%d", &x[i]); ++x[i];
		if (x[i] > VMAX)
			VMAX = x[i];
	}
	
	for (i = 1; i <= K; ++i) {
		updatePos(x[i], 1);
		updateSum(x[i], x[i]);
		stot += x[i];
	}
	long long smin = calc(K), idx = 1, med = median; 
	for (i = 2; i <= N - K + 1; ++i) {
		updatePos(x[i - 1], -1);
		updateSum(x[i - 1], -x[i - 1]);
		updatePos(x[i + K - 1], 1);
		updateSum(x[i + K - 1], x[i + K - 1]);
		stot = stot - x[i - 1] + x[i + K - 1];
		long long ret = calc(K);
		if (ret < smin)
			smin = ret, idx = i, med = median;
	}
	
	printf("%I64d\n", smin);
	for (i = idx; i <= idx + K - 1; ++i)
		x[i] = med;
	for (i = 1; i <= N; ++i)
		printf("%d\n", x[i] - 1);
	return 0;
}
