#include <stdio.h>
#define MOD 101267
 
int dp[2][1024], ret[1024];
int x[1024];
 
void baga(int &A, int B)
{
    A += B;
    if (A >= MOD)
        A = A - MOD;
}
 
bool match(int seq, int used)
{
    if (x[seq + 1] == x[used])
        return false;
     
    int i, lim = seq - used + 2;
    for (i = lim; i <= seq; i ++)
        if (x[i] != x[i - lim + 1])
            return false;
    return true;
}
 
int main()
{
    int i, j, k, N, L;
    char ch;
     
    freopen("interzis.in", "r", stdin);
    freopen("interzis.out", "w", stdout);
 
    scanf("%d%d\n", &N, &L);
    for (i = 1; i <= L; i ++)
    {
        scanf("%c", &ch);
        if (ch == 'b')
            x[i] = 1;
    }
 
    for (i = 1; i < L; i ++)
        for (j = i; j >= 1; j --)
            if (match(i, j))
            {
                ret[i] = j;
                break;
            }
     
    dp[0][0] = 1;
    for (i = 0; i < N; i ++)
    {
        for (k = 0; k < L; k ++)
        {
            baga(dp[(i + 1) & 1][k + 1], dp[i & 1][k]);
            baga(dp[(i + 1) & 1][ret[k]], dp[i & 1][k]);
        }
             
        for (j = 0; j < L; j ++)
            dp[i & 1][j] = 0;
    }
     
    int sol = 0;
    for (i = 0; i < L; i ++)
        baga(sol, dp[N & 1][i]);
     
    printf("%d", sol);
    return 0;
}
