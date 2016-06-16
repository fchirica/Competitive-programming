#include <stdio.h>
#include <vector>
#define NMAX 16100

using namespace std;

vector <int> G[NMAX];
int cost[NMAX], dp[NMAX];
bool visited[NMAX];

void DF(int node)
{
	vector<int> :: iterator it;
	visited[node] = 1;
	dp[node] = cost[node];
	
	for (it = G[node].begin(); it != G[node].end(); it ++)
		if (visited[*it] == 0)
		{
			DF(*it);
			if (dp[*it] > 0)
				dp[node] = dp[node] + dp[*it];
		}
}

int main()
{
	int i, x, y, N;
	
	freopen("asmax.in", "r", stdin);
	freopen("asmax.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d", &cost[i]);
	for (i = 1; i < N; i ++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	DF(1);
	
	int sol = dp[1];
	
	for (i = 2; i <= N; i ++)
		if (dp[i] > sol)
			sol = dp[i];
	
	printf("%d", sol);
	return 0;
}
