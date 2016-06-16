#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

string x[50100], lw[50100], up[50100];
char now[30];

bool cmp1(char A, char B)
{
	return A > B;
}

void show(string X)
{
	int i;
	
	for (i = 0; i < X.size(); i ++)
		printf("%c", X[i]);
}

int main()
{
	int i, j, N;
	
	freopen("scramble.in", "r", stdin);
	freopen("scramble.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; i ++)
	{
		gets(now + 1); 
		int len = strlen(now + 1);
		for (j = 1; j <= len; j ++)
			x[i] += now[j];
		lw[i] += x[i]; up[i] += x[i];
		sort(lw[i].begin(), lw[i].end(), cmp1);
		sort(up[i].begin(), up[i].end());
	}
	
	sort(lw + 1, lw + N + 1);
	sort(up + 1, up + N + 1);
	
	for (i = 1; i <= N; i ++)
	{
		int st = 1, dr = N, med;
		
		string tmp = x[i];
		sort(tmp.begin(), tmp.end());
		
		while (st <= dr)
		{
			med = (st + dr) / 2;
			if (lw[med] >= tmp)
				dr = med - 1;
			else
				st = med + 1;
		}
		
		printf("%d", st);
		
		st = 1; dr = N;
		sort(tmp.begin(), tmp.end(), cmp1);

		while (st <= dr)
		{
			med = (st + dr) / 2;
			if (up[med] >= tmp)
				dr = med - 1;
			else
				st = med + 1;
		}
		
		if (tmp[0] != tmp[tmp.size() - 1])
			st --;
		printf(" %d\n", st);
	}
		
	return 0;
}
