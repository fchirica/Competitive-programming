//O(N * logN) cu AIB

#include <stdio.h>
#include <algorithm>
#define NMAX 100100

using namespace std;

int x[NMAX], pos[NMAX], AIB[NMAX];

inline bool comp(int A, int B)
{
	return x[A] < x[B];
}

inline int lsb(int X)
{
	return X & -X;
}

inline int query(int X)
{
	int i, sol = 0;
	
	for (i = X; i >= 1; i = i - lsb(i))
		sol += AIB[i];
	
	return sol;
}

inline void update(int X, int N)
{
	int i;
	
	for (i = X; i <= N; i = i + lsb(i))
		AIB[i] ++;
}

int main()
{
	int i, N;
	long long sol = 0, now;
	
	freopen("costperm.in", "r", stdin);
	freopen("costperm.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		pos[i] = i;
	}
	
	sort(pos + 1, pos + N + 1, comp);
	for (i = 1; i <= N; i ++)
	{
		now = pos[i] - 1;
		now = now - query(pos[i] - 1);
		now = now * i;
		
		update(pos[i], N);
		sol = sol + now;
	}
	
	printf("%lld", sol);
	return 0;
}
