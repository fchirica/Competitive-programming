#include <stdio.h>

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int x[200][200], Qx[200 * 200], Qy[200 * 200];

int main() {
	freopen("alee.in", "r", stdin);
	freopen("alee.out", "w", stdout);
	
	int i, j, N, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			x[i][j] = -1;
	for (i = 1; i <= M; i ++) {
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		x[x0][y0] = 0;
	}
	int sx, sy, tx, ty;
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	
	int p = 1, u = 0;
	x[sx][sy] = 1; 
	Qx[++ u] = sx; Qy[u] = sy;
	
	while (p <= u) {
		int dir;
		for (dir = 0; dir <= 3; dir ++) {
			int nx = Qx[p] + dx[dir], ny = Qy[p] + dy[dir];
			if (x[nx][ny] == -1) {
				x[nx][ny] = x[Qx[p]][Qy[p]] + 1;
				Qx[++ u] = nx; Qy[u] = ny;
			}
		}
		p ++;
	}
	
	printf("%d", x[tx][ty]);
	return 0;
}
