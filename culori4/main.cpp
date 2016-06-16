#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

int x[12][12], dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
long long tmp;
bool visited[12][12];

struct pereche
{
	int x, y;
} white[20], black[20];
int nW, nB;

pereche mp(int X, int Y)
{
	pereche now; 
	now.x = X; now.y = Y;
	return now;
}

void DF(int x0, int y0)
{
	visited[x0][y0] = 1;
	if ((x0 + y0) % 2 == 0)
		white[++ nW] = mp(x0, y0);
	else
		black[++ nB] = mp(x0, y0);
	
	int d;
	for (d = 0; d < 4; d ++)
		if (x[x0 + dx[d]][y0 + dy[d]] == -1 && !visited[x0 + dx[d]][y0 + dy[d]])
			DF(x0 + dx[d], y0 + dy[d]);
}

bool check(int val, int x0, int y0)
{
	int d;
	
	for (d = 0; d < 4; d ++)
		if (x[x0 + dx[d]][y0 + dy[d]] == val)
			return false;
	return true;
}

long long cnt(pereche X[], int N)
{
	int i, d;
	long long ans = 1;
	int exist[6];
	
	for (i = 1; i <= N; i ++)
	{
		int x0 = X[i].x, y0 = X[i].y;
		exist[1] = exist[2] = exist[3] = exist[4] = exist[5] = 0;
		for (d = 0; d < 4; d ++)
			if (x[x0 + dx[d]][y0 + dy[d]] > 0)
				exist[x[x0 + dx[d]][y0 + dy[d]]] = 1;
			
		int now = 5;
		for (d = 1; d <= 5; d ++)
			if (exist[d])
				now --;
		ans = ans * now;
	}
	
	return ans;
}

void solveWhite(int k)
{
	if (k == nW + 1)
	{
		tmp += cnt(black, nB);
		return ;
	}
	
	int i;
	for (i = 1; i <= 5; i ++)
		if (check(i, white[k].x, white[k].y))
		{
			x[white[k].x][white[k].y] = i;
			solveWhite(k + 1);
		}
}

void solveBlack(int k)
{
	if (k == nB + 1)
	{
		tmp += cnt(white, nW);
		return ;
	}
	
	int i;
	for (i = 1; i <= 5; i ++)
		if (check(i, black[k].x, black[k].y))
		{
			x[black[k].x][black[k].y] = i;
			solveBlack(k + 1);
		}
}

int main()
{
	int i, j, N;
	char ch;
	long long sol = 1;
	
	freopen("culori4.in", "r", stdin);
	freopen("culori4.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; i ++, scanf("\n"))
		for (j = 1; j <= N; j ++)
		{
			scanf("%c", &ch);
			if (ch == '?')
				x[i][j] = -1;
			else
			{
				x[i][j] = ch - '0';
				if (check(x[i][j], i, j) == 0)
					sol = 0;
			}
		}
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			if (!visited[i][j] && x[i][j] == -1)
			{
				memset(white, 0, sizeof(white));
				memset(black, 0, sizeof(black));
				nW = nB = 0;
				DF(i, j);
				
				tmp = 0;
				if (nW < nB)
					solveWhite(1);
				else
					solveBlack(1);
				sol = sol * tmp;
			}
			
	printf("%lld", sol);
	return 0;
}
