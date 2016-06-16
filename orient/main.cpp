#include <stdio.h>
#include <vector>
#define INF 1 << 30

using namespace std;

struct par
{
	int y, cost;
}; 

vector <par> G[1024];
int dist[1024], Q[100000];

par mp(int x0, int y0)
{
	par aux; aux.y = x0; aux.cost = y0;
	return aux;
}

int main()
{
	int i, j, N, M;
	vector <par> :: iterator it, it2;
	
	freopen("orient.in", "r", stdin);
	freopen("orient.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int x0, y0, c;
		
		scanf("%d%d%d", &x0, &y0, &c);
		G[x0].push_back(mp(y0, 0));
		G[y0].push_back(mp(x0, c));
	}
	
	int sol = 1 << 30;
	
	for (i = 1; i <= N; i ++)
		for (it = G[i].begin(); it != G[i].end(); it ++)
		{
			int X = i, Y = it -> y, now = it -> cost;
			
			for (j = 1; j <= N; j ++)
				dist[j] = INF;
			dist[Y] = 0;
			
			int p = 1, u = 0;
			for (it2 = G[Y].begin(); it2 != G[Y].end(); it2 ++)
				if (it2 -> y != X)
				{
					dist[it2 -> y] = it2 -> cost;
					Q[++ u] = it2 -> y;
				}
			
			//Baga dijkstra daca nu intra in timp.
			while (p <= u)
			{
				int now = Q[p];
				for (it2 = G[now].begin(); it2 != G[now].end(); it2 ++)
					if (dist[now] + it2 -> cost < dist[it2 -> y])
						if (dist[now] + it2 -> cost < sol)
						{
							dist[it2 -> y] = dist[now] + it2 -> cost;
							Q[++ u] = it2 -> y;
						}
				p ++;
			}
			
			now += dist[X];
			if (now < sol)
				sol = now; 
		}
	
	printf("%d", sol);
	return 0;
}
