#include <stdio.h>
#define NMAX 30100
#define DIM 8192

int poz;
int rank[NMAX], AIB[NMAX], sol[NMAX];
char buff[DIM];

void read (int &numar)
{
	numar = 0;
	while (buff[poz] < '0' || buff[poz] > '9')     
		if (++poz == DIM) 
			fread(buff,1,DIM,stdin),poz=0;
	while ('0'<=buff[poz] && buff[poz]<='9')
	{
		numar = numar*10 + buff[poz] - '0';
		if (++poz == DIM) 
			fread(buff,1,DIM,stdin),poz=0;               
	}     
}

inline int lsb(int x)
{
	return x & -x;
}

int query(int pos)
{
	int ans = 0;
	for (; pos > 0; pos = pos - lsb(pos))
		ans += AIB[pos];
	return ans;
}

void update(int pos, int N)
{
	for (; pos <= N; pos = pos + lsb(pos))
		AIB[pos] ++;
}

inline int countFree(int x)
{
	return x - query(x);
}

int binarySearch(int left, int right, int rank)
{
	int med;
	
	while (left <= right)
	{
		med = (left + right) / 2;

		if (countFree(med) < rank)
			left = med + 1;
		else
			right = med - 1;
	}
	
	return left;
}

int main()
{
	int i, N;
	
	freopen("schi.in", "r", stdin);
	freopen("schi.out", "w", stdout);
	
	read(N);
	for (i = 1; i <= N; i ++)
		read(rank[i]);
	
	for (i = N; i >= 1; i --)
	{
		int firstFree = binarySearch(1, N, rank[i]);
		sol[firstFree] = i;
		update(firstFree, N);
	}
	
	for (i = 1; i <= N; i ++)
		printf("%d\n", sol[i]);
	return 0;
}
