#include <stdio.h>
#define MOD 10007
#define NMAX 100100

bool visible[NMAX];

int main()
{
    int i, x, N, K, sol = 1;

    freopen("pviz.in", "r", stdin); //grigo = wefgef?!
    freopen("pviz.out", "w", stdout);

    scanf("%d%d", &N, &K);
    for (i = 1; i <= K; i ++)
    {
        scanf("%d", &x);
        visible[x] = 1;
    }

    for (i = 1; i <= N; i ++)
        if (!visible[i])
            sol = (long long)sol * (i - 1) % MOD;

    printf("%d", sol);
    return 0;
}
