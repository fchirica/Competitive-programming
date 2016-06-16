#include <stdio.h>
#include <string.h>

char line[255]; 
int st[30], graf[30][30], cost[30], is[30], vis[30], sol[30];

int parse(char ch)
{
	return ch - 'A' + 1;
}

void DFS(int nod)
{
	int i;
	
	vis[nod] = 1;
	for (i = 1; i <= 26; i ++)
		if (graf[nod][i] && !vis[i])
			DFS(i);
	st[++ st[0]] = nod;
}

int main()
{
	int i, len, j, test, T;
	
	scanf("%d\n\n", &T);
	for (test = 1; test <= T; test ++)
	{
		while (gets(line + 1))
		{
			if (line[1] == 0)
				break;
			
			len = strlen(line + 1);
			int nod = parse(line[1]); is[nod] = 1;
			for (i = 2; line[i] == ' '; i ++);
			cost[nod] = 0;
			for (; '0' <= line[i] && line[i] <= '9'; i ++)
				cost[nod] = cost[nod] * 10 + line[i] - '0';
			for (; line[i] == ' ' && i <= len; i ++);
			for (; i <= len; i ++)
				graf[parse(line[i])][nod] = 1;
		}
		
		if (test > 1)
			printf("\n");
		
		int ans = 0;
		
		for (i = 1; i <= 26; i ++)
			if (is[i] && !vis[i])
				DFS(i);
		for (i = st[0]; i >= 1; i --)
		{
			sol[st[i]] = 0;
			for (j = 1; j <= 26; j ++)
				if (graf[j][st[i]])
					if (sol[j] > sol[st[i]])
						sol[st[i]] = sol[j];
			sol[st[i]] += cost[st[i]];
			if (sol[st[i]] > ans)
				ans = sol[st[i]];
		}
		printf("%d\n", ans);
		
		for (i = 1; i <= 26; i ++)
			for (j = 1; j <= 26; j ++)
				graf[i][j] = 0;
		for (i = 1; i <= 26; i ++)
			is[i] = vis[i] = 0;
		st[0] = 0;
	}
	
	return 0;
}
