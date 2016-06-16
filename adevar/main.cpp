#include <stdio.h>
#include <vector>

using namespace std;

vector <int> good[25];
vector <int> bad[25];

int main ()
{
    int N, i, x, temp, j;
    vector <int> :: iterator it;
    bool ok, lier;

    freopen ("adevar.in", "r", stdin);
    freopen ("adevar.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
    {
        scanf ("%d", &x);
        for (j = 1; j <= x; j ++)
        {
            scanf ("%d", &temp);
            good[i].push_back (temp);
        }
        scanf ("%d", &x);
        for (j = 1; j <= x; j ++)
        {
            scanf ("%d", &temp);
            bad[i].push_back (temp);
        }
    }

    int conf[25], maxConf = (1 << N) - 1, mask;

    for (mask = 0; mask <= maxConf; mask ++)
    {
        for (i = 0; i < N; i ++)
            if (mask & (1 << i))
                conf[i + 1] = 0;
            else
                conf[i + 1] = 1;

        ok = true;
        for (i = 1; i <= N && ok; i ++)
            if (conf[i] == 0)
            {
                for (it = good[i].begin (); it != good[i].end (); it ++)
                    if (conf[*it] == 1)
                        ok = false;
                for (it = bad[i].begin (); it != bad[i].end (); it ++)
                    if (conf[*it] == 0)
                        ok = false;
            }
            else
            {
                lier = false;
                for (it = good[i].begin (); it != good[i].end (); it ++)
                    if (conf[*it] == 1)
                        lier = true;
                for (it = bad[i].begin (); it != bad[i].end (); it ++)
                    if (conf[*it] == 0)
                        lier = true;
                if (!lier)
                    ok = false;
            }

            if (!ok)
                continue;
            for (i = 1; i <= N; i ++)
                printf ("%d\n", conf[i]);
            return 0;
    }

    return 0;
}
