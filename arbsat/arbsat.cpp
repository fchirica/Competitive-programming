#include <vector>
#include <stdio.h>
#define NMAX 5000
#define MOD 666013

using namespace std;

struct point
{
	int x, y;
} x[NMAX];

vector <point> H[MOD];
vector <point> sol;

bool Exist (int x0, int y0)
{
	int where = (x0 * 100 + y0) % MOD;
	point now;
	vector <point> :: iterator it;

	for (it = H[where].begin (); it != H[where].end (); it ++)
	{
		now = *it;
		if (now.x == x0 && now.y == y0)
			return 1;
	}
	
	return 0;
}

void Add (int x0, int y0)
{
	int where = (x0 * 100 + y0) % MOD;
	
	point now; now.x = x0; now.y = y0;
	H[where].push_back (now);
}

inline int min2 (int x0, int y0)
{
	return x0 < y0 ? x0 : y0;
}

inline int max2 (int x0, int y0)
{
	return x0 > y0 ? x0 : y0;
}


int main ()
{
	int i, j, N, M, nrSol = 0;
	point now;
	
	freopen ("arbsat2.in", "r", stdin);
	freopen ("arbsat2.out", "w", stdout);
	
	scanf ("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf ("%d%d", &x[i].x, &x[i].y);
		Add (x[i].x, x[i].y);
	}
	
	for (i = 1; i <= N; i ++)
		for (j = i + 1; j <= N; j ++)
		{
			int xm = min2 (x[i].x, x[j].x), ym = min2 (x[i].y, x[j].y);
			if(x[i].x == x[j].x || x[i].y == x[j].y)
				continue;
			if (!Exist (xm, ym))
			{
				Add (xm, ym);
				now.x = xm; now.y = ym;
				sol.push_back (now);
				nrSol ++;
				continue;
			}
			xm = max2 (x[i].x, x[j].x), ym = min2 (x[i].y, x[j].y);
			if (!Exist (xm, ym))
			{
				Add (xm, ym);
				now.x = xm; now.y = ym;
				sol.push_back (now);
				nrSol ++;
				continue;
			}
			xm = min2 (x[i].x, x[j].x), ym = max2 (x[i].y, x[j].y);
			if (!Exist (xm, ym))
			{
				Add (xm, ym);
				now.x = xm; now.y = ym;
				sol.push_back (now);
				nrSol ++;
				continue;
			}
			xm = max2 (x[i].x, x[j].x), ym = max2 (x[i].y, x[j].y);
			if (!Exist (xm, ym))
			{
				Add (xm, ym);
				now.x = xm; now.y = ym;
				sol.push_back (now);
				nrSol ++;
				continue;
			}
		}
		
	printf ("%d\n", nrSol);
	for (i = 0; i < nrSol; i ++)
	{
		now = sol[i];
		printf ("%d %d\n", now.x, now.y);
	}
	
	return 0;
}

