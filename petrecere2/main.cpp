#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector <int> T0[100100], T1[100100];
bool vis[100100];
int num, sum, sumtot;

void DFS(int nod, int take)
{
	vector <int> :: iterator it;

	vis[nod] = 1;
	sumtot ++; 
	if (take)
		sum ++;
	for (it = T0[nod].begin(); it != T0[nod].end(); it ++)
		if (!vis[*it])
			DFS(*it, take);
	for (it = T1[nod].begin(); it != T1[nod].end(); it ++)
		if (!vis[*it])
			DFS(*it, !take);
}

int main()
{
	int i, N, M;
	
	freopen("petrecere2.in", "r", stdin);
	freopen("petrecere2.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		int tip, x0, y0;
		scanf("%d%d%d", &tip, &x0, &y0);
		if (tip == 0)
		{
			T0[x0].push_back(y0);
			T0[y0].push_back(x0);
		}
		else
		{
			T1[x0].push_back(y0);
			T1[y0].push_back(x0);
		}
	}
	
	int sol = 0;
	for (i = 1; i <= N; i ++)
		if (vis[i] == 0)
		{
			sum = sumtot = 0;
			DFS(i, 1);
			int now = sum;
			if (sumtot - sum > now)
				now = sumtot - sum;
			sol += now;
		}
	
	printf("%d", sol);
	return 0;
}
