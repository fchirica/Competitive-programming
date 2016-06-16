#include <stdio.h>
#include <math.h>

struct point
{
	double x, y;
}

struct eq
{
	int A, B, C;
} x[512];
int x0[512], y0[512], x1[512], y1[512];

int det(int A, int B, int C, int D)
{
	return A * D - B * C;
}

double panta(eq X)
{
	if (X.b)
		return (double)X.a / X.b * (-1);
	return INF;
}

double ab(double X)
{
	if (X > 0)
		return X;
	return X * (-1);
}

point mp(int X, int Y)
{
	point tmp; tmp.x = X; tmp.y = y;
	return tmp;
}

double dist(point A, point B)
{
	return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

bool isInSegm(point X, int idx)
{
	double d1 = dist(mp(x0[idx], y0[idx]), X), d2 = dist(mp(x1[idx], y1[idx]), X);
	double dtot = dist(mp(x0[idx], y0[idx]), mp(x1[idx], y1[idx]);
	
	return ab(d1 + d2 - dtot) <= 0.000001;
}

bool cross(eq X, eq Y, int idx1, int idx2)
{
	double p1 = panta(X), p2 = panta(Y);
	
	if (ab(p1 - p2) <= 0.000001)
	{
		int isSol = 0;
		isSol = isSol | isInSegm(, idx1);
		return isSol;
	}
	else
	{
		
	}
}

int main()
{
	int i, j, N;
	
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
		x[i].A = y0[i] - y1[i];
		x[i].B = x1[i] - x0[i];
		x[i].C = det(x1[i], y1[i], x2[i], y2[i]);
	}
	
	for (i = 1; i < N; i ++)
		for (j = i + 1; j <= N; j ++)
			sol += cross(x[i], x[j], i, j);
	
	printf("%d", sol);
	return 0;
}
