#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LMAX 500500

using namespace std;

char x[LMAX];
int A[200], B[200];

int main ()
{
    int i, j, N;

    freopen ("palalila2.in", "r", stdin);
    freopen ("palalila2.out", "w", stdout);

    gets (x + 1);
    N = strlen (x + 1);

    for (i = 'A'; i <= 'z'; i ++)
        B[i] = - (1 << 30);
    for (i = 1; i <= N; i ++)
    {
        for (j = 'A'; j < x[i]; j ++)
            A[x[i]] = max (A[x[i]], B[j] + 1);
        for (j = x[i] + 1; j <= 'z'; j ++)
            B[x[i]] = max (B[x[i]], A[j] + 1);
    }

    int sol = 0;
    for (i = 'A'; i <= 'z'; i ++)
        if (A[i] > sol || B[i] > sol)
            sol = max (A[i], B[i]);
    printf ("%d", sol);
    return 0;
}

