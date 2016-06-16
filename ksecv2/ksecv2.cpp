#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LMAX 3500

using namespace std;

int x[LMAX], dp[LMAX][512], tree[2][4 * LMAX + 100];

inline int max (int a, int b)
{
	return a > b ? a : b;
}

void Normalizeaza (int N)
{
	int stx[LMAX], i;
	
	memset (stx, 0, sizeof (stx));
	for (i = 0; i <= N; i ++)
		stx[i] = x[i];
	
	sort (stx, stx + N + 1);
	
	int left, right, med;
	
	for (i = 0; i <= N; i ++)
	{
		left = 0; right = N;
		
		while (left <= right)
		{
			med = (left + right) / 2;
			if (stx[med] >= x[i])
				right = med - 1;
			else
				left = med + 1;
		}
		x[i] = left;
	}
}

void Upgrade (int node, int left, int right, int what, int poz, int value)
{
	int med = (left + right) / 2;
	
	if (left == right)
	{
		tree[what][node] = max (tree[what][node], value);
		return ;
	}
	
	if (poz <= med)
		Upgrade (2 * node, left, med, what, poz, value);
	else
		Upgrade (2 * node + 1, med + 1, right, what, poz, value);
	
	tree[what][node] = max (tree[what][2 * node], tree[what][2 * node + 1]);
}

int Query (int node, int left, int right, int what, int st, int dr)
{
	int med = (left + right) / 2, sol = -100;
	
	if (st <= left && right <= dr)
		return tree[what][node];
	
	if (st <= med)
		sol = Query (2 * node, left, med, what, st, dr);
	if (med < dr)
		sol = max (sol, Query (2 * node + 1, med + 1, right, what, st, dr));

	return sol;
}

void memsetTree (int val, int N)
{
	int i;
	
	for (i = 0; i <= 4 * N + 50; i ++)
		tree[val][i] = -1;
}

int main ()
{
	int N, K, i, j, k, best;
	
	freopen ("ksecv2.in", "r", stdin);
	freopen ("ksecv2.out", "w", stdout);
	
	x[0] = (1 << 30) * (-1);
	
	scanf ("%d%d", &N, &K);
	
	for (i = 1; i <= N; i ++)
		scanf ("%d", &x[i]);
	
	Normalizeaza (N);
	
	for (i = 0; i <= N; i ++)
		for (j = 1; j <= K; j ++)
			dp[i][j] = -1;
	dp[0][1] = 0;

	for (j = 1; j <= K; j ++)
	{
		memsetTree (0, N);
		memsetTree (1, N);
		Upgrade (1, 0, N, 0, x[0], dp[0][j]);
		
		for (i = 1; i <= N; i ++)
		{
			best = -1;
			//for (k = 0; k < i; k ++)
			//	if (x[k] <= x[i])
			//		best = max (best, dp[k][j]);
			//	else
			//		best = max (best, dp[k][j - 1]);
			best = max (best, Query (1, 0, N, 0, 0, x[i]));
			best = max (best, Query (1, 0, N, 1, x[i] + 1, N + 10));
			dp[i][j] = best + 1;
			if (best == -1)
				dp[i][j] = -1;
			Upgrade (1, 0, N, 0, x[i], dp[i][j]);
			Upgrade (1, 0, N, 1, x[i], dp[i][j - 1]);
		}
	}
	
	printf ("%d", dp[N][K]);
	
	return 0;
}
