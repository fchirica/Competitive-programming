#include <stdio.h>
#include <vector>
#define NMAX 1000100

using namespace std;

vector <int> G[NMAX];
int visited[NMAX]; 

void DF(int node)
{
	vector <int> :: iterator it;
	
	visited[node] = 1;
	for (it = G[node].begin(); it != G[node].end(); it ++)
		if (visited[*it] == 0)
			DF(*it); 
}

int main()
{
	int i, x, y, now, N, M, K;
	
	freopen("berarii2.in", "r", stdin);
	freopen("berarii2.out", "w", stdout);
	
	scanf("%d%d%d", &N, &M, &K);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d", &x, &y);
		G[y].push_back(x);
	}
	
	for (i = 1; i <= K; i ++)
	{
		scanf("%d", &now);
		DF(now);
	}
	
	int sol = 0;
	
	for (i = 1; i <= N; i ++)
		if (visited[i] == 0)
			sol ++;
	printf("%d\n", sol);
	
	for (i = 1; i <= N; i ++)
		if (visited[i] == 0)
			printf("%d\n", i);

	return 0;
}
