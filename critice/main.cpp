#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 1024

using namespace std;

vector <int> G[NMAX];
int C[NMAX][NMAX], F[NMAX][NMAX], ord[NMAX][NMAX];
int father[NMAX], reach[NMAX], sol[10100], vis2[NMAX], memo[NMAX];

bool BFS(int N)
{
	int inQ[NMAX], vis[NMAX], i;
	vector <int> :: iterator it;
	
	for (i = 1; i <= N; i ++)
	{
		vis[i] = 0;
		father[i] = 0;
	}
	int p = 1, u = 0;
	inQ[++ u] = 1; vis[1] = 1;
	
	while (p <= u)
	{
		int nod = inQ[p];
		for (it = G[nod].begin(); it != G[nod].end(); it ++)
			if (F[nod][*it] < C[nod][*it] && !vis[*it])
			{
				father[*it] = nod;
				inQ[++ u] = *it;
				vis[*it] = 1;
				if (*it == N)
					return true;
			}
		p ++;
	}
	
	return false;
}

void augment(int sink)
{
	int flux = 1 << 30, nod = sink;
	vector <int> :: iterator it;
	
	for (it = G[sink].begin(); it != G[sink].end(); it ++)
	{
		flux = C[*it][sink] - F[*it][sink];
		nod = *it;
		
		while (nod > 1 && flux)
		{
			if (C[father[nod]][nod] - F[father[nod]][nod] < flux)
				flux = C[father[nod]][nod] - F[father[nod]][nod];
			nod = father[nod];
		}
		
		if (flux)
		{
			F[*it][sink] += flux; F[sink][*it] -= flux;
			int nod = *it;
			while (nod > 1)
			{
				F[father[nod]][nod] += flux;
				F[nod][father[nod]] -= flux;
				nod = father[nod];
			}
		}
	}
}


void DFS1(int nod)
{
	vector <int> :: iterator it;
	
	reach[nod] = 1;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (F[nod][*it] < C[nod][*it] && !reach[*it])
			DFS1(*it);
}

void getSol(int nod, int N)
{
	vector <int> :: iterator it;
	
	vis2[nod] = 1;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (!vis2[*it])
		{
			if (reach[*it])
				getSol(*it, N);
			else
			{
				F[nod][*it] --; F[*it][nod] ++;
				if (memo[*it] == 1 || (BFS(N) && memo[*it] == -1))
				{
					sol[++ sol[0]] = ord[nod][*it];
					memo[*it] = 1;
				}
				else
					memo[*it] = 0;
				F[nod][*it] ++; F[*it][nod] --;
			}
		}
}

int main()
{
	int i, N, M;
	
	freopen("critice.in", "r", stdin);
	freopen("critice.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int x0, y0, c;
		
		scanf("%d%d%d", &x0, &y0, &c);
		G[x0].push_back(y0);
		G[y0].push_back(x0);
		C[x0][y0] = C[y0][x0] = c;
		ord[x0][y0] = ord[y0][x0] = i;
	}
	
	while (BFS(N))
		augment(N);
	for (i = 1; i <= N; i ++)
		memo[i] = -1;
	DFS1(1);
	getSol(1, N);
	
	sort(sol + 1, sol + sol[0] + 1);
	for (i = 0; i <= sol[0]; i ++)
		printf("%d\n", sol[i]);
	return 0;
}
