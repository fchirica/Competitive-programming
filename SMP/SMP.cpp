#include <stdio.h>

int M[512][512], W[512][512], L[512], R[512];

void pairup(int man) {
	++L[man];
	int woman = M[man][L[man]];
	if (R[woman] == 0) {
		L[man] = woman; R[woman] = man;
		return ;
	}
	int husband = R[woman];
	if (W[woman][man] < W[woman][husband]) {
		L[man] = woman; R[woman] = man;
		pairup(husband);
	}
	else
		pairup(man);
}

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int N;
		scanf("%d", &N);
		int i, j;
		for (i = 1; i <= N; ++i) {
			int who, who2;
			scanf("%d", &who);
			for (j = 1; j <= N; ++j) {
				scanf("%d", &who2);
				W[who][who2] = j;
			}
		}
		for (i = 1; i <= N; ++i) {
			int who, who2;
			scanf("%d", &who);
			for (j = 1; j <= N; ++j) {
				scanf("%d", &who2);
				M[who][j] = who2;
			}
		}
		
		for (i = 1; i <= N; ++i)
			L[i] = R[i] = 0;
		for (i = 1; i <= N; ++i)
			pairup(i);
		for (i = 1; i <= N; ++i) 
			printf("%d %d\n", i, L[i]);
	}
	
	return 0;
}
