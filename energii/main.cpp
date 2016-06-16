#include <stdio.h>
#include <vector>
#define NMAX 33000
 
using namespace std;
 
struct par
{
    int node, cost;
};
 
inline par make_par (int node, int cost)
{
    par aux;
     
    aux.node = node;
    aux.cost = cost;
     
    return aux;
}
 
int E[2 * NMAX], Lev[2 * NMAX], First[NMAX], rmq[17][2 * NMAX], Lg[2 * NMAX]; //LCA
int niv[NMAX], father[NMAX], cst[NMAX], last[16][NMAX], minCost[16][NMAX]; //smen stramosi
 
vector <par> G[NMAX];
 
void DF (int node, int L)
{
    vector <par> :: iterator it;
    par now;
     
    E[++ E[0]] = node;
    Lev[E[0]] = L;
    niv[node] = L;
    First[node] = E[0];
     
    for (it = G[node].begin (); it != G[node].end (); it ++)
    {
        now = *it;
        if (First[now.node])
            continue;
        father[now.node] = node;
        cst[now.node] = now.cost;
        DF (now.node, L + 1);
        E[++ E[0]] = node;
        Lev[E[0]] = L;
    }
}
 
void makeRMQ ()
{
    int i, j;
     
    for (i = 1; i <= E[0]; i ++)
        rmq[0][i] = i;
 
    for (i = 1; (1 << i) <= E[0]; i ++)
        for (j = 1; j <= E[0]; j ++)
        {
            if ((1 << i) + j - 1 > E[0])
                continue;
            rmq[i][j] = rmq[i - 1][j];
            if (Lev[rmq[i - 1][j + (1 << (i - 1))]] < Lev[rmq[i][j]])
                rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
        }
}
 
void makeLogs (int N)
{
    int i;
     
    for (i = 2; i <= N; i ++)
        Lg[i] = Lg[i / 2] + 1;
}
 
 
int getLCA (int X, int Y)
{
    int x = First[X], y = First[Y];
     
    if (x > y)
    {
        int aux = x;
        x = y;
        y = aux;
    }
     
    int diff = Lg[y - x + 1], sol;
     
    sol = rmq[diff][x];
    if (Lev[rmq[diff][y - (1 << diff) + 1]] < Lev[sol])
        sol = rmq[diff][y - (1 << diff) + 1];
     
    return E[sol];
 
}
 
void makeSmen (int N)
{
    int i, j;
     
    for (i = 2; i <= N; i ++)
        last[0][i] = father[i], minCost[0][i] = cst[i];
     
    for (i = 1; (1 << i) <= N; i ++)
        for (j = 1; j <= N; j ++)
        {
            if ((1 << i) >= niv[j])
                continue;
            last[i][j] = last[i - 1][last[i - 1][j]];
            minCost[i][j] = minCost[i - 1][j];
            if (minCost[i - 1][last[i - 1][j]] < minCost[i][j])
                minCost[i][j] = minCost[i - 1][last[i - 1][j]];
        }
}
 
int getMin (int X, int Y)
{
    int i, diff = niv[X] - niv[Y], sol = 1 << 30;
     
    for (i = 0; (1 << i) <= diff; i ++)
        if ((1 << i) & diff)
        {
            if (minCost[i][X] < sol)
                sol = minCost[i][X];
            X = last[i][X];
        }
     
    return sol;
}
 
int query (int X, int Y)
{
    int lc = getLCA (X, Y), sol;
     
    if (X == Y)
        return 0;
     
    sol = getMin (X, lc);
    if (getMin (Y, lc) < sol)
        sol = getMin (Y, lc);
     
    return sol;
}
 
int main ()
{
    int i, N, Q, P, u, v;
     
    freopen ("atac.in", "r", stdin);
    freopen ("atac.out", "w", stdout);
     
    scanf ("%d%d%d", &N, &Q, &P);
    for (i = 2; i <= N; i ++)
    {
        scanf ("%d%d", &u, &v);
        G[i].push_back (make_par (u, v));
        G[u].push_back (make_par (i, v));
    }
     
    DF (1, 1);
    makeRMQ ();
    makeLogs (E[0]);
    makeSmen (N);
     
    int X, Y, A, B, C, D, newX, newY, Z;
     
    scanf ("%d%d%d%d%d%d", &X, &Y, &A, &B, &C, &D);
     
    for (i = 1; i <= Q; i ++)
    {
        Z = query (X, Y);
        if (i >= Q - P + 1)
            printf ("%d\n", Z);
        newX = (X * A + Y * B) % N + 1;
        newY = (Y * C + Z * D) % N + 1;
        X = newX;
        Y = newY;
    }
     
    return 0;
}
