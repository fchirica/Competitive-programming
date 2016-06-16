#include <fstream>

const char IN [ ] = "gaz.in" ;
const char OUT [ ] = "gaz.out" ;
const int MAX = 2014 ;
const int INF = 1 << 30 ;

using namespace std;

ifstream fin ( IN ) ;
ofstream fout ( OUT ) ;

long long best [ MAX ] , gaz [ MAX ] ;

inline void sch ( long long &a , long long b )
{
    if ( a > b )
        a = b ;
}

inline long long maxx ( long long a , long long b )
{
    if ( a > b )
        return a ;
    return b ;
}

int main(              )
{
    long long L , P , D , C ;
    fin >> L >> P >> D >> C ;
    long long n , sum = 0 ;
    fin >> n ;
    for ( int i = 1 ; i <= n ; ++ i )
    {
        fin >> gaz [ i ] ;
        sum = sum + gaz [ i ] ;
        best [ i ] = INF ;
    }
    for ( int i = 1 ; i <= n ; ++ i )
    {
        long long temp = gaz [ i ] ;
        long long count = 0 ;
        for ( int j = i - 1 ; j >= 0 ; -- j )
        {
            sch ( best [ i ] , best [ j ] + count * C + P ) ;
            temp = temp + gaz [ j ] ;
            count = count + maxx ( 0 , temp - gaz [ j ] - L ) ;
        }
    }
    fout << best [ n ] + 1LL * sum * D ;
    return 0;
}
