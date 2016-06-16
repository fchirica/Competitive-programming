#include <stdio.h>
#define NMAX 100100

struct point
{
    int x, y;
} x[NMAX];

inline int gcd(int A, int B)
{
    int r;

    while (B)
    {
        r = A % B;
        A = B;
        B = r;
    }

    return A;
}

inline int ab(int X)
{
    if (X < 0)
        return X * (-1);
    return X;
}

inline int computeGcd(int i)
{
    int X = ab(x[i].x - x[i + 1].x), Y = ab(x[i].y - x[i + 1].y);

    return gcd(X, Y);
}

int main()
{
    int i, N;
    long long area = 0, interior = 0, sol;

    freopen("copaci.in", "r", stdin);
    freopen("copaci.out", "w", stdout);

    scanf("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf("%d%d", &x[i].x, &x[i].y);

    x[N + 1] = x[1];
    for (i = 1; i <= N; i ++)
        area += (long long)x[i].x * x[i + 1].y - (long long)x[i].y * x[i + 1].x;
    area = area / 2;
    if (area < 0)
        area = area * (-1);

    for (i = 1; i <= N; i ++)
        interior += computeGcd(i);

    interior = interior / 2;
    sol = area - interior + 1;

    printf("%lld", sol);
    return 0;
}

