#include <cstdio>
#include <cstring>
#include <algorithm>

#define NMax 19
#define LMax 30005
#define Infinity 1000000000

using namespace std;

int N, L[NMax], Cost[NMax][NMax], DP[1<<NMax][NMax], F[1<<NMax][NMax];
char DNA[NMax][LMax];

inline void BuildPi (char A[], int n, int Pi[])
{
    int k=0;
    for (int i=2; i<=n; ++i)
    {
        while (k>0 and A[k+1]!=A[i]) k=Pi[k];
        if (A[i]==A[k+1]) ++k;
        Pi[i]=k;
    }
}

inline int KMP (char A[], int n, char B[], int m, int Pi[])
{
    int k=0;
    for (int i=1; i<=m; ++i)
    {
        while (k>0 and B[i]!=A[k+1]) k=Pi[k];
        if (B[i]==A[k+1]) ++k;
        if (k==n) return -1;
    }
    return k;
}

void BuildCost ()
{
    for (int i=0; i<N; ++i)
    {
        int Pi[LMax]; memset (Pi, 0, sizeof (Pi));
        BuildPi (DNA[i], L[i], Pi);
        for (int j=0; j<N; ++j)
        {
            if (i==j) continue;
            if (KMP (DNA[i], L[i], DNA[j], L[j], Pi)==-1)
            {
                memcpy (DNA[i], DNA[N-1], sizeof (DNA[N-1]));
                L[i]=L[N-1]; --i; --N;
                memset (DNA[N], 0, sizeof (DNA[N]));
                break;
            }
        }
    }
    for (int i=0; i<N; ++i)
    {
        int Pi[LMax]; memset (Pi, 0, sizeof (Pi));
        BuildPi (DNA[i], L[i], Pi);
        for (int j=0; j<N; ++j)
        {
            if (i==j) continue;
            Cost[j][i]=KMP (DNA[i], L[i], DNA[j], L[j], Pi);
        }
    }
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            Cost[i][j]=L[j]-Cost[i][j];
        }
        Cost[N][i]=L[i];
    }
}

void Initialize ()
{
    for (int i=1; i<(1<<N); ++i)
    {
        for (int j=0; j<N; ++j)
        {
            DP[i][j]=Infinity;
            F[i][j]=N;
        }
    }
    for (int i=0; i<N; ++i)
    {
        DP[1<<i][i]=L[i];
    }
}

void SolveDP ()
{
    Initialize ();
    for (int Conf=1; Conf<(1<<N); ++Conf)
    {
        for (int i=0; i<N; ++i)
        {
            if (DP[Conf][i]<Infinity or !(Conf&(1<<i)))
            {
                continue;
            }
            for (int j=0; j<N; ++j)
            {
                if (i==j or !(Conf&(1<<j))) continue;
                if (DP[Conf^(1<<i)][j]+Cost[j][i]<DP[Conf][i])
                {
                    DP[Conf][i]=DP[Conf^(1<<i)][j]+Cost[j][i];
                    F[Conf][i]=j;
                }
            }
        }
    }
}

inline void Print (int Conf, int Last)
{
    if (Conf==0) return;
    Print (Conf^(1<<Last), F[Conf][Last]);
    for (int i=L[Last]+1-Cost[F[Conf][Last]][Last]; i<=L[Last]; ++i)
    {
        printf ("%c", DNA[Last][i]);
    }
}

void Solve ()
{
    BuildCost ();
    SolveDP ();
    int Last=0;
    for (int i=1; i<N; ++i)
    {
        if (DP[(1<<N)-1][i]<DP[(1<<N)-1][Last])
        {
            Last=i;
        }
    }
    freopen ("adn.out", "w", stdout);
    Print ((1<<N)-1, Last);
    printf ("\n");
}

void Read ()
{
    freopen ("adn.in", "r", stdin);
    scanf ("%d\n", &N);
    for (int i=0; i<N; ++i)
    {
        scanf ("%s\n", DNA[i]);
        L[i]=strlen (DNA[i]);
        for (int j=L[i]; j>0; --j)
        {
            DNA[i][j]=DNA[i][j-1];
        }
    }
}

int main()
{
    Read ();
    Solve ();
    return 0;
}
