#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 3020;
 
struct muchie
{
    int x, y;
    double cost;
} now[MAXN], last[MAXN];
int X[MAXN], Y[MAXN];
int T[MAXN];
char *Buffer;
 
inline double dist (int X1, int Y1, int X2, int Y2)
{
    return (double) sqrt ((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}
 
inline bool comp (const muchie &A, const muchie &B)
{
    return A.cost - B.cost <= (-0.00001);
}
 
int find (int nod)
{
    if (T[nod] == nod)
        return nod;
 
    return (T[nod] = find (T[nod]));
}
 
inline void read (int &X)
{
    X &= 0;
 
    while (*Buffer < '0' || *Buffer > '9')
        ++ Buffer;
 
    while (*Buffer >= '0' && *Buffer <= '9')
        X = (X * 10) + *(Buffer ++) - '0';
}
 
int main()
{
    long long fs = 0;
    int N, i, j, a, b, Tx, Ty;
    double Ans;
 
    freopen ("desen.in", "r", stdin);
    freopen ("desen.out", "w", stdout);
    fseek (stdin, 0, SEEK_END);
    fs = ftell (stdin);
    Buffer = new char [fs];
    rewind (stdin);
    fread (Buffer, 1, fs, stdin);
 
    read (N);
 
    for (i = 1; i <= N; i ++){
        read (X[i]);
        read (Y[i]);
 
        if (i == 1){
            printf ("0.000000\n");
 
            continue;
        }
 
        memcpy (now, last, sizeof (last));
        //memset (last, 0, sizeof (last));
        a = i - 2;
        for (j = 1; j < i; j ++){
            ++ a;
            now[a].x = i;
            now[a].y = j;
            now[a].cost = dist (X[i], Y[i], X[j], Y[j]);
        }
 
        sort (now + 1, now + a + 1, comp);
 
        for (j = 1; j <= a; j ++)
            T[j] = j;
 
        Ans = 0;
        b = 0;
        for (j = 1; j <= a; j ++){
            Tx = find (now[j].x);
            Ty = find (now[j].y);
 
            if (Tx != Ty){
                T[Tx] = Ty;
                last[++ b] = now[j];
                Ans += now[j].cost;
            }
        }
 
        printf ("%.6lf\n", Ans);
    }
 
    return 0;
}