#include <stdio.h>
#include <algorithm>
#define MOD 30103

using namespace std;

int x[800], AIB[800][800], dp[800][800];

struct par
{
	int x, y;
} pos[800 * 800];

inline bool comp(par A, par B)
{
	return x[A.x] + x[A.y] < x[B.x] + x[B.y];
}

inline int lsb(int X)
{
	return X & -X;
}

int query(int X, int Y)
{
	int ret = 0, i, j;
	
	for (i = X; i > 0; i = i - lsb(i))
		for (j = Y; j > 0; j = j - lsb(j))
		{
			ret = ret + AIB[i][j];
			ret = ret % MOD;
		}
	
	return ret;
}

void update(int X, int Y, int val, int N)
{
	int i, j;
	
	for (i = X; i <= N; i = i + lsb(i))
		for (j = Y; j <= N; j = j + lsb(j))
			AIB[i][j] += val;
}

int main()
{
	int i, j, N, cnt = 0, sol = 0;
	
	freopen("evantai.in", "r", stdin);
	freopen("evantai.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	
	for (i = 1; i < N; i ++)
		for (j = i + 1; j <= N; j ++)
			pos[++ cnt].x = i, pos[cnt].y = j;
	
	sort(pos + 1, pos + cnt + 1, comp);
	
	int last = -1, cur;
	
	for (i = 1; i <= cnt; i ++)
	{
		int needx = pos[i].x + 1, needy = pos[i].y - 1, ret;
		cur = x[pos[i].x] + x[pos[i].y];
		
		if (last != cur && last != -1)
			for (j = i - 1; j >= 1 && x[pos[j].x] + x[pos[j].y] == last; j --)
				update(pos[j].x, pos[j].y, dp[pos[j].x][pos[j].y], N);
		
		last = cur;
	
		ret = query(needy, needy) - query(needx - 1, needy) + 1;
		if (ret < 0)
			ret += MOD;
		if (ret >= MOD)
			ret -= MOD;
		
		dp[pos[i].x][pos[i].y] = ret;
		sol += ret;
		if (sol >= MOD)
			sol = sol - MOD;
	}
	
	printf("%d", sol);
	return 0;
}
