#include <stdio.h>

struct par
{
	int y, c;
};

vector<par> vecini[1 << 10];
int Q[5000], cost[1024];

par mp(int y, int c)
{
	par aux;
	
	aux.y = y;
	aux.c = c;
	
	return aux;
}

int main()
{
	int N, M, x, y, c;
	vector <par> :: iterator it;
	
	freopen("orient.in", "r", stdin);
	freopen("orient.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d%d", &x, &y, &c);
		vecini[x].push_back(y, 0);
		vecini[y].push_back(x, c);
	}
	
	for (i = 1; i <= N; i ++)
	{
		p = 1; u = 0;
		Q[++ u] = i;
		for (j = 1; j <= N; j ++)
			cost[j] = INF;
		
		while (p <= u)
		{
			
		}