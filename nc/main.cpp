#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

char x[1 << 12];
vector <int> phrases;

inline bool let (char X)
{
    if ('a' <= X && X <= 'z')
        return true;
    if ('A' <= X && X <= 'Z')
        return true;
    return false;
}

int main ()
{
    int i, lenth, num = 0, j;

    freopen ("nc.in", "r", stdin);
    freopen ("nc.out", "w", stdout);

    for (i = 1; gets (x + 1); i ++)
    {
        lenth = strlen (x + 1);
        for (j = 1; j <= lenth; j ++)
        {
            if (x[j] == '.' || x[j] == '!' || x[j] == '?')
            {
                if (num)
                    phrases.push_back (num);
                num = 0;
            }
            if (let (x[j]) && !let (x[j + 1]))
                num ++;
        }
    }

    printf ("%d\n", phrases.size ());
    lenth = phrases.size () - 1;
    for (i = 0; i <= lenth; i ++)
        printf ("%d\n", phrases[i]);
    return 0;
}

