#include <stdio.h>
#include <vector>

using namespace std;

struct muchie
{
	int x;
	int bit;
};
vector <muchie> G[1024];
int degree[1024], cul[1024];

muchie makeVertex(int x0, int y0)
{
	muchie aux;
	aux.x = y0; aux.bit = x0;
	return aux;
}

void DFS(int x, int color)
{
	vector <muchie> :: iterator it;
	
	cul[x] = color;
	for (it = G[x].begin(); it != G[x].end(); it ++)
		if (cul[it -> x] == -1)
		{
			if (color == 0 && it -> bit == 0)
				DFS(it -> x, 1);
			if (color == 0 && it -> bit == 1)
				DFS(it -> x, 0);
			if (color == 1 && it -> bit == 1)
				DFS(it -> x, 1);
			if (color == 1 && it -> bit == 0)
				DFS(it -> x, 0);
		}
}

int main()
{
	int i, N, M, x, y;
	char ch;
	
	freopen("honest.in", "r", stdin);
	freopen("honest.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d %c %d", &x, &ch, &y);
		if (ch == 'c')
			G[x].push_back(makeVertex(1, y));
		else
			G[x].push_back(makeVertex(0, y));
		degree[y] ++;
	}
	
	for (i = 1; i <= N; i ++)
		cul[i] = -1;
	for (i = 1; i <= N; i ++)
		if (degree[i] == 0)
			DFS(i, 1);
	
	int tot = 0, change = 0;
	for (i = 1; i <= N; i ++)
		if (cul[i])
			tot ++;
	if (tot < N / 2)
		change = 1;
	for (i = 1; i <= N; i ++)
		printf("%d\n", cul[i] ^ change);
	return 0;
}
