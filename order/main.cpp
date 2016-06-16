#include <stdio.h>
#define NMAX 30100

int AIB[NMAX];

inline int lsb(int X)
{
	return X & -X;
}

int query(int X)
{
	int free = X;
	
	while (X)
	{
		free = free - AIB[X];
		X = X - lsb(X);
	}

	return free;
}

void update(int X, int N)
{
	while (X <= N)
	{
		AIB[X] ++;
		X = X + lsb(X);
	}
}

int main()
{
	int i, N, pos = 1;
	
	freopen("order.in", "r", stdin);
	freopen("order.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		int step = i + query(pos), tot = query(N);
		
		step = step % tot;
		if (step == 0)
			step = tot;
		
		int st = 1, dr = N, sol;
		while (st <= dr)
		{
			int med = (st + dr) / 2;
			if (query(med) >= step)
			{
				dr = med - 1;
				if (query(med) == step)
					sol = med;
			}
			else
				st = med + 1;
		}
		
		printf("%d ", sol);
		update(sol, N);
		pos = sol;
	}
	
	return 0;
}
