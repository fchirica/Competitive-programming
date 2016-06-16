#include <stdio.h>
#define LMAX (1 << 22)

int dp[LMAX], conf[30];

void getConf (int now)
{
    int i;

    for (i = 0; i < 22; i ++)
        if (now & (1 << i))
            conf[i] = 1;
        else
            conf[i] = 0;
}

int getNum ()
{
    int i, now;

    now = 0;
    for (i = 0; i < 22; i ++)
        if (conf[i])
            now = now + (1 << i);

    return now;
}

int getMoney (int now)
{
    int num = 0;

    while (now)
    {
        num ++;
        now = now & (now - 1);
    }

    return num;
}

int main ()
{
    int T, i, now, sol = 0, j, last;

    freopen ("coins.in", "r", stdin);
    freopen ("coins.out", "w", stdout);

    scanf ("%d", &T);

    now = 0;
    for (i = 0; i < 22; i ++)
    {
        now = now + (1 << i);
        dp[now] = 1;
    }

    for (i = 1; i < LMAX; i ++)
    {
        getConf (i);
        if (dp[i])
            continue;
        last = -1;
        for (j = 0; j < 22; j ++)
            if (conf[j] == 0)
                last = j;
            else
            {
                if (last == -1)
                    continue;
                now = i | (1 << last);
                now = now & (~ (1 << j));
                if (dp[now] == 0)
                    dp[i] = 1;
            }
    }

    while (T --)
    {
        for (i = 0; i < 22; i ++)
            scanf ("%d", &conf[i]);
        now = 0;
        for (i = 0; i < 22; i ++)
            if (conf[i])
                now = now + (1 << i);
        if (dp[now])
            sol = sol + getMoney (now);
    }

    printf ("%d", sol);
    return 0;
}

