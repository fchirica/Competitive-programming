#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 8192

int x[600000];
int sol[600000];
char buff[DIM];
int poz = 0;

void swap(int &A, int &B)
{
	A = A ^ B;
	B = A ^ B;
	A = A ^ B;
}

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
 
int main()
{
	int i, N;
	long long sum = 0;
	
	freopen("congr.in", "r", stdin);
	freopen("congr.out", "w", stdout);

	srand(time(NULL));

	read(N);
	for (i = 1; i <= 2 * N; i ++)
	{
		read(x[i]);
		if (i <= N)
			sum += x[i];
		sol[i] = i;
	}
	
	while (sum % N)
	{
		int ind1 = 1 + rand() % N;
		int ind2 = N + rand() % N;
		
		if (ind2 == N)
			ind2 ++;
		sum = sum - x[ind1] + x[ind2];
		swap(x[ind1], x[ind2]);
		swap(sol[ind1], sol[ind2]);
	}
	
	for (i = 1; i <= N; i ++)
		printf("%d ", sol[i]);
	return 0;
}
