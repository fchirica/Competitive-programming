#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct muchie
{
	int x0, y0, cost;
};

muchie E[100100];

struct par
{
	int x, cost;
};
vector <par> G[10100];

par mp(int X, int Y)
{
	par aux; aux.x = X; aux.cost = Y;
	return aux;
}

bool comp(muchie X, muchie Y)
{
	return X.cost < Y.cost;
}

int T[10100], R[10100], cost[10100];

int getFather(int X)
{
	int root = X;
	
	while (root != T[root])
		root = T[root];
	while (X != root)
	{
		int aux = T[X];
		T[X] = root;
		X = aux;
	}
	
	return root;
}

void unite(int X, int Y)
{
	if (R[X] <= R[Y])
	{
		T[X] = Y;
		if (R[X] == R[Y])
			R[Y] ++;
	}
	else
		T[Y] = X;
}

void DFS(int nod, int Cnow)
{
	vector <par> :: iterator it;
	
	cost[nod] = Cnow;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (cost[it -> x] == 0)
		{
			if (it -> cost > Cnow)
				Cnow = it -> cost;
			DFS(it -> x, Cnow);
		}
}

int main()
{
	int i, N, M, K;
	
	freopen("apm2.in", "r", stdin);
	freopen("apm2.out", "w", stdout);
	
	scanf("%d%d%d", &N, &M, &K);
	for (i = 1; i <= M; i ++)
		scanf("%d%d%d", &E[i].x0, &E[i].y0, &E[i].cost);
	
	sort(E + 1, E + M + 1, comp);
	for (i = 1; i <= N; i ++)
		T[i] = i, R[i] = 1;
	
	for (i = 1; i <= M; i ++)
	{
		int dad1 = getFather(E[i].x0), dad2 = getFather(E[i].y0);
		if (dad1 == dad2)
			continue;
		G[dad1].push_back(mp(dad2, E[i].cost));
		G[dad2].push_back(mp(dad1, E[i].cost));
		unite(dad1, dad2);
	}
	
	for (i = 1; i <= K; i ++)
	{
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		memset(cost, 0, sizeof(cost));
		DFS(x0, 0);
		printf("%d\n", cost[y0] - 1);
	}
	
	return 0;
}
