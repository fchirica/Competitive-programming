#include<stdio.h>
#include<vector>
#define NMAX 33000

using namespace std;

vector<int> L[NMAX];
int u, E[NMAX << 1], First[NMAX], Lev[NMAX << 1];
int D[20][NMAX << 1];
int score[NMAX];

inline int log2(int X)
{
    int pow=0;
    while ((1<<pow) <= X)
        pow++;
    return pow - 1;
}

void DF(int nod, int nivel)
{
    vector<int> :: iterator it;
    E[++u] = nod;
    Lev[u] = nivel;
    First[nod] = u;
    for(it = L[nod].begin(); it != L[nod].end(); it ++)
        {
            DF(*it,nivel + 1);
            E[++u] = nod;
            Lev[u] = nivel;
        }
}

void RMQ()
{
    int i, j;
    for(i = 1; i <= u; i ++)
        D[0][i] = i;
    for(i = 1; i <= log2(u); i ++)
        for(j = 1; j <= u; j ++)
            {
                if(j + (1 << i) > u + 1)
                    break;
                if(Lev[D[i - 1][j]] > Lev[D[i - 1][j + (1 << (i - 1))]])
                    D[i][j] = D[i - 1][j + (1 << (i - 1))];
                else
                    D[i][j] = D[i - 1][j];
            }
}

int best = -1, xbest, ybest;

void LCA(int x, int y)
{
    int X, Y, aux, lg, index;
    X = First[x];
    Y = First[y];
    if (X > Y)
        {
            aux = X;
            X = Y;
            Y = aux;
        }
    lg = log2(Y - X + 1);
    if(Lev[D[lg][X]] > Lev[D[lg][Y - (1 << lg) + 1]])
        index = D[lg][Y - (1 << lg) + 1];
    else
        index = D[lg][X];
    int boss = E[index];
    int win = score[boss];
    if (win > best) {
        best = win;
        xbest = x; ybest = y;
    }
    if (win == best) {
        if (x < xbest)
            xbest = x, ybest = y;
        if (x == xbest && y < ybest)
            ybest = y;
    }
}

bool isRoot[NMAX];

int main()
{
    int N, M, i, x, y;

    freopen("concurs.in", "r", stdin);
    freopen("concurs.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i) {
        scanf("%d", &score[i]);
        isRoot[i] = 1;
    }
    for(i = 1; i < N; i ++) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        L[xx].push_back(yy);
        isRoot[yy] = 0;
    }

    for (int i = 1; i <= N; ++i)
        if (isRoot[i])
            DF(i, 0);
    RMQ();
    while(M --)
    {
        scanf("%d%d", &x, &y);
        LCA(x, y);
    }

    printf("%d %d %d", best, xbest, ybest);
    return 0;
}

