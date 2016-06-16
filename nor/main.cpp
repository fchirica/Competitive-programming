#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#define NMAX 15100

using namespace std;

int dad[NMAX], R[NMAX];

inline bool comp (int a, int b)
{
    return a > b;
}

inline int getFather (int root)
{
    int node = root;

    while (root != dad[root])
        root = dad[root];
    while (node != root)
        dad[node] = root, node = dad[node];

    return root;
}

int main ()
{
    int N, M, i, x, y, sum = 0, n, j;

    freopen ("nor.in", "r", stdin);
    freopen ("nor.out", "w", stdout);

    scanf ("%d%d", &N, &M);

    for (i = 1; i <= N; i ++)
        dad[i] = i, R[i] = 1;
    for (i = 1; i <= M; i ++)
    {
        scanf ("%d%d", &x, &y);
        x = getFather (x);
        y = getFather (y);
        if (x == y)
            continue;
        if (R[x] < R[y])
        {
            R[y] = R[y] + R[x];
            R[x] = 0;
            dad[x] = y;
        }
        else
        {
            R[x] = R[x] + R[y];
            R[y] = 0;
            dad[y] = x;
        }
    }

    vector <int> clouds;
    for (i = 1; i <= N; i ++)
        if (R[i] > 2)
            clouds.push_back (R[i]);
    sort (clouds.begin (), clouds.end (), comp);
    n = clouds.size ();

    for (i = 0, N = N / 2; i < n && sum <= N; sum = sum + clouds[i], i ++);
    if (i == n && sum <= N)
    {
        printf ("0\n\n");
        return 0;
    }
    else
    {
        printf ("%d\n", i);
        for (j = 0; j < i; j ++)
            printf ("%d ", clouds[j]);
    }

    return 0;
}
