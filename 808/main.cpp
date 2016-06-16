#include <stdio.h>

int dx[10100], dy[10100];
int x[1024][1024];

void baga(int x0, int y0, int idx)
{
	dx[idx] = x0; dy[idx] = y0; x[x0][y0] = idx;
}

void precalc()
{
	int i, x0 = 500, y0 = 500, step = 0;
	
	baga(x0, y0, 1);
	for (i = 2; i <= 10000; i ++)
	{
		if (step == 0)
		{
			x0 ++; baga(x0, y0, i);
			if (x[x0][y0 - 1] == 0)
				step ++;
			continue;
		}
		if (step == 1)
		{
			if (x[x0 - 1][y0 - 1])
			{
				y0 --; baga(x0, y0, i);
				continue;
			}
			step ++;
		}
		if (step == 2)
		{
			x0 --; y0 --; baga(x0, y0, i);
			if (x[x0 - 1][y0] == 0)
				step ++;
			continue;
		}
		if (step == 3)
		{
			x0 --; baga(x0, y0, i);
			if (x[x0][y0 + 1] == 0)
				step ++;
			continue;
		}
		if (step == 4)
		{
			if (x[x0 + 1][y0 + 1])
			{
				y0 ++; baga(x0, y0, i);
				continue;
			}
			step ++;
		}
		if (step == 5)
		{
			x0 ++; y0 ++; baga(x0, y0, i);
			if (x[x0 + 1][y0] == 0)
				step = 0;
			continue;
		}
	}
}

inline int ab(int X)
{
	if (X > 0)
		return X;
	return X * (-1);
}

int main()
{
	precalc();
	
	int x0, y0, A, B;
	while (1)
	{
		scanf("%d%d", &x0, &y0); A = x0; B = y0;
		if (x0 == 0 && y0 == 0)
			return 0;
		int diff1 = ab(dx[x0] - dx[y0]), diff2 = ab(dy[x0] - dy[y0]);
		if (dx[x0] > dx[y0])
		{
			int aux = x0; x0 = y0; y0 = aux;
		}
		int sol;
		if (dy[x0] < dy[y0])
		{
			sol = diff1; 
			if (diff2 > diff1)
				sol = diff2;
		}
		else
			sol = diff1 + diff2;
		printf("The distance between cells %d and %d is %d.\n", A, B, sol);
	}
	
	return 0;
}
