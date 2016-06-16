#include <stdio.h>
#define LMAX 100100

int x[LMAX];
bool used[LMAX];

inline int gcd (int a, int b)
{
    int r;

    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main ()
{
    int N, i, j, len, ans = 1;

    freopen ("perm2.in", "r", stdin);
    freopen ("perm2.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf  ("%d", &x[i]);

    for (i = 1; i <= N; i ++)
        if (!used[i])
        {
            used[i] = 1;
            len = 1;
            for (j = x[i]; !used[j]; j = x[j])
            {
                len ++;
                used[j] = 1;
            }
            ans = (long long)ans * len / gcd (ans, len);
        }

    printf ("%d", ans);
    return 0;
}
