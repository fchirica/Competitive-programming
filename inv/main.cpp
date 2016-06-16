#include <stdio.h>
#include <algorithm>

using namespace std;

int x[100100], zero[100100], AIB[100100];

void Preprocess (int N)
{
    int i, pow = 1;

    zero[1] = 1;
    for (i = 2; i <= N; i ++)
        if (pow * 2 == i)
            pow = pow * 2, zero[i] = i;
        else
            zero[i] = zero[i - pow];
}

void AddAIB (int val, int N)
{
    while (val <= N)
    {
        AIB[val] ++;
        val = val + zero[val];
    }

}

int QueryAIB (int val)
{
    int ans = 0;

    while (val)
    {
        ans = ans + AIB[val];
        val = val - zero[val];
    }

    return ans;
}

void Normalizare (int N)
{
    int now[100100], i, left, right, med;

    for (i = 1; i <= N; i ++)
        now[i] = x[i];
    sort (now + 1, now + N + 1);

    for (i = 1; i <= N; i ++)
    {
        left = 1; right = N;

        while (left <= right)
        {
            med = (left + right) / 2;
            if (now[med] < x[i])
                left = med + 1;
            else
                right = med - 1;
        }

        x[i] = left;
    }
}

void RunSlow (int N)
{
    int i, j, sol = 0;

    for (i = 1; i < N; i ++)
        for (j = i + 1; j <= N; j ++)
            if (x[i] > x[j])
                sol ++;

    printf ("EXPECTED: %d\n", sol);
}

void Solve (int N)
{
    int i, sol = 0;

    for (i = N; i >= 1; i -- )
    {
        sol = sol + QueryAIB (x[i] - 1);
        sol = sol % 9917;
        AddAIB (x[i], N);
    }

    printf ("%d", sol);
}

int main ()
{
    int i, N;

    freopen ("inv.in", "r", stdin);
    freopen ("inv.out", "w", stdout);

    scanf ("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf ("%d", &x[i]);

    //RunSlow (N);
    Normalizare (N);
    Preprocess (N);
    Solve (N);

    return 0;
}

