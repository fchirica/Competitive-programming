#include <stdio.h>
#include <string.h>
#include <vector>
#define INF (1 << 30)

using namespace std;

int gagici[6], dist[6][1024], out[1024], distOut[6], used[6][1024];
int Hsize, bestSol = 1 << 30, vis[6], S, st[6];

struct graf
{
	int x, y;
} H[1000024];

vector <graf> G[1024];

graf mp(int x0, int y0)
{
	graf aux;
	aux.x = x0; aux.y = y0;
	return aux;
}

void swap(graf &A, graf &B)
{
	graf aux; 
	aux.x = A.x; aux.y = A.y;
	A.x = B.x; A.y = B.y;
	B.x = aux.x; B.y = aux.y;
}

void bagaHeap(int val, int cost)
{
	H[++ Hsize] = mp(val, cost);
	int nod = Hsize;
	
	while (nod > 1 && H[nod / 2].y > H[nod].y)
	{
		swap(H[nod], H[nod / 2]);
		nod = nod / 2;
	}
}

void scoateHeap()
{
	swap(H[1], H[Hsize]); Hsize --;
	
	int nod = 1, son;
	do
	{
		son = 0;
		if (2 * nod <= Hsize)
			son = 2 * nod;
		if (2 * nod + 1 <= Hsize && H[2 * nod + 1].y < H[2 * nod].y)
			son = 2 * nod + 1;
		if (H[nod].y < H[son].y)
			son = 0;
		if (son)
		{
			swap(H[nod], H[son]);
			nod = son;
		}
	}
	while (son);
}

void Dijkstra(int idx, int N, int nod)
{
	int i;
	
	Hsize = 0;
	
	for (i = 1; i <= N; i ++)
	{
		dist[idx][i] = INF;
		if (i == nod)
		{
			dist[idx][i] = 0;
			bagaHeap(i, 0);
		}
	}
	
	graf now;
	vector <graf> :: iterator it;
	
	while (Hsize)
	{
		now = H[1];
		scoateHeap();
		if (used[idx][now.x])
			continue;
		used[idx][now.x] = 1;
		
		for (it = G[now.x].begin(); it != G[now.x].end(); it ++)
			if (now.y + it -> y < dist[idx][it -> x])
			{
				bagaHeap(it -> x, now.y + it -> y);
				dist[idx][it -> x] = now.y + it -> y;
			}
	}
}

void back(int k)
{
	int i;
	
	if (k == 6)
	{
		int now = dist[st[1]][S];
		for (i = 1; i < 5; i ++)
			now += dist[st[i]][gagici[st[i + 1]]];
		now = now + distOut[st[5]];
		if (now < bestSol)
			bestSol = now;
		return ;
	}
	
	for (i = 1; i <= 5; i ++)
		if (vis[i] == 0)
		{
			vis[i] = 1;
			st[k] = i;
			back(k + 1);
			vis[i] = 0;
		}
}

int main()
{
	int i, j, N, M, K, x0, y0, w0;
	
	freopen("zmeu.in", "r", stdin);
	freopen("zmeu.out", "w", stdout);
	
	scanf("%d%d%d%d", &N, &M, &K, &S);
	for (i = 1; i <= 5; i ++)
		scanf("%d", &gagici[i]);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d%d", &x0, &y0, &w0);
		G[x0].push_back(mp(y0, w0));
		G[y0].push_back(mp(x0, w0));
	}
	
	for (i = 1; i <= 5; i ++)
		Dijkstra(i, N, gagici[i]);
	for (i = 1; i <= K; i ++)
	{
		scanf("%d", &x0);
		out[x0] = 1;
	}
	
	for (i = 1; i <= 5; i ++)
	{
		distOut[i] = 1 << 30;
		for (j = 1; j <= N; j ++)
			if (out[j] && dist[i][j] < distOut[i])
				distOut[i] = dist[i][j];
	}
	
	back(1);
	
	printf("%d", bestSol);
	return 0;
}
