#include <stdio.h>

int x0[512], y0[512], x1[512], y1[512], OX[1024], OY[1024], x[1024], y[1024];
int up[1024][1024], right[1024][1024];

void norm(int &X, int now[])
{
	int st = 1, dr = now[0], med;
	
	while (st <= dr)
	{
		med = (st + dr) / 2;
		if (X == now[med])
		{
			X = med;
			return ;
		}
		if (X < now[med])
			dr = med - 1;
		else
			st = med + 1;
	}
}

void swap(int &X, int &Y)
{
	int aux = X;
	X = Y;
	Y = aux;
}

void bagaOX(int x0, int y0, int y1)
{
	int i;
	
	for (i = y0; i < y1; i ++)
		up[x0][i] = 1;
}

void bagaOY(int x0, int x1, int y0)
{
	int i;
	
	for (i = x0; i < x1; i ++)
		right[i][y0] = 1;
}

int jos(int x0, int y0)
{
	x0 ++;
	if (x0 > x[0])
		return 0;
	if (up[x0 - 1][y0] == 0)
		return 1;
	return 0;
}

int sus(int x0, int y0)
{
	if (x0 == 0)
		return 0;
	if (up[x0 - 1][y0] == 0)
		return 1;
	return 0;
}

int stanga(int x0, int y0)
{
	if (y0 == 0)
		return 0;
	if (
}

int main()
{
	int N, M, N1 = 0, N2 = 0;
	
	freopen("crazy.in", "r", stdin);
	freopen("crazy.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
		OX[++ N1] = x0[i]; OX[++ N1] = x1[i];
		OY[++ N2] = y0[i]; OY[++ N2] = y1[i];
	}
	
	sort(OX + 1, OX + N1 + 1);
	sort(OY + 1, OY + N2 + 1);
		
	OX[0] = OX[1] - 1; OY[0] = OY[1] - 1;
	for (i = 1; i <= N1; i ++)
		if (OX[i] != OX[i - 1])
			y[++ y[0]] = OX[i];
	for (i = 1; i <= N2; i ++)
		if (OY[i] != OY[i - 1])
			x[++ x[0]] = OY[i];
	
	x[++ x[0]] = y[++ y[0]] = 1 << 30;
	for (i = 1; i <= N; i ++)
	{
		norm(x0[i], y); norm(y0[i], x);
		norm(x1[i], y); norm(y1[i], x);
	}
	
	for (i = 1; i <= N; i ++)
	{
		int xnow = y0[i], ynow = x0[i];
		int x2 = y1[i], y2 = x1[i];
		
		if (xnow == x2)
		{
			if (ynow > y1)
				swap(ynow, y1);
			bagaOX(xnow, ynow, y1);
		}
		if (ynow == y2)
		{
			if (xnow > x1)
				swap(xnow, x1);
			bagaOY(xnow, x1, ynow);
		}
	}
	
	