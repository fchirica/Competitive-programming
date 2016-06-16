#include <stdio.h>
#include <algorithm>
#define EPS 0.00000001

using namespace std;

struct punct
{
    double x, y;
} x[1024];

inline double ab(double X)
{
    if (X > 0)
        return X;
    return -X;
}

inline bool comp(punct A, punct B)
{
    if (ab(A.x - B.x) <= EPS)
        return A.y < B.y;
    return A.x < B.x;
}

bool is(punct A, int N)
{
    int st = 1, dr = N, med;

    while (st <= dr)
    {
        med = (st + dr) / 2;
        if (ab(x[med].x - A.x) <= EPS && ab(x[med].y - A.y) <= EPS)
            return true;
        if (comp(A, x[med]))
            dr = med - 1;
        else
            st = med + 1;
    }

    return false;
}

int main()
{
    int i, j, N;

    freopen("patrate3.in", "r", stdin);
    freopen("patrate3.out", "w", stdout);

    scanf("%d", &N);
    for (i = 1; i <= N; i ++)
        scanf("%lf%lf", &x[i].x, &x[i].y);
    sort(x + 1, x + N + 1, comp);

    int sol = 0;

    for (i = 1; i <= N; i ++)
        for (j = i + 1; j <= N; j ++)
        {
            punct now1, now2;

            now1.x = x[i].x + x[i].y - x[j].y;
            now1.y = x[i].y + x[j].x - x[i].x;
            now2.x = x[j].x + x[i].y - x[j].y;
            now2.y = x[j].y + x[j].x - x[i].x;

            if (is(now1, N) && is(now2, N))
                sol ++;
        }

    printf("%d", sol / 2);
    return 0;
}

