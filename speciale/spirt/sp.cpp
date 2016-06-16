//Nu am putut sa scriu decat un backtracking, deoarece inainte de concurs am
//baut prea mult spirt si m-am imbatat

#include <stdio.h>
#define LMAX 100
#define MOD 666013

char x[LMAX];
int st[LMAX], last[LMAX], sol = 0, now[LMAX];

void solve (int k, int n, int m)
{
	int i;
	
	if (k == n + 1)
	{
		sol ++;
		if (sol == MOD)
			sol = 0;
		return ;
	}
	
	for (i = 1; i <= m; i ++)
		if (i != now[k - 1] && i != now[last[k]])
		{
			now[k] = i;
			solve (k + 1, n, m);
		}
}

int main ()
{
	int i, N, M;
	
	freopen ("spirt.in", "r", stdin);
	freopen ("spirt.out", "w", stdout);
	
	scanf ("%d%d\n", &N, &M);
	gets (x + 1);
	
	for (i = 1; i <= N; i ++)
	{
		if (x[i] == '(')
			st[++ st[0]] = i;
		else
			last[i] = st[st[0]], st[0] --;
	}
	
	solve (1, N, M);
	printf ("%d", sol);
	
	return 0;
}
