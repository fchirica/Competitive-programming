#include <stdio.h>
#define DIM 8192

//parsare

char buff[DIM];
int poz;
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

//final parsare

int H[1 << 10];

void swap(int &A, int &B)
{
	int aux = A;
	A = B;
	B = aux;
}

void Add(int nod)
{
	H[++ H[0]] = nod;
	
	nod = H[0];
	while (nod > 1 && H[nod] < H[nod / 2])
	{
		swap(H[nod], H[nod / 2]);
		nod = nod / 2;
	}
}

void Del()
{
	swap(H[1], H[H[0]]); H[0] --;
	
	int node = 1, son;
	
	do
	{
		son = 0;
		if (2 * node <= H[0])
		{
			son = 2 * node;
			if (2 * node + 1 <= H[0] && H[2 * node + 1] < H[2 * node])
				son = 2 * node + 1;
		}
		if (H[son] > H[node])
			son = 0;
		if (son)
		{
			swap(H[son], H[node]);
			node = son;
		}
	}
	while (son);
}

long long getMax(long long X, long long Y)
{
	return X > Y ? X : Y;
}

int main()
{
	int i, j, N, K, now;
	long long sum = 0, sol = 0;
	
	freopen("bleach.in", "r", stdin);
	freopen("bleach.out", "w", stdout);
	
	read(N); read(K);
	for (i = 1; i <= N; i ++)
	{
		if (i == 1)
		{
			read(now); Add(now);
			for (j = 2; j <= K + 1; j ++)
			{
				read(now);
				Add(now);
			}
			now = H[1]; Del();
			sol = getMax(sol, now - sum);
			sum += now;
		}
		else
		if (i <= N - K)
		{
			read(now); Add(now);
			now = H[1]; Del();
			sol = getMax(sol, now - sum);
			sum += now;
		}
		else
		{
			now = H[1]; Del();
			sol = getMax(sol, now - sum);
			sum += now;
		}
	}
	
	printf("%lld", sol);
	return 0;
}
