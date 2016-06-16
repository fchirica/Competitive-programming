#include <stdio.h>
#include <string.h>

char st[1024], x[1024];
char tmp[1024];

int values[512];
int u;

int get(int where, int val)
{
	int step;
	
	if (val == 1 || val == 2)
		step = 1;
	else
		step = -1;
	
	for (; tmp[where] == ' '; where += step);
	if (val == 1 && tmp[where] == 'N' && tmp[where + 1] == 'O' && tmp[where + 2] == 'T')
	{
		tmp[where] = tmp[where + 1] = tmp[where + 2] = ' ';
		return 1 - get(where + 3, val);
	}
	int ret = tmp[where]; tmp[where] = ' ';
	if (val == 1)
		return 1 - values[ret];
	else
		return values[ret];
}

void eval(int pos)
{
	int i, begin;

	for (begin = pos; begin >= 0; begin --)
		if (st[begin] == '(')
			break;
	for (i = begin + 1; i <= pos - 1; i ++)
	{
		tmp[i - begin] = st[i];
		st[i] = NULL;
	}
	u = begin - 1;
	int N = pos - begin - 1;
	
	for (i = 1; i <= N; i ++)
		if (tmp[i] == 'T' && tmp[i + 1] == 'R' && tmp[i + 2] == 'U' && tmp[i + 3] == 'E')
			tmp[i] = 1, tmp[i + 1] = tmp[i + 2] = tmp[i + 3] = ' ';
	for (i = 1; i <= N; i ++)
		if (tmp[i] == 'F' && tmp[i + 1] == 'A' && tmp[i + 2] == 'L' && tmp[i + 3] == 'S' && tmp[i + 4] == 'E')
			tmp[i] = 0, tmp[i + 1] = tmp[i + 2] = tmp[i + 3] = tmp[i + 4] = ' ';
		
	for (i = 1; i <= N; i ++)
		if (tmp[i] == 'N' && tmp[i + 1] == 'O' && tmp[i + 2] == 'T')
		{
			tmp[i] = tmp[i + 1] = ' '; tmp[i + 2] = ' ';
			tmp[i] = get(i + 3, 1);
		}
	
	for (i = 1; i <= N; i ++)
		if (tmp[i] == 'A' && tmp[i + 1] == 'N' && tmp[i + 2] == 'D')
		{
			int ret1 = get(i - 1, 3), ret2 = get(i + 3, 2);
			tmp[i] = tmp[i + 1] = tmp[i + 2] = ' ';
			tmp[i] = ret1 & ret2;
		}
	
	for (i = 1; i <= N; i ++)
		if (tmp[i] == 'O' && tmp[i + 1] == 'R')
		{
			int ret1 = get(i - 1, 3), ret2 = get(i + 2, 2);
			tmp[i] = tmp[i + 1] = ' ';
			tmp[i] = ret1 | ret2;
		}
	
	for (i = 1; i <= N; i ++)
		if (tmp[i] != ' ')
			st[++ u] = tmp[i];
}

void solve(int N)
{
	int i;
	
	u = 0;
	st[++ u] = '(';
	
	for (i = 1; i <= N; i ++)
	{
		st[++ u] = x[i];
		if (x[i] == ')')
			eval(u);
	}
	
	st[++ u] = ')';
	eval(u);
	printf("%d", st[1]);
}

int main()
{
	int i, N, M;
	
	freopen("bool.in", "r", stdin);
	freopen("bool.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	scanf("%d\n", &M);
	
	values[1] = 1;
	for (i = 1; i <= M; i ++)
	{
		char ch;
		
		scanf("%c", &ch);
		values[(int)ch] = 1 - values[(int)ch];
		solve(N);
	}
	
	return 0;
}
