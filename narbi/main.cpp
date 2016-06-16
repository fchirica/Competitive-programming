#include <stdio.h>
#define lim ((1 << 15) - 1)

int sol[lim + 100];

void precalc()
{
	int i;
	
	for (i = 1; i <= lim; i ++)
		if (i & 1)
			sol[i] = (sol[i >> 1] << 1) + (i >> 1) + 1;
		else
			sol[i] = sol[i >> 1] + sol[(i >> 1) - 1] + (i >> 1);
}

inline int cnt(int X)
{
	return sol[X] - sol[X - 1];
}

int solve(int X)
{
	int ans, pref, suf;
	
	pref = X >> 15;
	suf = X & lim;
	
	ans = pref * sol[lim] + (lim + 1) * sol[pref - 1];
	ans += sol[suf] + (suf + 1) * cnt(pref);
	
	return ans;
}

int main()
{
	int i, N, K, X, last = 0;
	
	freopen("narbi.in", "r", stdin);
	freopen("narbi.out", "w", stdout);
	
	precalc();
	scanf("%d%d%d", &N, &K, &X);
	
	for (i = 1; i <= N; i ++)
	{
		last = solve(X);
		X = X + (last & 15) + 1;
		
		if (i >= N - K + 1)
			printf("%d\n", last);
	}
	
	return 0;
}
