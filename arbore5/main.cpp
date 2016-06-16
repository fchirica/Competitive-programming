#include <stdio.h>
#include <vector>

using namespace std;

vector <int> Arb[100100];
int vis[100100], parity[100100];

void DFS(int nod)
{
	vector <int> :: iterator it;
	
	vis[nod] = 1;
	for (it = Arb[nod].begin(); it != Arb[nod].end(); it ++)
		if (vis[*it] == 0)
		{
			DFS(*it);
			parity[nod] = parity[nod] ^ parity[*it];
		}
}

int main()
{
	int i, N, K, x0, y0; 
	
	freopen("arbore5.in", "r", stdin);
	freopen("arbore5.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	for (i = 1; i < N; i ++)
	{
		scanf("%d%d", &x0, &y0);
		Arb[x0].push_back(y0);
		Arb[y0].push_back(x0);
	}
	for (i = 1; i <= K; i ++)
	{
		scanf("%d%d", &x0, &y0);
		parity[x0] ^= 1; parity[y0] ^= 1;
	}
	
	DFS(1);
	
	int sol = 0;
	for (i = 2; i <= N; i ++)
		if (parity[i] == 0)
			sol ++;
	printf("%d", sol);
	return 0;
}
