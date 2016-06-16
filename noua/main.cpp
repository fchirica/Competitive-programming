/*
And the cat's in the cradle,
and the silver spoon
Little boy blue,
and the man on the moon
When you comin' home dad?
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int res[100];
char x[22];

inline bool comp(int A, int B) {
    return A > B;
}

int main() {

    int n;
    scanf("%d\n", &n);
    gets(x + 1);

    for (int i = 1; i <= n; ++i) {
        int xx = x[i] - '0';
        if (xx < 2)
            continue;
        if (xx == 4 || xx == 6 || xx == 8 || xx == 9) {
            if (xx == 4) {
                res[++res[0]] = 2;
                res[++res[0]] = 2;
                res[++res[0]] = 3;
            }
            if (xx == 6) {
                res[++res[0]] = 3;
                res[++res[0]] = 5;
            }
            if (xx == 8) {
                res[++res[0]] = 2;
                res[++res[0]] = 2;
                res[++res[0]] = 2;
                res[++res[0]] = 7;
            }
            if (xx == 9) {
                res[++res[0]] = 3;
                res[++res[0]] = 3;
                res[++res[0]] = 2;
                res[++res[0]] = 7;
            }
        } else
            res[++res[0]] = xx;
    }

    sort(res + 1, res + res[0] + 1, comp);
    for (int i = 1; i <= res[0]; ++i)
        printf("%d", res[i]);
    return 0;
}
