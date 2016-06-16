#include <stdio.h>
#include <string.h>
#include <algorithm>
#define NMAX 25100

using namespace std;

char x[NMAX][112];
int ind[NMAX];

inline bool comp(int A, int B)
{
	int val = strcmp(x[A], x[B]);
	
	if (val < 0)
		return 1;
	return 0;
}

inline int addTrie(int X)
{
	int ind1 = ind[X - 1], ind2 = ind[X], i, num = 0, n1 = strlen(x[ind1]), n2 = strlen(x[ind2]);
	
	for (i = 0; i < n1 && i < n2; i ++)
	{
		if (x[ind1][i] != x[ind2][i])
			break;
		num ++;
	}
	
	return n2 - num;
}

int main()
{
	int i, N, sol = 0;
	
	freopen("dictree.in", "r", stdin);
	freopen("dictree.out", "w", stdout);
	
	scanf("%d\n", &N);
	for (i = 1; i <= N; i ++)
	{
		gets(x[i]);
		ind[i] = i;
	}
	
	sort(ind + 1, ind + N + 1, comp);
	for (i = 1; i <= N; i ++)
		sol += addTrie(i);
	
	printf("%d", sol + 1);
	return 0;
}

