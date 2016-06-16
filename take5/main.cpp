#include <stdio.h>
#include <algorithm>
#include <vector>
#define NMAX (1 << 10)

using namespace std;

int N, limLeft, limRight;
int x[NMAX], news[NMAX];
int sleft[(NMAX * NMAX) / 2], sright[(NMAX * NMAX) / 2];

void makeRight()
{
	int i, j;

    for (i = 3; i <= N; i ++)
        for (j = i + 1; j <= N; j ++)
            sright[++limRight] = x[i] + x[j];

    sort(sright + 1, sright + limRight + 1);
}

void scoate(int X)
{
	int i, step = 0, next = X + 1;

    for (i = 1; i <= limRight; i++)
    {
        while(sright[i + step] == x[X] + x[next])
			step ++, next ++, limRight --;
        sright[i] = sright[i + step];
    }
}

void baga(int X)
{
    int i;

    int M = limLeft, N = 0;
    for (i = 1; i < X; i ++)
        news[++ N] = x[i] + x[X];

    limLeft = M + N;
	sleft[0] = news[0] = -1;

    for (i = limLeft; i > 0; i --)
		if (sleft[M] < news[N])
            sleft[i] = news[N --];
        else
            sleft[i] = sleft[M --];
}

int main()
{
    int i, S, sol = 0;

    freopen("take5.in", "r", stdin);
    freopen("take5.out", "w", stdout);

    scanf("%d%d", &N, &S);
    for (i = 1; i <= N; i ++)
        scanf("%d", &x[i]);

    sort(x + 1, x + N + 1);
	makeRight();

    for (i = 3; i <= N - 2; i ++)
    {
        scoate(i);
        baga(i - 1);

        int wanted = S - x[i];
        int howl = limLeft, howr = limRight, idx1, idx2 = howr;

        if (wanted < 0)
            continue;

		for (idx1 = 1; idx1 <= howl; idx1 ++)
        {
            while (idx2 && sleft[idx1] + sright[idx2] > wanted)
                idx2 --;

            if (idx2 <= 0)
                break;

            if (sleft[idx1] + sright[idx2] == wanted)
            {
                int left = 1, right = 0, val = sright[idx2];

                while (idx2 &&  sright[idx2] == val)
                    right ++, idx2 --;

                val = sleft[idx1];
				while(sleft[idx1 + 1] == val)
                    left ++, idx1 ++;

                sol += left * right;
            }
        }
    }

    printf("%d", sol);
    return 0;
}
