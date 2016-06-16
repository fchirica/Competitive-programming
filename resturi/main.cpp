#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int r[35], p[35], M[1024], X[1024], tmp[1024];
 
void rev(int x[])
{
    int st = 1, dr = x[0], tmp;
 
    while (st <= dr)
    {
        tmp = x[st];
        x[st] = x[dr];
        x[dr] = tmp;
        st ++;
        dr --;
    }
}
 
int getRem(int x[], int MOD)
{
    int rest = 0, i;
 
    for (i = 1; i <= x[0]; i ++)
        rest = (rest * 10 + x[i]) % MOD;
 
    return rest;
}
 
void copy(int x[], int y[])
{
    int i;
 
    for (i = x[0]; i >= 0; i --)
        x[i] = 0;
 
    x[0] = y[0];
    for (i = 1; i <= x[0]; i ++)
        x[i] = y[i];
}
 
void inm(int x[], int fact)
{
    rev(x);
    if (fact == 0)
    {
        int i;
        for (i = x[0]; i >= 1; i --)
            x[i] = 0;
        x[0] = 1;
        return ;
    }
 
    int i, tr = 0;
 
    for (i = 1; i <= x[0]; i ++)
    {
        x[i] = x[i] * fact + tr;
        tr = x[i] / 10;
        x[i] = x[i] % 10;
    }
 
    while (tr)
    {
        x[++ x[0]] = tr % 10;
        tr = tr / 10;
    }
 
    rev(x);
}
 
void baga(int x[], int y[])
{
    rev(x); rev(y);
 
    int i, tr = 0;
 
    if (y[0] > x[0])
        x[0] = y[0];
    for (i = 1; i <= x[0]; i ++)
    {
        x[i] += y[i] + tr;
        tr = x[i] / 10;
        x[i] = x[i] % 10;
    }
 
    if (tr)
        x[++ x[0]] = 1;
    rev(x);
}
 
void solve(int N)
{
    int i;
 
    for (i = M[0]; i >= 0; i --)
        M[i] = 0;
    M[0] = M[1] = 1;
    for (i = X[0]; i >= 0; i --)
        X[i] = 0;
 
    do
    {
        X[++ X[0]] = r[1] % 10;
        r[1] = r[1] / 10;
    }
    while (r[1]);
    rev(X);
 
    for (i = 2; i <= N; i ++)
    {
        int rest = r[i] - getRem(X, p[i]);
        while (rest < 0)
            rest += p[i];
 
        inm(M, p[i - 1]);
        int A = getRem(M, p[i]);
 
        int res;
        for (res = 0; res < p[i]; res ++)
            if (res * A % p[i] == rest)
                break;
 
        copy(tmp, M);
        inm(tmp, res);
        baga(X, tmp);
    }
 
    for (i = 1; i <= X[0]; i ++)
        printf("%d", X[i]);
    printf("\n");
}
 
void solveNull(int N)
{
    printf("0\n");
}
 
int main()
{
    int i, j, N, T;
 
    freopen("resturi.in", "r", stdin);
    freopen("resturi.out", "w", stdout);
 
    scanf("%d", &T);
    for (i = 1; i <= T; i ++)
    {
        int tot = 0;
 
        scanf("%d", &N);
        for (j = 1; j <= N; j ++)
        {
            scanf("%d%d", &p[j], &r[j]);
            tot += r[j];
        }
 
        if (tot > 0)
            solve(N);
        else
            solveNull(N);
    }
 
    return 0;
}
