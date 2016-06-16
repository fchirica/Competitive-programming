#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 100100

using namespace std;

int cost[NMAX], ind[NMAX], sol[NMAX];
vector<int> G[NMAX];

inline bool comp(int A, int B)
{
	return cost[A] < cost[B];
}

void DF(int node, int value)
{
	vector<int> :: iterator it;
	
	if (sol[node] == 0)
		sol[node] = value;
	for (it = G[node].begin(); it != G[node].end(); it ++)
		if (sol[*it] == 0)
			DF(*it, value);
}

int main()
{
	int i, N, M, x, y;
	
	freopen("srevni.in", "r", stdin);
	freopen("srevni.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &cost[i]);
		ind[i] = i;
	}
	
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d", &x, &y);
		G[y].push_back(x);
	}
	
	sort(ind + 1, ind + N + 1, comp);
	for (i = 1; i <= M; i ++)
		DF(ind[i], cost[ind[i]]);
	
	for (i = 1; i <= N; i ++)
		printf("%d ", sol[i]);
	return 0;
}
