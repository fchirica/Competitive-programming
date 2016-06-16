#include <stdio.h>
#include <vector>
#define LMAX 2000000 + 10

using namespace std;
vector <int> prime;
char stieve[LMAX / 16];

inline void getPrime (int upperBound)
{
    int i, j, pos;

    prime.push_back (2);
    for (i = 3; i * i <= upperBound; i = i + 2)
    {
        pos = (i - 1) / 2;
        if ((stieve[pos >> 3] & (1 << (pos & 7))) == 0)
        {
            for (j = i * i; j <= upperBound; j = j + 2 * i)
            {
                pos = (j - 1) / 2;
                stieve[pos >> 3] = stieve[pos >> 3] | (1 << (pos & 7));
            }
        }
    }
    for (i = 3; i <= upperBound; i = i + 2)
    {
        pos = (i - 1) / 2;
        if ((stieve[pos >> 3] & (1 << (pos & 7))) == 0)
            prime.push_back (i);
    }
}

int main ()
{
    int N;

    freopen ("ciur.in", "r", stdin);
    freopen ("ciur.out", "w", stdout);

    scanf ("%d", &N);

    getPrime (N);
    printf ("%d", prime.size ());
    return 0;
}


