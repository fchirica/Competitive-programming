#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int isConnected[105], vis[105], sol[105][105];
int N;
vector <int> G[105];

void DFS(int nod)
{
	isConnected[nod] = 1;
	vector <int> :: iterator it;
	
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (isConnected[*it] == 0)
			DFS(*it);
}

void DFS2(int nod, int forbidden)
{
	if (forbidden == 1)
		return ;
	vis[nod] = 1;
	
	vector <int> :: iterator it;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (vis[*it] == 0 && *it != forbidden)
			DFS2(*it, forbidden);
}

void print()
{
	printf("+");
	int i;
	for (i = 1; i <= 2 * N - 1; i ++)
		printf("-");
	printf("+\n");
}

int main()
{
	int i, j, test, testCases;
	vector <int> :: iterator it;
	
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	scanf("%d", &testCases);
	for (test = 1; test <= testCases; test ++)
	{
		scanf("%d", &N);
		
		int x;
		for (i = 1; i <= N; i ++)
			for (j = 1; j <= N; j ++)
			{
				sol[i][j] = 0;
				scanf("%d", &x);
				if (x)
					G[i].push_back(j);
			}
			
		memset(isConnected, 0, sizeof(vis));
		DFS(1); 
	
		for (i = 1; i <= N; i ++)
		{
			for (j = 1; j <= N; j ++)
				vis[j] = 0;
			DFS2(1, i);
			for (j = 1; j <= N; j ++)
				if (isConnected[j] && !vis[j])
					sol[i][j] = 1;
		}
		
		printf("Case %d:\n", test);
		for (i = 1; i <= N; i ++)
		{
			print();
			printf("|");
			for (j = 1; j <= N; j ++)
				if (sol[i][j])
					printf("Y|");
				else
					printf("N|");
			printf("\n");
		}
		print();
		
		for (i = 1; i <= N; i ++)
			G[i].clear();
	}
	
	return 0;
}

