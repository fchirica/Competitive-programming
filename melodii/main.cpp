#include <stdio.h>
#include <algorithm>
#define QMAX 30100
#define NMAX 5000100
#define INF (1 << 30)

using namespace std;

struct query
{
    int N, K, P, order;
} x[QMAX];

int sol[QMAX];

inline bool comp (query A, query B)
{
    if (A.P == B.P)
        return A.N < B.N;
    return A.P < B.P;
}

int dp[NMAX], st[NMAX];

int main ()
{
    int i, Q, n0, n1, u, j;

    freopen ("otilia.in", "r", stdin);
    freopen ("otilia.out", "w", stdout);

    scanf ("%d", &Q);
    for (i = 1; i <= Q; i ++)
    {
        scanf ("%d%d%d", &x[i].N, &x[i].K, &x[i].P);
        x[i].order = i;
    }

    sort (x + 1, x + Q + 1, comp);

    for (i = 1; i <= Q; i ++)
    {
        if (x[i].P != x[i - 1].P)
            n0 = 1, n1 = x[i].N, u = 0;
        else
        {
            if (x[i].N == x[i - 1].N)
            {
                sol[x[i].order] = (dp[x[i].N] <= x[i].K) ? 1 : 0;
                continue;
            }
            n0 = x[i - 1].N + 1; n1 = x[i].N;
        }
        for (j = n0; j <= n1; j ++)
        {
            while (u > 0 && dp[st[u]] <= (j - st[u]) * x[i].P)
                u --;
            if (u == 0)
            {
                st[++ u] = j;
                dp[j] = INF;
                continue;
            }
            dp[j] = j - st[u];
            st[++ u] = j;
        }

        sol[x[i].order] = (dp[x[i].N] <= x[i].K) ? 1 : 0;
    }

    for (i = 1; i <= Q; i ++)
        printf ("%d\n", sol[i]);

    return 0;
}
