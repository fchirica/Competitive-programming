#include <stdio.h>
#include <vector>
#include <algorithm>
#define NMAX 17000

using namespace std;

vector<int> G[NMAX];
int N, sol[NMAX], numEdges[NMAX];
bool visited[NMAX];

void DF(int node)
{
	vector<int> :: iterator it;
	
	sol[node] = -1000000000;
	numEdges[node] = 1;
	visited[node] = true;
	
	for (it = G[node].begin(); it != G[node].end(); it ++)
		if (visited[*it] == false)
		{
			DF(*it);
			numEdges[node] = numEdges[node] + numEdges[*it];
			sol[node] = max(sol[node], numEdges[*it]);
		}
	
	sol[node] = max(sol[node], N - numEdges[node]);
}

int main()
{
	int x, y, i;
	
	freopen("sediu.in", "r", stdin);
	freopen("sediu.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i < N; i ++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	DF(1);
	
	int numSol, bestSol = 1000000000;
	
	for (i = 1; i <= N; i ++)
	{
		if (sol[i] == bestSol)
			numSol ++;
		if (sol[i] < bestSol)
		{
			bestSol = sol[i];
			numSol = 1;
		}
	}
	
	printf("%d %d\n", bestSol, numSol);
	for (i = 1; i <= N; i ++)
		if (sol[i] == bestSol)
			printf("%d ", i);
	return 0;
}
