#include <stdio.h>
#include <vector>

using namespace std;

int x[50500], num[50500], L[50500];

vector <int> last[50500];

int main ()
{
    int i, N, X, first, R;
    vector <int> :: iterator it;

    freopen ("progresii.in", "r", stdin);
    freopen ("progresii.out", "w", stdout);

    scanf ("%d%d", &N, &X);
    for (i = 1; i <= N; i ++)
    {
        scanf ("%d%d", &first, &R);
        if (R)
            for (first = first + R; first <= X; first += R)
                last[first].push_back (first - R);
    }

    num[0] = 1; L[0] = 1;
    for (i = 1; i <= X; i ++)
        for (it = last[i].begin (); it != last[i].end (); it ++)
        {
            num[i] = num[i] + num[*it];
            if (num[*it])
                L[i] = max (L[i], L[*it] + 1);
        }

    printf ("%d %d", num[X], L[X]);
    return 0;
}


