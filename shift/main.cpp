#include <stdio.h>
#include <string.h>

char x[100100], ret[30][2];
int poz[30][2], cost[30][2];
int sol[100100][2];

inline int ab(int X)
{
	if (X > 0)
		return X;
	return -X;
}

inline int min(int A, int B)
{
	return A < B ? A : B;
}

int main()
{
	int i, N;
	char ch1, ch2;
	
	freopen("shift.in", "r", stdin);
	freopen("shift.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	
	for (i = 1; i <= 26; i ++)
	{
		scanf("%c %c\n", &ret[i][0], &ret[i][1]);
		ch1 = ret[i][0]; ch2 = ret[i][1];
		if (poz[ch1 - 'a'][0])
			poz[ch1 - 'a'][1] = i;
		else
			poz[ch1 - 'a'][0] = i;
		if (poz[ch2 - 'a'][0])
			poz[ch2 - 'a'][1] = i;
		else
			poz[ch2 - 'a'][0] = i;
	}
	
	for (i = 1; i <= 26; i ++)
	{
		int x0, y0;
		scanf("%d%d", &x0, &y0);
		ch1 = ret[i][0]; ch2 = ret[i][1];
		if (cost[ch1 - 'a'][0])
			cost[ch1 - 'a'][1] = x0;
		else
			cost[ch1 - 'a'][0] = x0;
		if (cost[ch2 - 'a'][0])
			cost[ch2 - 'a'][1] = y0;
		else
			cost[ch2 - 'a'][0] = y0;
	}
	
	sol[1][0] = poz[x[1] - 'a'][0] - 1 + cost[x[1] - 'a'][0];
	sol[1][1] = poz[x[1] - 'a'][1] - 1 + cost[x[1] - 'a'][1];
	
	for (i = 2; i <= N; i ++)
	{
		sol[i][0] = ab(poz[x[i] - 'a'][0] - poz[x[i - 1] - 'a'][0]) + cost[x[i] - 'a'][0] + sol[i - 1][0];
		sol[i][0] = min(sol[i][0], ab(poz[x[i] - 'a'][0] - poz[x[i - 1] - 'a'][1]) + cost[x[i] - 'a'][0] + sol[i - 1][1]);
		
		sol[i][1] = ab(poz[x[i] - 'a'][1] - poz[x[i - 1] - 'a'][0]) + cost[x[i] - 'a'][1] + sol[i - 1][0];
		sol[i][1] = min(sol[i][1], ab(poz[x[i] - 'a'][1] - poz[x[i - 1] - 'a'][1]) + cost[x[i] - 'a'][1] + sol[i - 1][1]);
	}
	
	int ans = sol[N][0];
	ans = min(ans, sol[N][1]);
	printf("%d", ans);
	return 0;
}
