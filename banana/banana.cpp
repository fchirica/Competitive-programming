#include <stdio.h>

int  C[16001];
int  *B[10001], Nr[10001];
int  T[16001], H[16001], Num[16001];
int  Zona[16001], Nrz;

int N, K;
int Res;

void sortz();

void sortl(int l);

void init()
{
    int i;
    for (i = 0; i < N; i++) T[i] = i, H[i] = 0, Num[i] = 1;
}

int mult(int i)
{
    if (T[i] == i) return i;
    return T[i] = mult(T[i]);
}

void unite(int i, int j)
{
    i = mult(i);
    j = mult(j);
    if (i == j) return;
    if (H[i] > H[j]) T[j] = i, Num[i] += Num[j];
    else
    if (H[i] < H[j]) T[i] = j, Num[j] += Num[i];
    else
    {
        T[j] = i;
        Num[i] += Num[j];
        H[i]++;
    }
}

int getindex(int ln, int c)
{
    int l, r, m;
    for (l = 1, r = Nr[ln]; l < r; )
    {
        m = (l+r)/2;
        if (C[B[ln][m]] < c)
           l = m+1;
        else
           r = m;
    }
    return (Nr[ln] > 0 && C[B[ln][l]] == c) ? B[ln][l] : -1;
}

void bagamare(int x, int i, int j)
{
    int nr;
    if (i < 1 || j < 1 || i > 10000 || j > 10000) return;
    nr = getindex(i, j);
    if (nr >= 0)
       unite(x, nr);
}


void solve()
{
    int i, j;
    for (i = 0; i <= 10000; i++) sortl(i);
    init();
    for (i = 0; i <= 10000; i++)
      for (j = 1; j <= Nr[i]; j++)
      {
          bagamare(B[i][j], i+1, C[B[i][j]]);
          bagamare(B[i][j], i-1, C[B[i][j]]);
          bagamare(B[i][j], i, C[B[i][j]]+1);
          bagamare(B[i][j], i, C[B[i][j]]-1);
      }
    for (i = 0; i < N; i++)
        if (T[i] == i)
            Zona[++Nrz] = Num[i];
    sortz();
    for (i = 1; i <= Nrz && i <= K; i++) Res += Zona[i];
}

void read_data()
{
    FILE *fi = fopen("BANANA.IN", "rt");
    int i, j, l, c;
    fscanf(fi, "%d %d", &N, &K);
    for (i = 0; i < N; i++)
    {
        fscanf(fi, "%d %d", &l, &c);
        Nr[l]++;
    }
    fclose(fi);
    fi = fopen("BANANA.IN", "rt");
    fscanf(fi, "%d %d", &N, &K);
    for (i = 0; i <= 10000; i++)
    {
        B[i] = (int *) alloc(Nr[i]+1, sizeof(int));
        Nr[i] = 0;
    }
    for (i = 0; i < N; i++)
    {
        fscanf(fi, "%d %d", &l, &c);
        C[i] = c;
        B[l][++Nr[l]] = i;
    }
    fclose(fi);
}


void print()
{
    FILE *fo = fopen("BANANA.OUT", "wt");
    fprintf(fo, "%d\n", Res);
    fclose(fo);
}

void main()
{
    read_data();
    solve();
    print();
}


int _t, hs;


#define swap(i, j) (_t = Zona[i], Zona[i] = Zona[j], Zona[j] = _t)
#define fiu (p = (2*i >= hs || Zona[2*i] < Zona[2*i+1] ? 2*i : 2*i+1))

void siftz(int i)
{
    for (int p; fiu <= hs && Zona[p] < Zona[i]; i = p) swap(i, p);
}

void sortz()
{
    int i;
    hs = Nrz;
    for (i = hs/2; i > 0; i--) siftz(i);
    while (hs > 1)
    {
        swap(1, hs);
        hs--;
        siftz(1);
    }
}



#undef swap
#undef fiu
#define swap(i, j) (_t = B[l][i], B[l][i] = B[l][j], B[l][j] = _t)
#define comp(i, j) (C[B[l][i]] > C[B[l][j]])
#define fiu (p = (2*i >= hs || comp(2*i, 2*i+1) ? 2*i : 2*i+1))

void sift(int i, int l)
{
    for (int p; fiu <= hs && comp(p, i); i = p) swap(i, p);
}

void sortl(int l)
{
    int i;
    hs = Nr[l];
    for (i = hs/2; i > 0; i--) sift(i, l);
    while (hs > 1)
    {
        swap(1, hs);
        hs--;
        sift(1, l);
    }
}

