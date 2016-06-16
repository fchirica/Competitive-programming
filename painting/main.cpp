#include <stdio.h>
#include <vector>
#define NMAX 100010

using namespace std;

vector <int> G[NMAX], G2[NMAX];
int sol[NMAX], root[NMAX], col[NMAX], vis[NMAX];

void DFS(int nod)
{
	vector <int> :: iterator it;
	
	vis[nod] = 1;
	for (it = G2[nod].begin(); it != G2[nod].end(); ++ it)
		if (!vis[*it])
		{
			G[nod].push_back(*it);
			DFS(*it);
		}
}

void DFS2(int nod, int color)
{
	if (sol[nod] != -1)
		return ;
	sol[nod] = color;
	
	vector <int> :: iterator it;
	
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		DFS2(*it, color);
}

int main()
{
	int i, x, y, N, M;
	
	freopen("painting.in", "r", stdin);
	freopen("painting.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i < N; i ++)
	{
		scanf("%d%d", &x, &y);
		G2[x].push_back(y);
		G2[y].push_back(x);
	}
	for (i = 1; i <= M; i ++)
		scanf("%d%d", &root[i], &col[i]);

	DFS(1);
	for (i = 1; i <= N; i ++)
		sol[i] = -1;
	for (i = M; i >= 1; i --)
		DFS2(root[i], col[i]);
	for (i = 1; i <= N; i ++)
		if (sol[i] == -1)
			sol[i] = 1;
	
	for (i = 1; i <= N; i ++)
		printf("%d ", sol[i]);
	return 0;
}
