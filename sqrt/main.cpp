#include <stdio.h>
#include <string.h>

short x[2100], X[2100], T[2100], sqX[2100], lastsq[2100];

void del(short plm[])
{
	int i;
	
	for (i = 1; i <= plm[0] + 50; i ++)
		plm[i] = 0;
	plm[0] = 0;
}

void copy(short plm1[], short plm2[])
{
	int i;
	
	plm1[0] = plm2[0];
	for (i = 1; i <= plm1[0] + 50; i ++)
		plm1[i] = plm2[i];
}

void reverse(short plm[])
{
	short st = 1, dr = plm[0], aux;
	
	while (st <= dr)
	{
		aux = plm[st];
		plm[st] = plm[dr];
		plm[dr] = aux;
		st ++;
		dr --;
	}
}

inline short max(short A, short B)
{
	return A > B ? A : B;
}

void baga(short last[]) //sqX = sqX + last
{
	sqX[0] = max(sqX[0], last[0]);
	
	short i, tr = 0;
	
	for (i = 1; i <= sqX[0]; i ++)
	{
		sqX[i] = sqX[i] + tr + last[i];
		tr = sqX[i] / 10;
		sqX[i] = sqX[i] % 10;
	}
	
	if (tr)
		sqX[++ sqX[0]] = 1;
}

void makeSquare(short c)
{
	reverse(sqX);
	
	short i, scalar = 20 * c, tr = 0;;
	short last[2100];
	copy(last, X);
	last[0] --;
	
	reverse(last);
	
	for (i = 1; i <= last[0]; i ++)
	{
		last[i] = last[i] * scalar + tr;
		tr = last[i] / 10;
		last[i] = last[i] % 10;
	}
	while (tr)
	{
		last[++ last[0]] = tr % 10;
		tr = tr / 10;
	}
	baga(last);
	del(last);
	c = c * c;
	do
	{
		last[++ last[0]] = c % 10;
		c = c / 10;
	}
	while (c);
	baga(last);
	
	reverse(sqX);
}

inline short comp()
{
	if (sqX[0] < T[0])
		return -1;
	if (sqX[0] > T[0])
		return 1;
	short i;
	
	for (i = 1; i <= sqX[0]; i ++)
	{
		if (sqX[i] < T[i])
			return -1;
		if (sqX[i] > T[i])
			return 1;
	}
	
	return 0;
}

int main()
{
	short c, N, aux, K, i, cn, nrc = 0;
	
	freopen("sqrt.in", "r", stdin);
	freopen("sqrt.out", "w", stdout);
	
	scanf("%d", &N); cn = N;
	while (N)
	{
		x[++ x[0]] = N % 10;
		N = N / 10;
		nrc ++;
	}
	
	short st = 1, dr = x[0];
	while (st <= dr)
	{
		aux = x[st];
		x[st] = x[dr];
		x[dr] = aux;
		st ++;
		dr --;
	}
	
	scanf("%d", &K);
	x[0] += 2 * K;
	
	if (nrc % 2)
		i = 1;
	else
		i = 2;
	for(; i <= x[0]; i += 2)
	{
		if (i == 1)
			T[++ T[0]] = x[i];
		else
		{
			T[++ T[0]] = x[i - 1];
			T[++ T[0]] = x[i];
		}
		X[0] ++;
		lastsq[0] += 2;
		if (lastsq[0] == 2)
			lastsq[0] = lastsq[0] - 2;
		
		st = 0; dr = 9;
		short lastc, value;
		
		while (st <= dr)
		{
			c = (st + dr) / 2;
			X[X[0]] = c;
			copy(sqX, lastsq);
			makeSquare(c);
			
			value = comp();
			if (value == 0)
			{
				lastc = c;
				break;
			}
			if (value == -1)
			{
				lastc = c;
				st = c + 1;
			}
			else
				dr = c - 1;
		}
		X[X[0]] = lastc;
		copy(sqX, lastsq);
		makeSquare(lastc);
		copy(lastsq, sqX);
	}
	
	for (i = (nrc + 1) / 2 + 1; i <= X[0]; i ++)
		printf("%d", X[i]);
	return 0;
}

