#include <stdio.h>
#include <algorithm>
#include <vector>
#define MOD 884491    

using namespace std;

struct point
{
	int x, y;
} x[50000], sol[810000];
vector <point> H[MOD];

int cntSol = 0;

bool comp(point A, point B)
{
	return A.x < B.x;
}

int hash(point A)
{
	int P = 666013;
	long long code;
	
	code = 1LL * A.x * P + A.y % MOD;
	code = (code + A.x + 1LL * A.y * P) % MOD;
	
	return (int)code;
}

bool exist(point A)
{
	vector <point> :: iterator it;
	int where = hash(A);
	
	for (it = H[where].begin(); it != H[where].end(); it ++)
		if (it -> x == A.x && it -> y == A.y)
			return 1;
	return 0;
}

void add(point A)
{
	if (exist(A))
		return ;
	
	int where = hash(A);
	
	H[where].push_back(A);
	sol[++ cntSol] = A;
}

void load(int N)
{
	int i;
	
	for (i = 1; i <= N; i ++)
		H[hash(x[i])].push_back(x[i]);
}

void solve(int left, int right)
{
	if (left >= right)
		return ;
	
	int med = (left + right) / 2, i;
	
	for (i = left; i <= right; i ++)
	{
		point tmp; 
		
		tmp.x = x[med].x; tmp.y = x[i].y;
		add(tmp);
	}
	
	solve(left, med - 1);
	solve(med + 1, right);
}

int main()
{
	int i, N, M;
	
	freopen("arbsat2.in", "r", stdin);
	freopen("arbsat2.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
		scanf("%d%d", &x[i].x, &x[i].y);
	
	sort(x + 1, x + N + 1, comp);
	load(N);
	solve(1, N);
	
	printf("%d\n", cntSol);
	for (i = 1; i <= cntSol; i ++)
		printf("%d %d\n", sol[i].x, sol[i].y);
	return 0;
}
