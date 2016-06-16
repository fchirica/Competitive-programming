#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NMax 1510
#define EPS 1e-2

typedef struct { double x, y; } point;

int N;
point P[NMax];

int nr = 0;

int eq(double x, double y)
{ return fabs(x-y) < EPS; }

double less(double x, double y)
{ return x < y-EPS; }

double less_eq(double x, double y)
{ return x <= y-EPS; }

int cmp(const void *a, const void *b)
{
    point * A = ( point * ) a, * B = ( point * )b;

    if (less(A->x, B->x)) return -1;
    if (less(B->x, A->x)) return +1;
    if (less(A->y, B->y)) return -1;
    if (less(B->y, A->y)) return +1;
    return 0;
}

int bs(double x, double y)
{
    int l, r, m;

    l = 1; r = N;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (P[m].x < x - EPS || (eq(P[m].x, x) && P[m].y < y - EPS))
            l = m+1; // <
        else if (P[m].x > x + EPS || (eq(P[m].x, x) && P[m].y > y + EPS))
            r = m-1; // >
        else return m;
    }

    return 0;
}

point simetric(double x, double y, double A, double B, double C) // ???
{
    double A1 = B, B1 = -A, C1 = A * y - B * x, mx, my;
    point sp;

    mx = (B * C1 - B1 * C) / (A * B1 - A1 * B);
    my = (A1 * C - A * C1) / (A * B1 - A1 * B);
    sp.x = x + (mx-x) * 2.0;
    sp.y = y + (my-y) * 2.0;

    return sp;
}

int uz[NMax];

int all_right(double A, double B, double C)
{
    int i, ok;
    point sp;

    for (i = 1; i <= N; i++) uz[i] = 0;

    for (i = 1; i <= N; i++)
        if (!uz[i])
        {
            if (eq(A * P[i].x + B * P[i].y + C, 0.0)) continue;

            sp = simetric(P[i].x, P[i].y, A, B, C);

            ok = bs(sp.x, sp.y);
            if (!ok)
                return 0;
            uz[ok] = 1;
        }
    return 1;
}

int main(void)
{
    int i, j;
    double x, y, A, B, C, a, b, c, GX = 0, GY = 0;

    freopen("dmg.in", "r", stdin);
    freopen("dmg.out", "w", stdout);

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf", &x, &y);
        P[i].x = x; P[i].y = y;
        GX += x; GY += y;
    }
    qsort(P, N, sizeof(point), cmp);
    for (i = N; i >= 1; i--) P[i] = P[i-1];
    //P[i].x = P[i].y = 0;

    printf("          \n");

    GX /= N; GY /= N;
    A = P[1].y-GY; B = GX-P[1].x; C = P[1].x*GY - GX*P[1].y;
    if (all_right(A, B, C))
    {
        nr++;
        printf("%.8lf %.8lf %.8lf\n", A, B, C);
    }


    for (i = 2; i <= N; i++)
    {
        A = P[1].y-P[i].y; B = P[i].x-P[1].x; C = P[1].x*P[i].y - P[i].x*P[1].y;
        if (all_right(A, B, C) && !eq(A * GX + B * GY + C, 0.0))
        {
            nr++;
            printf("%.8lf %.8lf %.8lf\n", A, B, C);
        }

        a = B; b = -A; c = A * (P[1].y+P[i].y) * 0.5 - B * (P[1].x+P[i].x) * 0.5;
        if (all_right(a, b, c))
        {
            nr++;
            printf("%.8lf %.8lf %.8lf\n", a, b, c);
        }

    }

    fseek(stdout, 0, SEEK_SET);
    printf("%d", nr);

    return 0;
}
