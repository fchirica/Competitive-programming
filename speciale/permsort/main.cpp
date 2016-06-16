#include <stdio.h>
#define DIM 8192

int poz, x[1000100], pos[1000100];
int AIB[2 * 1000100];
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

inline int lsb(int X)
{
	return X & -X;
}

inline int query(int X)
{
	int tot = 0;
	
	while (X > 0)
		tot += AIB[X], X = X - lsb(X);
	
	return tot;
}

inline void update(int X, int N)
{
	for (; X <= N; X = X + lsb(X))
		AIB[X] ++;
}

int main()
{
	int i, N;
	
	freopen("permsort.in", "r", stdin);
	freopen("permsort.out", "w", stdout);

	read(N);
	for (i = 1; i <= N; i ++)
	{
		read(x[i]);
		pos[x[i]] = i;
	}
	
	long long sol = 0;
	
	for (i = 1; i <= N; i ++)
	{
		int dist, where = pos[i];
		
		dist = pos[i] - pos[i - 1];
		if (dist < 0)
			dist += N, where += N;
		
		dist = dist - query(where - 1) + query(pos[i - 1]);
		sol += dist;
		
		update(pos[i], 2 * N); update(pos[i] + N, 2 * N);
	}
	
	printf("%lld", sol);
	return 0;
}
