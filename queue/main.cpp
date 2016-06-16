#include <stdio.h>
#include <string.h>

int st1[30100], st2[30100];
char x[150];

int parse(int N)
{
	int i, nr = 0;
	
	for (i = 1; i <= N; i ++)
		if ('0' <= x[i] && x[i] <= '9')
			nr = nr * 10 + x[i] - '0';

	return nr;
}

void load()
{
	if (st2[0])
		return ;
	while (st1[0])
	{
		printf("pop(1) push(2,%d) ", st1[st1[0]]);
		st2[++ st2[0]] = st1[st1[0]];
		st1[0] --;
	}
}

int main()
{
	int i, N, M;
	
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; i ++)
	{
		gets(x + 1);
		M = strlen(x + 1);
		
		printf("%d: ", i);
		
		int ret = parse(M);
		
		if (x[2] == 'u')
		{
			st1[++ st1[0]] = ret;
			printf("read(%d) push(1,%d)", ret, ret);
		}
		else
		{
			load();
			printf("pop(2) write(%d)", st2[st2[0]]);
			st2[0] --;
		}
		
		printf("\n");
	}
	
	return 0;
}

