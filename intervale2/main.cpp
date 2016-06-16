#include <stdio.h>
#include <algorithm>
#define NMAX 100100

using namespace std;

int x[NMAX], X[NMAX], sol[NMAX], AIB[NMAX];

struct query
{
	int left, right;
} P[NMAX];

inline int lsb(int X)
{
	return X & -X;
}

void Norm(int N)
{
	int i, st, dr, med;

	for (i = 1; i <= N; i ++)
		X[i] = x[i];
	sort (X + 1, X + N + 1);
	
	for (i = 1; i <= N; i ++)
	{
		st = 1; dr = N;
		
		while (st <= dr)
		{
			med = (st + dr) / 2;
			if (X[med] == x[i])
			{
				x[i] = med;
				break;
			}
			if (X[med] < x[i])
				st = med + 1;
			else
				dr = med - 1;
		}
	}
}

inline int comp(query A, query B)
{
	return x[A.right] < x[B.right];
}

int Query(int X)
{
	int sol = 0;
	
	while (X)
	{
		sol += AIB[X];
		X = X - lsb(X);
	}
	
	return sol;
}

void update(int X, int N)
{
	int i;
	
	for (i = X; i <= N; i = i + lsb(i))
		AIB[i] ++;
}

int main()
{
	int i, N;
	
	freopen("intervale2.in", "r", stdin);
	freopen("intervale2.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	
	Norm(N);
	
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &P[i].left);
		P[i].right = i;
	}
	
	sort(P + 1, P + N + 1, comp);
	
	for (i = 1; i <= N; i ++)
	{
		sol[P[i].right] = P[i].right - P[i].left - (Query(P[i].right) - Query(P[i].left - 1));
		update(P[i].right, N);
	}
	
	for (i = 1; i <= N; i ++)
		printf("%d ", sol[i]);
	
	return 0;
}
