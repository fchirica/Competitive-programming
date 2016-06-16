//valuare a la gutzu $$$

#include <fstream>
using namespace std;
#define LE 2066
ifstream f ( "psir.in" );
#define ll unsigned int
#define MOD 4294967296
ofstream g ( "psir.out" );
int a[LE], ind [LE], poz[LE];
ll DP[LE][LE];
int n, i;
#include <algorithm>
int top, j;
ll result;

bool comp ( int ind1, int ind2 )
{
    return a[ind1] < a[ind2];
}
int main()
{
    f >> n;

    for ( i = 1; i <= n; ++i )
    {
        f >> a[i];
        ind[i] = i;
    }

    sort ( ind + 1, ind + n + 1, comp );

    for ( i = 1; i <= n; ++i )
    {
        poz[ind[i]] = ++top;

        while ( a[ind[i]] == a[ind[i+1]] )
            poz[ind[++i]] = top;
    }


    for ( i = 2; i <= n; ++i )
    {
        for ( j = 1; j < i; ++j ) if ( a[i] != a[j] )
            {
                if ( a[j] > a[i] )
                    DP[i][poz[j]] = ( DP[i][poz[j]] +  DP[j][1] - DP[j][poz[i]] + MOD ) % MOD;
                else
                DP[i][poz[j]] = ( DP[i][poz[j]] + DP[j][poz[i] + 1] ) % MOD;
            }

        for ( j = 1; j < i; ++j )
            ++DP[i][poz[j]];

        for ( j = top; j >= 1; --j )
            DP[i][j] = ( DP[i][j] + DP[i][j+1] ) % MOD;
    }

    for ( i = 1; i <= n; ++i )
        result = ( result + DP[i][1] ) % MOD;


g<<result<<'\n';




    f.close();
    g.close();
    return 0;
}
