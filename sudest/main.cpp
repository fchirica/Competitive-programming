#include <stdio.h>

int moves[110][110], sol[110][110];
int a[110][110], x[300];

inline void chmax(int &A, int B) {
	if (A < B)
		A = B;
}

void recon(int x0, int y0) {
	if (x0 != 1 || y0 != 1) {
		int back = x[moves[x0][y0]];
		if (x0 - back > 0 && sol[x0 - back][y0] + a[x0][y0] == sol[x0][y0])
			recon(x0 - back, y0);
		else
			recon(x0, y0 - back);
	}
	
	printf("%d %d\n", x0, y0);
}

int main() {
	freopen("sudest.in", "r", stdin);
	freopen("sudest.out", "w", stdout);
	
	int i, j, N, K;
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++) 
			scanf("%d", &a[i][j]);
	scanf("%d", &K);
	for (i = 1; i <= K; i ++)
		scanf("%d", &x[i]);

	sol[1][1] = a[1][1] + 1;
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			if (sol[i][j]) {
				int need = moves[i][j], delta = x[need + 1];
				if (need == K)
					continue;
				if (i + delta <= N) {
					moves[i + delta][j] = moves[i][j] + 1;
					chmax(sol[i + delta][j], sol[i][j] + a[i + delta][j]);
				}
				if (j + delta <= N) {
					moves[i][j + delta] = moves[i][j] + 1;
					chmax(sol[i][j + delta], sol[i][j] + a[i][j + delta]);
				}
			}
	
	printf("%d\n", sol[N][N] - 1);
	recon(N, N);
	return 0;
}
