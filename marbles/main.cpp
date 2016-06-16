#include <stdio.h>
#include <algorithm>

using namespace std;

struct ball
{
	int x, cul;
} X[100100];

int cul[100100], x[100100], SP[70][100100];

bool comp(ball A, ball B)
{
	return A.x < B.x;
}

int bs(int val, int N)
{
	int st = 1, dr = N, med;
	
	while (st <= dr)
	{
		med = (st + dr) / 2;
		if (x[med] == val)
			return med;
		if (x[med] < val)
			st = med + 1;
		else
			dr = med - 1;
	}
	
	return st;
}

int main()
{
	int i, j, N, M, maxC = -1;
	
	freopen("marbles.in", "r", stdin);
	freopen("marbles.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &X[i].x, &X[i].cul);
		if (X[i].cul > maxC)
			maxC = X[i].cul;
	}
	
	sort(X + 1, X + N + 1, comp);
	for (i = 1; i <= N; i ++)
		x[i] = X[i].x, cul[i] = X[i].cul;
	
	for (i = 1; i <= maxC; i ++)
		for (j = 1; j <= N; j ++)
		{
			SP[i][j] = SP[i][j - 1];
			if (cul[j] == i)
				SP[i][j] ++;
		}
		
	for (i = 1; i <= M; i ++)
	{
		int tip, x0, y0;
		
		scanf("%d%d%d", &tip, &x0, &y0);
		
		if (tip == 0)
		{
			int pos = bs(x0, N);
			x[pos] = x0 + y0;
		}
		else
		{
			int left = bs(x0, N), right = bs(y0, N), sol = 0;
			
			if (x[right] > y0)
				right --;
			left --;
			
			for (j = 1; j <= maxC; j ++)
				if (SP[j][right] - SP[j][left] > sol)
					sol = SP[j][right] - SP[j][left];
			
			printf("%d\n", sol);
		}
	}
	
	return 0;
}
