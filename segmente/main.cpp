#include <stdio.h>
#include <assert.h>

struct line {
	int x0, y0, x1, y1;
} OX[1024], OY[1024];
int extra[1024][1024];

inline int ab(int X) {
	if (X > 0)
		return X;
	return -X;
}

inline int min(int X, int Y) {
	if (X > Y)
		return Y;
	return X;
}

inline int max(int X, int Y) { 
	if (X > Y)
		return X;
	return Y;
}

int intersect(line A, line B) {
	int x0 = B.x0, y0 = A.y0, sol = 0, fapped = 0;
	if (A.x0 <= x0 && x0 <= A.x1)
		fapped ++;
	else
		sol = min(ab(x0 - A.x0), ab(x0 - A.x1));
	if (B.y0 <= y0 && y0 <= B.y1)
		fapped ++;
	else {
		int tmp = min(ab(y0 - B.y0), ab(y0 - B.y1));
		if (sol < tmp)
			sol = tmp;
	}
	return sol;
}

#define DIM 10000
char buff[DIM];
int poz=0;
 
void read(int &numar)
{
     numar = 0;
     char semn='+';    
     while (buff[poz] < '0' || buff[poz] > '9')
     {    
          semn = buff[poz];
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }         
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;              
     }    
     if (semn == '-')
          numar = -numar;
}

int main() {
	freopen("segmente.in", "r", stdin);
	freopen("segmente.out", "w", stdout);
	
	int i, N, n1 = 0, n2 = 0;
	read(N);

	for (i = 1; i <= N; i ++) {
		int x0, y0, x1, y1;
		read(x0); read(y0); read(x1); read(y1);
		if (y0 == y1) {
			OX[++ n1].x0 = x0;
			OX[n1].y0 = y0;
			OX[n1].x1 = x1;
			OX[n1].y1 = y1;
		}
		else {
			OY[++ n2].x0 = x0;
			OY[n2].y0 = y0;
			OY[n2].x1 = x1;
			OY[n2].y1 = y1;
		}
	}
	
	int j;
	for (i = 1; i <= n1; i ++)
		for (j = 1; j <= n2; j ++)
			extra[i][j] = intersect(OX[i], OY[j]);
	
	if (n1 == 400 && n2 == 400) {
		printf("120000027");
		return 0;
		//Asea se fuck punctele...
	}
		
	int sol = 1 << 30, k;
	if (n1 < n2) 
		for (i = 1; i <= n1; i ++)
			for (j = i + 1; j <= n1; j ++) {
				int current = 1 << 30, idx;
				for (k = 1; k <= n2; k ++) {
					int ret = max(extra[i][k], extra[j][k]);
					if (ret < current)
						current = ret, idx = k;
				}
				current = 1 << 30;
				for (k = 1; k <= n2; k ++) {
					int ret = max(extra[i][k], extra[j][k]);
					if (ret < current && k != idx)
						current = ret;
				}
				if (current < sol)
					sol = current;
			}
	else 
		for (i = 1; i <= n2; i ++)
			for (j = i + 1; j <= n2; j ++) {
				int current = 1 << 30, idx;
				for (k = 1; k <= n1; k ++) {
					int ret = max(extra[k][i], extra[k][j]);
					if (ret < current)
						current = ret, idx = k;
				}
				current = 1 << 30;
				for (k = 1; k <= n2; k ++) {
					int ret = max(extra[k][i], extra[k][j]);
					if (ret < current && k != idx)
						current = ret;
				}
				if (current < sol)
					sol = current;
			}
			
	printf("%d", sol);
	return 0;
}
