#include <stdio.h>
#define LMAX 1000100
#define DIM 8192
#define VMAX 1000100

int x[LMAX], next[LMAX], st[LMAX];
char buff[DIM];
int poz = 0;
long long cnt[VMAX], S[VMAX], grad[LMAX];

void read (int &numar)
{
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar = numar*10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    }
}

int main ()
{
    int i, N, M, lun, maxVal = -1, x0, y0;

    freopen ("nrsubsecv.in", "r", stdin);
    freopen ("nrsubsecv.out", "w", stdout);

    //Read data
    read (N); read (M);
    for (i = 1; i <= N; i ++)
    {
        read (x[i]);
        if (x[i] > maxVal)
            maxVal = x[i];
    }

    int p, u; p = 1; u = 0;

    //Get next[i], where next[i] is minimum j with property i < j and x[i] < x[j]
    //Using a stack it can be calculated in O(N)
    for (i = 1; i <= N; i ++)
    {
        while (p <= u && x[i] < x[st[u]])
        {
            next[st[u]] = i;
            u --;
        }
        st[++ u] = i;
    }
    for (i = 1; i <= N; i ++)
        if (next[i] == 0)
            next[i] = N + 1;

    for (i = 1; i <= N; i ++)
    {
        lun = next[i] - i;
        cnt[x[i]] += (long long)(grad[i] + 1) * lun;
        grad[next[i]] += grad[i] + 1;
    }

    for (i = 0; i <= maxVal; i ++)
    {
        if (i > 0)
            S[i] = S[i - 1] + cnt[i];
        else
            S[i] = cnt[i];
    }

    for (i = 1; i <= M; i ++)
    {
        read (x0); read (y0);
        printf ("%lld\n", S[y0] - S[x0 - 1]);
    }

    return 0;
}
