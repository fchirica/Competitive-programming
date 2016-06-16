#include <stdio.h>
#include <algorithm>

using namespace std;

int x[100100], diff[100100];

inline int comp(int A, int B) {
	return A > B;
}

int main() {
	int i, N, M, K;
	
	freopen("metrouri.in", "r", stdin);
	freopen("metrouri.out", "w", stdout);
	
	scanf("%d%d%d", &M, &N, &K);
	for (i = 1; i <= N; i ++) {
		int S, T;
		scanf("%d%d", &S, &T);
		x[i] = T - S;
	}
	
	int sol = 0;
	if (K >= N) {
		printf("0");
		return 0;
	}
	
	sort(x + 1, x + N + 1);
	for (i = 2; i <= N; i ++) {
		diff[i - 1] = x[i] - x[i - 1];
		sol += diff[i - 1];
	}
	sort(diff + 1, diff + N, comp);
	
	for (i = 1; i < K; i ++)
		sol = sol - diff[i];
	
	printf("%d", sol);
	return 0;
}
