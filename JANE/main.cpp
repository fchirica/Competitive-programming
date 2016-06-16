#include <stdio.h>
#include <math.h>
#define pii pair <int, int>
#define x first
#define y second
#include <algorithm>
#include <vector>

using namespace std;

int n, dmax, h[100100];

bool good(pii X) {
    if (X.x < 1 || X.y < 1 || X.x > n || X.y > n)
        return 0;
    if (X.x > X.y)
        return 0;
    return abs(h[X.x] - h[X.y]) <= dmax;
}

pii Q[1000100];

vector <pii> H[666777];

int hash(pii X) {
    return ((6971 * X.x) + (666013LL * X.y)) % 666777;
}

void add(pii X) {
    H[hash(X)].push_back(X);
}

bool is(pii X) {
    vector <pii> :: iterator it;
    int go = hash(X);
    for (it = H[go].begin(); it != H[go].end(); ++it)
        if (*it == X)
            return 1;
    return 0;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int p = 1, u = 0;
    scanf("%d%d", &n, &dmax);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    for (int i = 1; i <= n; ++i) {
        Q[++u] = make_pair(i, i);
        add(make_pair(i, i));
        if (good(make_pair(i, i + 1))) {
            Q[++u] = make_pair(i, i + 1);
            add(make_pair(i, i + 1));
        }
    }

    while (p <= u) {
        pii tmp = Q[p];
        for (int dx = -1; dx <= 1; dx += 2)
            for (int dy = -1; dy <= 1; dy += 2) {
                pii cur = make_pair(tmp.x + dx, tmp.y + dy);
                if (is(cur) == 0)
                    if (good(cur)) {
                        Q[++u] = cur;
                        add(cur);
                    }
            }
        ++p;
    }

    sort(Q + 1, Q + u + 1);
    for (int i = 1; i <= u; ++i)
        if (Q[i].x != Q[i].y)
            printf("%d %d\n", Q[i].x, Q[i].y);
    return 0;
}
