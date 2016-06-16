//Nu am mai rezolvat de multa vreme o problema asa handicapata! Sincere felicitari autorilor!

#include <stdio.h>
#include <vector>

using namespace std;

int N, M, K, E, W;
vector <int> what[260][260];
bool can[1024][1024];
int dp[2][260][260];

void read() {
	int i, j, k;
	
	scanf("%d%d%d%d%d", &N, &M, &K, &W, &E);
	for (i = 1; i <= K; i ++) {
		int x0, y0, r, delay, t;
		scanf("%d%d%d%d%d", &x0, &y0, &r, &delay, &t);
		
		for (j = x0 - r; j <= x0 + r; j ++)
			for (k = y0 - r; k <= y0 + r; k ++)
				if (j > 0 && j <= N)
					if (k > 0 && k <= M)
						what[j][k].push_back(i);
		
		int go = 0, wait = delay;
		for (j = 1; j <= 1001; j ++)
			if (wait) {
				wait --;
				can[i][j] = true;
				if (wait == 0)
					go = t;
			} else {
				go --;
				if (go == 0)
					wait = delay;
			}
	}
}

void solve() {
	int sol, i, j, dir;
	int dx[] = {-1, 1, 0}, dy[] = {0, 0, -1};
		
	dp[1][W][1] = true;
	for (sol = 2; sol <= 1000; sol ++) {
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= M; j ++)
				dp[sol & 1][i][j] = 0;
		
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= M; j ++)
				for (dir = 0; dir <= 2; dir ++) {
					int nx = i + dx[dir], ny = j + dy[dir];
					if (nx > 0 && nx <= N)
						if (ny > 0 && ny <= M)
							if (dp[1 - (sol & 1)][nx][ny]) {
								bool goodTime = true;
								vector <int> :: iterator it;
								for (it = what[i][j].begin(); it != what[i][j].end(); it ++)
									if (can[*it][sol] == false)
										goodTime = false;
									
								if (goodTime) {
									dp[sol & 1][i][j] = true;
									if (i == E && j == M) {
										printf("%d", sol);
										return ;
									}
								}
							}
				}
	}
}

int main() {
	freopen("gheizere.in", "r", stdin);
	freopen("gheizere.out", "w", stdout);
	
	read();
	solve();
	
	return 0;
}
