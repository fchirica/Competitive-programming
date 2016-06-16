//Bag euristici la greu

#include <stdio.h>
#define DIM 8192

int x[512], y[512];
int x0[200100], y0[200100], t[200100];

char buff[DIM];
int poz = 0;

void read (int &numar)
{
    numar = 0; 
	int semn = 1;
    while (buff[poz] < '0' || buff[poz] > '9')     
	{
		if (buff[poz] == '-')
			semn = -1;
        if (++poz == DIM) 
            fread(buff,1,DIM,stdin),poz=0;
	}
	
    while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar = numar*10 + buff[poz] - '0';
        if (++poz == DIM) 
            fread(buff,1,DIM,stdin),poz=0;               
    }     
	
	numar = numar * semn;
}

void solveBrute(int N, int M)
{
	int i, j;
	
	for (i = 1; i <= M; i ++)
	{
		int sol = 0;
		
		for (j = 1; j <= N; j ++)
		{
			long long cur = x[j] + 1LL * t[i] * y[j];
			if (x0[i] <= cur && cur <= y0[i])
				++ sol;
		}
		printf("%d\n", sol);
	}
}

int main()
{
	int i, N, M, tmax = -1;
	
	freopen("kinetic.in", "r", stdin);
	freopen("kinetic.out", "w", stdout);
	
	read(N); read(M);
	for (i = 1; i <= N; i ++)
	{
		read(x[i]); read(y[i]);
	}
	
	for (i = 1; i <= M; i ++)
	{
		read(x0[i]); read(y0[i]); read(t[i]);
		if (x0[i] > y0[i])
		{
			int aux = x0[i];
			x0[i] = y0[i];
			y0[i] = aux;
		}
		
		if (t[i] > tmax)
			tmax = t[i];
	}
	
	solveBrute(N, M);
	
	return 0;
}
