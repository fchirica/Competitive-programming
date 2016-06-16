#include <stdio.h>
#include <string.h>

int next[120][5100][30], len[120], st[120][5100];
char word[120][5100];

int main()
{
	int i, j, k, N, M;
	char ch;
	
	freopen("search.in", "r", stdin);
	freopen("search.out", "w", stdout);
	
	scanf("%d%d\n", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		gets(word[i] + 1);
		len[i] = strlen(word[i] + 1);
	}
	
	for (i = 1; i <= N; i ++)
	{
		for (k = 0; k <= 25; k ++)
			next[i][len[i] + 1][k] = -1;
		for (j = len[i]; j >= 0; j --)
			for (k = 0; k <= 25; k ++)
				if (k + 'a' == word[i][j + 1])
					next[i][j][k] = j + 1;
				else
					next[i][j][k] = next[i][j + 1][k];
	}
	
	for (i = 1; i <= M; i ++)
	{
		int sol = 0;
		
		scanf(" %c ", &ch);
		if (ch == '-')
			for (j = 1; j <= N; j ++)
			{
				st[j][0] --;
				if (st[j][st[j][0]] != -1)
					sol ++;
			}
		else
			for (j = 1; j <= N; j ++)
			{
				int pos = st[j][st[j][0]];
				
				if (pos == -1)
					st[j][++ st[j][0]] = -1;
				else
				{
					st[j][++ st[j][0]] = next[j][pos][ch - 'a'];
					if (next[j][pos][ch - 'a'] != -1)
						++ sol;
				}
			}
		
		printf("%d\n", sol);
	}
	
	return 0;
}
