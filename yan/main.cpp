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
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define FOR(i, n) REP(i, 1, n)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define pair <int, int> pii

using namespace std;

int main() {
    read3(A, B, C);
    ll a = A, b = B, c = C;
    int op = 0;
    char ch;
    if (a + b == c)
        ++op, ch = '+';
    if (a * b == c)
        ++op, ch = '*';
    if (a - b == c)
        ++op, ch = '-';
    if (b && a % b == 0 && a / b == c)
        ++op, ch = '/';
    if (op == 0 || op > 1)
        printf("Invalid");
    else
        printf("%c", ch);
    return 0;
}
