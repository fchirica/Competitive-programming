#include <stdio.h>
#include <vector>

using namespace std;
vector <int> G[100100];
bool vis[100100];

void DFS(int nod)
{
	vector <int> :: iterator it;
	
	vis[nod] = 1;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (vis[*it] == 0)
			DFS(*it);
}


int main()
{
	int i, N, M;
	
	freopen("drum4.in", "r", stdin);
	freopen("drum4.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int x0, y0;
		
		scanf("%d%d", &x0, &y0);
		G[x0].push_back(y0);
		G[y0].push_back(x0);
	}
	
	int sol = 0;
	for (i = 1; i <= N; i ++)
		if (vis[i] == 0)
		{
			sol ++;
			DFS(i);
		}
		
	printf("%d", sol);
	return 0;
}
