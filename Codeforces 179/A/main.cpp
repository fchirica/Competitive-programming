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
#include <cstring>
#include <string.h>

using namespace std;

void openfiles() {
    #ifndef ONLINE_JUDGE
        freopen ("data.in", "r", stdin);
        freopen ("data.out", "w", stdout);
    #endif
}

int x[150], f[1500];

int main() {
    openfiles();

    int i, N;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%d", &x[i]);

    for (i = 1; i <= N; ++i)
        ++f[x[i]];

    int maxLimit = (N + 1) / 2;

    bool solution = true;
    for (i = 1; i <= N; ++i)
        if (f[x[i]] > maxLimit)
            solution = false;

    printf("%s", solution ? "YES" : "NO");
    return 0;
}
