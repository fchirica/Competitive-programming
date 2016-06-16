#include <stdio.h>
#include <vector>
#define MAXN 1024

using namespace std;

vector <int> G[MAXN];
int sol[MAXN];

void DFS(int nod)
{
	if (sol[nod])
		return ;
	vector <int> :: iterator it;
	
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
	{
		DFS(*it);
		sol[nod] += sol[*it];
	}
	
	if (sol[nod] == 0)
		sol[nod] = 1;
}

int main()
{
	int i, j, N, test;
	
	for (test = 1; scanf("%d", &N) != EOF; test ++)
	{
		for (i = 0; i < N; i ++)
		{
			int n0, x0;
			scanf("%d", &n0);
			for (j = 1; j <= n0; j ++)
			{
				scanf("%d", &x0);
				G[i].push_back(x0);
			}
		}
		
		DFS(0);
		
		if (test > 1)
			printf("\n");
		printf("%d\n", sol[0]);
		
		for (i = 0; i < N; i ++)
			G[i].clear(), sol[i] = 0;
	}
	
	return 0;
}
