#include <stdio.h>
#include <string.h>
#define NMAX (1 << 10)
#define DIM 6900

int poz, N, M, numSol;
int minL[NMAX][NMAX], maxL[NMAX][NMAX], minQ[NMAX], maxQ[NMAX], x[NMAX][NMAX];
char buff[DIM];

void read(int &numar)
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

int solve(int l, int L)
{
	int i, j, pmin, pmax, umin, umax, best = 1 << 30, nowMin, nowMax;
	
	numSol = 0;
	pmin = pmax = 1; umin = umax = 0;
	memset(minQ, 0, sizeof(minQ));
	memset(maxQ, 0, sizeof(maxQ));
	
	for (j = 1; j <= M; j ++)
	{
		for (i = 1; i <= N; i ++)
		{
			while (pmin <= umin && x[i][j] <= x[minQ[umin]][j])
				umin --;
			minQ[++ umin] = i;
			if (minQ[pmin] + l == i)
				pmin ++;
			minL[i][j] = x[minQ[pmin]][j];
		}
		
		pmin = 1; umin = 0;
	}
	
	for (j = 1; j <= M; j ++)
	{
		for (i = 1; i <= N; i ++)
		{
			while (pmax <= umax && x[i][j] >= x[maxQ[umax]][j])
				umax --;
			maxQ[++ umax] = i;
			if (maxQ[pmax] + l == i)
				pmax ++;
			maxL[i][j] = x[maxQ[pmax]][j];
		}
		
		pmax = 1; umax = 0;
	}
	
	for (i = l; i <= N; i ++)
	{
		for (j = 1; j <= M; j ++)
		{
			while (pmin <= umin && minL[i][j] <= minL[i][minQ[umin]])
				umin --;
			minQ[++ umin] = j;
			if (minQ[pmin] + L == j)
				pmin ++;
			nowMin = minL[i][minQ[pmin]];
			
			while (pmax <= umax && maxL[i][j] >= maxL[i][maxQ[umax]])
				umax --;
			maxQ[++ umax] = j;
			if (maxQ[pmax] + L == j)
				pmax ++;
			nowMax = maxL[i][maxQ[pmax]];
			
			if (j >= L)
			{
				if (nowMax - nowMin < best)
					best = nowMax - nowMin, numSol = 0;
				if (nowMax - nowMin == best)
					numSol ++;
			}
		}
		pmin = pmax = 1; umin = umax = 0;
	}	
	
	return best;
}

int main()
{
	int i, j, Q, L, l, sol, cntSol, now;
	
	freopen("struti.in", "r", stdin);
	freopen("struti.out", "w", stdout);
	
	read(N); read(M); read(Q);
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= M; j ++)
			read(x[i][j]);
	
	while (Q --)
	{
		read(l); read(L);
		
		sol = solve(L, l); cntSol = numSol;
		if (l != L)
		{
			now = solve(l, L);
			if (now < sol)
				sol = now, cntSol = numSol;
			else
			if (now == sol)
				cntSol += numSol;
		}
		
		printf("%d %d\n", sol, cntSol);
	}
	
	return 0;
}
