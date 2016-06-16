#include <stdio.h>

int cnt[260000];

int get(char ch)
{
	if ('a' <= ch && ch <= 'z')
		return ch - 'a';
	if ('A' <= ch && ch <= 'Z')
		return ch - 'A' + 26;
	return ch - '0' + 52;
}

void add(char x0, char x1, char x2)
{
	int where = get(x2) + get(x1) * 62 + get(x0) * 62 * 62;
	cnt[where] ++;
}

int main()
{
	char ch[3];
	int i, N = -1, lung = 0;
	
	freopen("trigrame.in", "r", stdin);
	freopen("trigrame.out", "w", stdout);
	
	while (1)
	{
		++lung;
		N = (N + 1) % 3;
		scanf("%c", &ch[N]);
		if (ch[N] == ' ' || ch[N] == '\n')
			break;
		int last1 = (N + 2) % 3, last2 = (N + 1) % 3;
		if (lung >= 3)
			add(ch[last2], ch[last1], ch[N]);
	}
	
	int unique = 0, max = 0, frequence = 0;
	for (i = 0; i <= 255000; i ++)
		if (cnt[i])
		{
			unique ++;
			if (cnt[i] > max)
				max = cnt[i], frequence = 0;
			if (cnt[i] == max)
				frequence ++;
		}
	
	printf("%d %d %d", unique, max, frequence);
	return 0;
}
