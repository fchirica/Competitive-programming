#include <stdio.h>
#include <algorithm>
#define MMAX 20100
#define NMAX 1024
#define KMAX 50100

using namespace std;

struct edge
{
    int x, y, c;
} x[MMAX];

inline bool comp (edge A, edge B)
{
    return A.c < B.c;
}

int C[NMAX], R[NMAX], T[NMAX];
bool D[KMAX];

int father (int X)
{
    int root = X, aux;

    while (root != T[root])
        root = T[root];
    while (X != root)
    {
        aux = T[X];
        T[X] = root;
        X = aux;
    }

    return root;
}

void unite (int X, int Y)
{
    if (R[X] <= R[Y])
    {
        T[X] = Y;
        if (R[X] == R[Y])
            R[Y] ++;
    }
    else
        T[Y] = X;
}

int main ()
{
    int dadX, dadY, j, N, M, K, i, n = 0, sum = 0, last = 0, sol = 0;

    freopen ("retea.in", "r", stdin);
    freopen ("retea.out", "w", stdout);

    scanf ("%d%d%d", &N, &M, &K);
    for (i = 1; i <= M; i ++)
        scanf ("%d%d%d", &x[i].x, &x[i].y, &x[i].c);
    sort (x + 1, x + M + 1, comp);

    for (i = 1; i <= N; i ++)
        T[i] = i, R[i] = 1;
    for (i = 1; i <= M; i ++)
    {
        dadX = father (x[i].x);
        dadY = father (x[i].y);
        if (dadX == dadY)
            continue;
        unite (dadX, dadY);
        C[++ n] = x[i].c;
    }

    D[0] = 1;
    for (i = 1; i < N; i ++)
    {
        for (j = last; j >= 0; j --)
            if (D[j] && j + C[i] <= K)
                D[j + C[i]] = 1;
        last = last + C[i];
        if (last > K)
            last = K;
    }

    for (i = 1; i < N; i ++)
        sum = sum + C[i];
    for (i = 0; i <= K; i ++)
        if (D[i])
            sol ++;
    printf ("%d %d", sum, sol);
    return 0;
}
