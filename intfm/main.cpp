#include <stdio.h>
#include <algorithm>
#define NMAX 1 << 11

using namespace std;

struct interval
{
    int x, y;
} x[NMAX];
int sol[NMAX], dp[NMAX];

inline bool comp (interval A, interval B)
{
    return A.y < B.y;
}

void RunDP (int inter)
{
    int lower = (x[inter].y - x[inter].x) / 5 * 2 + x[inter].x, upper = (x[inter].y - x[inter].x) / 5 * 3 + x[inter].x, n = 0, i, left, right, last, med;
    int first[NMAX], second[NMAX], D[NMAX];

    for (i = 1; i <= inter; i ++)
        if (lower <= x[i].x && x[i].y <= upper)
            first[++ n] = x[i].x, second[n] = x[i].y, D[n] = 0;

    D[0] = 0;
    for (i = 1; i <= n; i ++)
    {
        left = 1; right = i; last = 0;
        while (left <= right)
        {
            med = (left + right) / 2;
            if (second[med] <= x[inter].x)
                last = med, left = med + 1;
            else
                right = med - 1;
        }
        D[i] = max (D[i - 1], D[last] + dp[i] + 1);
    }

    dp[inter] = D[n];
}

int main ()
{
    int N, i, j;

    freopen ("intfm.in", "r", stdin);
    freopen ("intfm.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf ("%d%d", &x[i].x, &x[i].y);

    sort (x + 1, x + N + 1, comp);
    for (i = 1; i <= N; i ++)
    {
        RunDP (i);
        for (j = i - 1; j > 0; j --)
            if (x[j].y <= x[i].x)
                break;
        sol[i] = max (sol[i - 1], sol[j] + dp[i] + 1);
    }

    printf ("%d", sol[N]);
    return 0;
}
