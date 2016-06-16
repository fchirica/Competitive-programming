#include <stdio.h>
#include <algorithm>
#define NMAX 100100

using namespace std;

int x[NMAX], AIB[NMAX], pos[NMAX];

struct query
{
	int x, y, ord, sol;
} Q[NMAX];

bool cmp1(query A, query B)
{
	return A.y < B.y;
}

bool cmp2(query A, query B)
{
	return A.ord < B.ord;
}

inline int lsb(int X)
{
	return X & -X;
}

int query(int X)
{
	int cnt = 0;
	
	for (; X > 0; X = X - lsb(X))
		cnt = (cnt + AIB[X]) % 666013;
	
	return cnt;
}

void update(int pos, int val, int N)
{
	for (; pos <= N; pos = pos + lsb(pos))
	{
		AIB[pos] = (AIB[pos] + val) % 666013;
		if (AIB[pos] < 0)
			AIB[pos] += 666013;
	}
}

int main()
{
	int i, j, N, K, M;
	
	freopen("distincte.in", "r", stdin);
	freopen("distincte.out", "w", stdout);
	
	scanf("%d%d%d", &N, &K, &M);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d", &Q[i].x, &Q[i].y);
		Q[i].ord = i;
	}
	
	sort(Q + 1, Q + M + 1, cmp1);
	for (i = 1; i <= M; i ++)
	{
		for (j = Q[i - 1].y + 1; j <= Q[i].y; j ++)
		{
			if (pos[x[j]])
				update(pos[x[j]], x[j] * (-1), N);
			pos[x[j]] = j;
			update(j, x[j], N);
		}
		
		Q[i].sol = query(Q[i].y) - query(Q[i].x - 1);
		if (Q[i].sol < 0)
			Q[i].sol += 666013;
	}
	
	sort(Q + 1, Q + M + 1, cmp2);
	for (i = 1; i <= M; i ++)
		printf("%d\n", Q[i].sol);
	return 0;
}
