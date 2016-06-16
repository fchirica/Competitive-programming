#include <stdio.h>

int x[1024][1024], dp[1024][1024], lin[1024][1024], col[1024][1024];

const int DIM = 8192;
char buff[DIM];
int poz = 0;
void read(int &numar) {
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')     
        if (++ poz == DIM) 
            fread(buff, 1, DIM, stdin), poz = 0;
    while ('0' <= buff[poz] && buff[poz] <= '9') {
        numar = numar * 10 + buff[poz] - '0';
        if (++ poz == DIM) 
            fread(buff, 1, DIM, stdin), poz = 0;               
    }     
}

int main() {
	freopen("acces.in", "r", stdin);
	freopen("acces.out", "w", stdout);

	int i, j, N, M;
	read(N); read(M);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			read(x[i][j]);
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++) 
			if (x[i][j] == 0) { 
				lin[i][j] = j;
				col[i][j] = i;
			}
			else {
				lin[i][j] = lin[i][j - 1];
				col[i][j] = col[i - 1][j];
			}
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			if (x[i][j] == 0) {
				int sum = x[i - 1][j] + x[i][j - 1];
				if (sum == 2)
					dp[i][j] = 1;
				else if (sum == 1) {
					if (x[i][j - 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else
						dp[i][j] = dp[i - 1][j] + 1;
				}
				else {
					if (x[i - 1][j - 1] == 0)
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
					else {
						int x0 = col[i - 1][j - 1], y0 = lin[i - 1][j - 1];
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[x0][y0] + 1;
					}
				}
			}
	
	int Q;
	read(Q);
	while (Q --) {
		int x0, y0;
		read(x0); read(y0);
		printf("%d\n", dp[x0][y0]);
	}

	return 0;
}
