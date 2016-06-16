#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

vector <int> G[1024], GT[1024]; 
int timp[1024], vis[1024], Q[1024], pred[1024];
char x[1024];
int num;

void DFS1(int nod)
{
	vis[nod] = 1;
	
	vector <int> :: iterator it;
	for (it = GT[nod].begin(); it != GT[nod].end(); it ++)
		if (vis[*it] == 0)
			DFS1(*it);
	timp[++ timp[0]] = nod;
}

void DFS2(int nod)
{
	vis[nod] = 1;
	num ++;
	
	vector <int> :: iterator it;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (vis[*it] == 0)
			DFS2(*it);
}

int main()
{
	int i, j, N, M;
	vector <int> :: iterator it;

	freopen("dezbateri.in", "r", stdin);
	freopen("dezbateri.out", "w", stdout);
	
	scanf("%d%d\n", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		gets(x + 1);
		int n = strlen(x + 1), x0 = 0, y0 = 0, z0 = 0, parse = 0, tip = 0;
		for (j = 1; j <= n; j ++)
		{
			if (x[j] == '>')
			{
				parse ++;
				if (parse == 1)
					tip = 1;
				else
					tip = 2;
				continue;
			}
			if (x[j] == ',')
			{
				parse ++;
				continue;
			}
			if (parse == 0)
				x0 = x0 * 10 + x[j] - '0';
			if (parse == 1)
				y0 = y0 * 10 + x[j] - '0';
			if (parse == 2)
				z0 = z0 * 10 + x[j] - '0';
		}
		
		if (tip == 1)
		{
			G[y0].push_back(x0);
			GT[x0].push_back(y0);
			G[z0].push_back(x0);
			GT[x0].push_back(z0);
			pred[x0] += 2;
		}
		else
		{
			G[z0].push_back(x0);
			GT[x0].push_back(z0);
			G[z0].push_back(y0);
			GT[y0].push_back(z0);
			pred[x0] ++;
			pred[y0] ++;
		}
	}
	
	for (i = 1; i <= N; i ++)
		if (vis[i] == 0)
			DFS1(i);
	memset(vis, 0, sizeof(vis));
	for (i = timp[0]; i >= 0; i --)
		if (vis[timp[i]] == 0)
		{
			num = 0;
			DFS2(timp[i]);
			if (num >= 2)
			{
				printf("0");
				return 0;
			}
		}
		
	int p = 1, u = 0;
	for (i = 1; i <= N; i ++)
		if (pred[i] == 0)
			Q[++ u] = i;
		
	int idx, min;
	while (p <= u)
	{
		min = N + 100;
		for (i = p; i <= u; i ++)
			if (Q[i] < min)
				min = Q[i], idx = i;
		int aux = Q[p]; Q[p] = Q[idx]; Q[idx] = aux;
		for (it = G[Q[p]].begin(); it != G[Q[p]].end(); it ++)
		{
			pred[*it] --;
			if (pred[*it] == 0)
				Q[++ u] = *it;
		}
		p ++;
	}
	
	for (i = 1; i <= N; i ++)
		printf("%d ", Q[i]);
	return 0;
}
