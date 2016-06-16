//Sursa mai veche, retrimisa ca sa apara punctele in cadrul grupului :D

#include <stdio.h>
#include <math.h>
#define LMAX 5100
#define VMAX 100100
#define DIM 16384

int N, x[LMAX], pz;
short D[VMAX];
char ax[DIM + 16];

inline void read(int &now) //parsare copiata de la Mircea Dima :)
{
    now = 0;
    while(ax[pz] < '0' || ax[pz] > '9' )
        if(++ pz == DIM)
            fread(ax, 1, DIM, stdin), pz = 0;
    while(ax[pz] >= '0' && ax[pz] <= '9')
    {
        now = now * 10 + ax[pz] - '0';
        if(++ pz == DIM)
            fread(ax, 1, DIM, stdin), pz = 0;
    }
}

void Clear()
{
    int i;

    for(i = 1; i <= N; i ++)
        D[x[i]] = 0;
}

int SolveIt(int R)
{
    int i, max = 1, last;

    Clear();
    for(i = 1; i <= N; i ++)
    {
        D[x[i]] = 1;
        if(x[i] % R == 0)
        {
            last = x[i] / R;
            if(D[last])
            {
                D[x[i]] = D[last] + 1;
                if(D[x[i]] > max)
                    max = D[x[i]];
            }
        }
    }

    return max;
}

bool Divisible(int max)
{
    int i, j;

    Clear();
    for(i = N; i >= 1; i --)
    {
        D[x[i]] = 1;
        for(j = (x[i] << 1); j <= max; j = j + x[i])
            if(D[j])
                return true;
    }

    return false;
}

int main()
{
    int T, i, R, max, bestSol, nowSol, root, now, min;

    freopen("subgeom.in", "r", stdin);
    freopen("subgeom.out", "w", stdout);

    scanf("%d", &T);
    while(T --)
    {
        read(N);
        max = -1;
        min = 1 << 30;
        for(i = 1; i <= N; i ++)
        {
            read(now);
            x[i] = now;
            if(x[i] > max)
                max = x[i];
            if(x[i] < min)
                min = x[i];
        }

        bestSol = 1;
        root = (int) sqrt(max / min);
        for(R = 2; R <= root; R ++)
        {
            nowSol = SolveIt(R);
            if(nowSol > bestSol)
                bestSol = nowSol;
        }

        if(bestSol == 1 && Divisible(max))
            bestSol = 2;

        Clear();
        printf("%d\n", bestSol);
    }

    return 0;
}
