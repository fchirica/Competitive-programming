#include <stdio.h>

int perm[100100];
bool vis[100100];

int main()
{
	int i, N, sol = 0;
	
	freopen("intersort.in", "r", stdin);
	freopen("intersort.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d", &perm[i]);
	for (i = 1; i <= N; i ++)
	{
		if (vis[i] == true)
			continue;
		
		int len = 0;
		int x = i;
		while (!vis[x])
		{
			++ len;
			vis[x] = 1;
			x = perm[x];
		}
		
		if (len == 1)
			continue;
		if (i == 1)
			sol += len - 1;
		else
		{
			int now = len + 1;
			if (len == 2 && i == 2)
				now = 2;
			sol += now;
		}
	}
	
	printf("%d", sol);
	return 0;
}
