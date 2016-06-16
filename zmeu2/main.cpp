#include <stdio.h>
#include <vector>
#define INF (1 << 30)

using namespace std;

bool mat[210][210], D[210], C[210];

vector <int> G[210];
short sol[210][510];

int u;
struct coditza
{
	short nod, capete;
} Q[210 * 510];

void push(int nod, int head)
{
	Q[++ u].nod = nod; Q[u].capete = head;
}

int main()
{
	int i, j, Head, N, M;
	vector <int> :: iterator it;
	
	freopen("zmeu2.in", "r", stdin);
	freopen("zmeu2.out", "w", stdout);
	
	scanf("%d%d%d", &Head, &N, &M);
	for (i = 1; i <= N; i ++)
		scanf("%d%d", &D[i], &C[i]);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			if (i != j)
				if (!(i == 1 && j == N))
					if (i != N && j != 1)
						mat[i][j] = 1;
	for (i = 1; i <= M; i ++)
	{
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		mat[x0][y0] = 0;
	}
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			if (mat[i][j])
				G[i].push_back(j);
			
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= Head; j ++)
			sol[i][j] = 32000;
		
	if (C[1] > Head)
	{
		printf("-1");
		return 0;
	}
	sol[1][Head - C[1]] = D[1];
	push(1, Head - C[1]);
	int p = 1, ans = 32000;

	while (p <= u)
	{
		for (it = G[Q[p].nod].begin(); it != G[Q[p].nod].end(); it ++)
		{
			int curHeads = Q[p].capete - C[*it];
			if (curHeads <= 0)
				continue;
			if (sol[Q[p].nod][Q[p].capete] + D[*it] >= ans)
				continue;
			if (sol[*it][curHeads] > sol[Q[p].nod][Q[p].capete] + D[*it])
			{
				sol[*it][curHeads] = sol[Q[p].nod][Q[p].capete] + D[*it];
				push(*it, curHeads);
				if (*it == N)
					if (sol[*it][curHeads] < ans)
						ans = sol[*it][curHeads];
			}
		}
		p ++;
	}
	
	if (ans == 32000)
		printf("-1");
	printf("%d", ans);
	return 0;
}
