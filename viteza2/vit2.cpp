#include <stdio.h>
#include <vector>

using namespace std;

struct vertex
{
	int x, cost, last;
};

vector <vertex> G[1 << 10];

inline vertex mv (int x, int y, int last)
{
	vertex aux; aux.x = x; aux.cost = y; aux.last = last;
	return aux;
}

int sol[1 << 10][1 << 10];
vertex Q[5100];

int main ()
{
	int x, i, j, y, N, M, p = 1, u = 0, cost;
	vector <vertex> :: iterator it;
	vertex now;
	
	freopen ("viteza2.in", "r", stdin);
	freopen ("viteza2.out", "w", stdout);
	
	scanf ("%d%d", &N, &M);
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
		{
			sol[i][j] = 1 << 30;
			if (i == j)
				sol[i][j] = 0;
		}
		
	for (i = 1; i <= M; i ++)
	{
		scanf ("%d%d%d", &x, &y, &cost);
		G[x].push_back (mv (y, cost, 0));
		G[y].push_back (mv (x, cost, 0));
	}
	
	for (i = 1; i <= N; i ++)
	{
		p = 1; u = 0;
		Q[++ u] = mv (i, 0, 0);
		while (p <= u)
		{
			for (it = G[Q[p].x].begin (); it != G[Q[p].x].end (); it ++)
			{
				now = *it;
				if (Q[p].cost + now.cost < sol[i][now.x])
					if (now.cost > Q[p].last)
					{
						Q[++ u] = mv (now.x, Q[p].cost + now.cost, now.cost);
						sol[i][now.x] = Q[p].cost + now.cost;
					}
						
			}
			p ++;
		}
	}

	for (i = 1; i <= N; i ++, printf ("\n"))
		for (j = 1; j <= N; j ++)
			printf ("%d ", sol[i][j] == (1 << 30) ? -1 : sol[i][j]);
	
	return 0;
}
