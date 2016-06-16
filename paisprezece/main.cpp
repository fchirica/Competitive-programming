#include <stdio.h>
#include <vector>
#define LMAX 1000000 + 10

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

inline int pow6 (int X)
{
    return X * X * X * X * X * X;
}

long long pow13 (int x)
{
    return (long long)pow6 (x) * pow6 (x) * x;
}

int main ()
{
    int X, Y, now, j, num = 0, i, N;

    freopen ("paisprezece.in", "r", stdin);
    freopen ("paisprezece.out", "w", stdout);

    scanf ("%d%d", &X, &Y);
    getPrime (Y / 64);
    N = prime.size () - 1;

    for (i = 0; (now = pow6 (prime[i])) <= Y; i ++)
    {
        for (j = 0; j <= N && prime[j] * now < X; j ++);
        for (; j <= N && prime[j] * now <= Y; j ++)
            if (prime[j] != prime[i])
                num ++;

    }
    for (i = 0; (long long)pow13 (prime[i]) <= Y; i ++)
        if (pow13 (prime[i]) >= X)
            num ++;

    printf ("%d\n", num);
    return 0;
}


