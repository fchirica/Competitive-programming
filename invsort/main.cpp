#include <stdio.h>
#include <algorithm>
#define NMAX 33000

using namespace std;

int x[NMAX], bit[NMAX], pos[NMAX];

inline int comp(int A, int B)
{
	if (x[A] == x[B])
		return A < B;
	return x[A] < x[B];
}

void reverse(int st, int dr)
{
	int aux;
	
	printf("%d %d\n", st, dr);
	
	while (st <= dr)
	{
		aux = x[st]; 
		x[st] = x[dr];
		x[dr] = aux;
		aux = bit[st];
		bit[st] = bit[dr];
		bit[dr] = aux;
		st ++; 
		dr --;
	}
}

void divide(int st, int dr)
{
	if (st >= dr)
		return ;
	
	int i, j, med = (st + dr) / 2;
	
	divide(st, med);
	divide(med + 1, dr);
	
	for (i = med; i >= st; i --)
		if (bit[i] == 0)
			break;
	for (j = med + 1; j <= dr; j ++)
		if (bit[j] == 1)
			break;
	
	i ++; j --;
	if (i < j)
		reverse(i, j);
}

void solve(int st, int dr)
{
	int i, med, pivot;
	
	if (st >= dr)
		return ;
	
	med = (st + dr) / 2; pivot = x[med];
	for (i = st; i <= dr; i ++)
		if (x[i] < pivot)
			bit[i] = 0;
		else
			bit[i] = 1;
	
	divide(st, dr);
	
	for (i = st; i <= dr; i ++)
		if (x[i] == pivot)
			break;
		
	solve(st, i - 1);
	solve(i + 1, dr);
}

int main()
{
	int i, N;
	
	freopen("invsort.in", "r", stdin);
	freopen("invsort.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		pos[i] = i;
	}
	
	sort(pos + 1, pos + N + 1, comp);
	for (i = 1; i <= N; i ++)
		x[pos[i]] = i;
	
	solve(1, N);
	return 0;
}
