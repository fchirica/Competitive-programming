#include <stdio.h>

int main()
{
    int i;
    long long where, N, now, ret, M;

    freopen("farfurii.in", "r", stdin);
    freopen("farfurii.out", "w", stdout);

    scanf("%lld%lld", &N, &M);

    for (where = 1; where * (where - 1) / 2 < M; ++ where);

    for (i = 1; i <= N - where; i ++)
        printf("%d ", i);

    now = N - where + 1 + M - (where - 1) * (where - 2) / 2;
    printf("%d ", now);
    where = N - where;

    ret = N + 1;
    for (i = where + 2; i <= N; i ++)
    {
        ret --;
        if (ret == now)
            ret --;
        printf("%d ", ret);
    }

    return 0;
}
