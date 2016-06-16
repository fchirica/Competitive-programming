#include <stdio.h>
#include <algorithm>

using namespace std;

int x[50100], y[50100];
int sx[] = {1, -1, -1, 1}, sy[] = {1, 1, -1, -1};

inline int sgn(int X)
{
	if (X > 0)
		return 1;
	return -1;
}

struct point
{
	int x, y;
} P[50100];

inline bool comp(point A, point B)
{
	return A.x < B.x;
}

int solve(int N)
{
	int now[50100], i;
	
	now[0] = 0;
	for (i = 1; i <= N; i ++)
	{
		int st = 1, dr = now[0], med, last = -1;
		
		while (st <= dr)
		{
			med = (st + dr) / 2;
			if (now[med] <= P[i].y)
				dr = med - 1, last = med;
			else
				st = med + 1;
		}
		
		if (last != -1)
			now[last] = P[i].y;
		else
			now[++ now[0]] = P[i].y;
	}
	
	return now[0];
}

int main()
{
	int i, quad, N, x0, y0;
	
	freopen("pachete.in", "r", stdin);
	freopen("pachete.out", "w", stdout);
	
	scanf("%d%d%d", &N, &x0, &y0);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i] = x[i] - x0; y[i] = y[i] - y0;
	}
	
	int sol = 0, n;
	for (quad = 0; quad < 4; quad ++)
	{
		n = 0;
		for (i = 1; i <= N; i ++)
			if (sgn(x[i]) == sx[quad] && sgn(y[i]) == sy[quad])
			{
				P[++ n].x = x[i];
				P[n].y = y[i];
				if (x[i] < 0)
					P[n].x = P[n].x * (-1);
				if (y[i] < 0)
					P[n].y = P[n].y * (-1);
			}
			
		sort(P + 1, P + n + 1, comp);
		sol += solve(n);
	}
	
	printf("%d", sol);
	return 0;
}
