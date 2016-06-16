#include <stdio.h>
#include <vector>
#define NMAX 50500
#define INF (1 << 30)

using namespace std;

int dist[NMAX];

int main()
{
    int test, i, x, y, T, N, M, S, cost;

    freopen("distante.in", "r", stdin);
    freopen("distante.out", "w", stdout);

    scanf("%d", &T);
    for (test = 1; test <= T; test ++)
    {
        scanf("%d%d%d", &N, &M, &S);
        for (i = 1; i <= N; i ++)
            scanf("%d", &dist[i]);

        bool isCorrect = true;

        for (i = 1; i <= M; i ++)
        {
            scanf("%d%d%d", &x, &y, &cost);
            if (dist[x] + cost < dist[y] || dist[y] + cost < dist[x])
                isCorrect = false;
        }

        if (dist[S])
            isCorrect = false;

        if (isCorrect == true)
            printf("DA\n");
        else
            printf("NU\n");
    }

    return 0;
}
