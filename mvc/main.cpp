#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[100100];
int cost[100100], father[100100];

int X, Y;

void DFS(int nod, int last)
{
	vector <int> :: iterator it;
	
	if (X && Y)
		return ;
	
	father[nod] = last;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
	{
		if (father[*it] == 0)
			DFS(*it, nod);
		else
			if (father[*it] && last != *it)
				X = *it, Y = nod;
	}
}

int d1[100100], d2[100100], vis[100100];

inline int min(int A, int B)
{
	if (A < B)
		return A;
	return B;
}

void DFS2(int X)
{
	vector <int> :: iterator it;

	vis[X] = 1;
	d1[X] = cost[X];
	
	for (it = G[X].begin(); it != G[X].end(); it ++)
		if (*it != -69 && !vis[*it])
		{
			DFS2(*it);
			d1[X] += min(d1[*it], d2[*it]);
			d2[X] += d1[*it];
		}
}
	

int solve(int X, int N)
{
	int i; 
	
	for (i = 1; i <= N; i ++)
		d1[i] = d2[i] = vis[i] = 0;
	DFS2(X);
	return d1[X];
}

int main()
{
	int i, N;
	vector <int> :: iterator it;

	freopen("mvc.in", "r", stdin);
	freopen("mvc.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d", &cost[i]);
	for (i = 1; i <= N; i ++)
	{
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		G[x0].push_back(y0);
		G[y0].push_back(x0);
	}
	
	DFS(1, -1);
	
	for (it = G[X].begin(); it != G[X].end(); it ++)
		if (*it == Y)
		{
			*it = -69;
			continue;
		}
	for (it = G[Y].begin(); it != G[Y].end(); it ++)
		if (*it == X)
		{
			*it = -69;
			continue;
		}
	
	int sol = min(solve(X, N), solve(Y, N));
	
	printf("%d", sol);
	return 0;
}
