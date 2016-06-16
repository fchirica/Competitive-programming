#include <stdio.h>
#include <string.h>
#define LMAX 100100

char x[LMAX];
int count[LMAX];
bool brute[LMAX];

void RunBrute (int N)
{
    int sol = 0, okay, i;

    do
    {
        okay = 1; sol ++;
        for (i = 1; i < N; i ++)
            if (brute[i] == 1 && brute[i + 1] == 0)
                brute[i] = 0, brute[i + 1] = 1, i ++, okay = 0;
    }
    while (!okay);

    printf ("%d\n", sol - 1);
}

int main ()
{
    int Q, N, i, waited, pos, sol, now, between, killed;

    freopen ("soldati.in", "r", stdin);
    freopen ("soldati.out", "w", stdout);

    scanf ("%d\n", &Q);
    while (Q --)
    {
        gets (x + 1);
        N = strlen (x + 1);
        count[0] = 0;
        for (i = 1; i <= N; i ++)
        {
            count[i] = count[i - 1] + (x[i] == '>' ? 1 : 0);
            brute[i] = (x[i] == '>' ? 1 : 0);
        }
        /*if (N < 1000)
        {
            RunBrute (N);
            continue;
        } */
        sol = pos = killed = 0;
        waited = -1;
        for (i = 1; i <= N; i ++)
            if (x[i] == '<')
            {
                now = count[i];
                if (now == 0)
                    continue;
                between = count[i - 1] - count[pos];
                if (between > waited)
                    waited = 0, killed = 0;
                else
                    waited ++, killed += count[i - 1] - count[pos], now -= killed;
                now += waited;
                if (now < count[i])
                    now = count[i], killed = 0, waited = 0;
                if (now > sol)
                    sol = now;
                pos = i;

            }
        printf ("%d\n", sol);
    }

    return 0;
}
