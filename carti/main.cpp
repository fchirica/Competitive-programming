#include <stdio.h>
#include <deque>
#include <algorithm>
using namespace std;
 
deque<int> d;
int N, C, R;
 
void rot()
{
        if (R == 1)
                R = 0;
        else
                R = 1;
}
 
int main ()
{
        int i, x;
       
        freopen("carti3.in", "r", stdin);
        freopen("carti3.out", "w", stdout);
        scanf("%d%d", &N, &C);
       
        for (i = 1; i <= C; ++i)
        {
                scanf("%d", &x);
                d.push_back(x);
        }
       
        for (i = 1; i <= N; ++i)
        {
                scanf ("%d", &x);
                if (x == -1)
                        rot();
                else
                {
                        if (R == 0)
                                d.push_front(x);
                        else
                                d.push_back(x);
                }
        }
       
        if (R) reverse (d.begin(), d.end());
        for (i = 0; i < d.size(); ++i)
                printf("%d\n", d[i]);
       
        return 0;
}