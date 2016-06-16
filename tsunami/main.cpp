#include <stdio.h>

int x[1024][1024];
struct pos {
	int x, y;
}	Q[1024 * 1024];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	freopen("tsunami.in", "r", stdin);
	freopen("tsunami.out", "w", stdout);
	
	int i, j, N, M, lim;
	scanf("%d%d%d", &N, &M, &lim);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			scanf("%d", &x[i][j]);
	
	int p = 1, u = 0;
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++) {
			if (x[i][j] == 0)
				Q[++ u].x = i, Q[u].y = j;
			if (x[i][j] >= lim)
				x[i][j] = 0;
		}
	
	int sol = 0;
	while (p <= u) {
		for (int d = 0; d <= 3; d ++) {
			int nx = Q[p].x + dx[d], ny = Q[p].y + dy[d];
			if (x[nx][ny]) {
				++ sol;
				x[nx][ny] = 0;
				Q[++ u].x = nx; Q[u].y = ny;
			}
		}
		p ++;
	}
	
	printf("%d", sol);
	return 0;
}
