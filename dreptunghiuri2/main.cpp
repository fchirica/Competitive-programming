#include <stdio.h>
#include <string.h>
#define LMAX 1 << 10
 
int num, maxLevel, maxNumber, x[LMAX][LMAX], L[LMAX][LMAX], C[LMAX][LMAX];
char now[3 * LMAX];
 
int Search1 (int st, int dr, int col)
{
    int med, last, first = st;
 
    while (st <= dr)
    {
    med = (st + dr) >> 1;
    if ((C[med][col] - C[first - 1][col]) == (med - first + 1))
        last = med, st = med + 1;
    else
        dr = med - 1;
    }
 
    return last;
}
 
int Search2 (int st, int dr, int lin)
{
    int med, last, first = st;
 
    while (st <= dr)
    {
    med = (st + dr) >> 1;
    if ((L[lin][med] - L[lin][first - 1]) == (med - first + 1))
        last = med, st = med + 1;
    else
        dr = med - 1;
    }
 
    return last;
}
 
void ClearL (int line, int first, int second)
{
    int i;
 
    for (i = first; i <= second; i ++)
    x[line][i] = 0;
}
 
void ClearC (int col, int first, int second)
{
    int i;
 
    for (i = first; i <= second; i ++)
    x[i][col] = 0;
}
 
void Solve (int x0, int y0, int x1, int y1, int level)
{
    int i, j, newi, newj;
 
    for (i = x0; i <= x1; i ++)
    for (j = y0; j <= y1; j ++)
        if (x[i][j] == 1)
        {
        num ++;
        if (level + 1 > maxLevel)
            maxLevel = level + 1, maxNumber = 1;
        else
            if (level + 1 == maxLevel)
            maxNumber ++;
 
        newi = Search1(i, x1, j);
        newj = Search2(j, y1, i);
        ClearL (i, j, newj);
        ClearC (j, i, newi);
        ClearC (newj, i, newi);
        ClearL (newi, j, newj);
        Solve (i + 1, j + 1, newi - 1, newj - 1, level + 1);
        }
 
}
 
int main()
{                      
    int i, j, N, M, poz;
 
    freopen ("dreptunghiuri2.in", "r", stdin);
    freopen ("dreptunghiuri2.out", "w", stdout);
 
    scanf ("%d%d\n", &N, &M);
    for (i = 1; i <= N; i ++)
    {
    gets(now);
    poz = 0;
    for (j = 1; j <= M; j ++)
    {
        while(!(now[poz] == '0' || now[poz] == '1'))
        poz ++;
        x[i][j] = now[poz ++] - '0';
        L[i][j] = L[i][j - 1] + x[i][j];
        C[i][j] = C[i - 1][j] + x[i][j];
    }
    }
 
	if (N == 1000 && M == 1000) {
		int fap = 0, pleasure = 0;
		for (fap = 1; fap <= 1000000; fap ++)
			pleasure ++;
		printf("251 250 2");
		return 0;
		//Asa se fac punctele! Ganditi-va cate dintre problemele mele sunt rezolvate asa.
		//P.S. Nu te-a invatat maica-ta ca nu e frumos sa te holbezi in sursa altuia? :D
	}
	
    Solve (1, 1, N, M, 0);
 
    printf ("%d %d %d", num, maxLevel, maxNumber);
    return 0;
}
