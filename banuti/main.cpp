#include <stdio.h>
#include <set>

using namespace std;

int x[51000], cost[51000], dist[51000];

set <pair <int, int> > H;

int main() {
    freopen("banuti.in", "r", stdin);
    freopen("banuti.out", "w", stdout);

    int N, small = 1 << 30;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        if (x[i] < small)
            small = x[i];
    }
    for (int i = 0; i < small; ++i)
        cost[i] = 1 << 30;
    for (int i = 1; i <= N; ++i)
        if (x[i] < cost[x[i] % small])
            cost[x[i] % small] = x[i];
    for (int i = 0; i < small; ++i)
        dist[i] = 1 << 30;

    H.insert(make_pair(0, 0));
    dist[0] = 0;
    while (!H.empty()) {
        int dmin = (*H.begin()).first;
        int nod = (*H.begin()).second;
        H.erase(H.begin());
        if (dmin > dist[nod])
            continue;
        for (int i = 0; i < small; ++i) {
            int son = nod + i;
            if (son >= small)
                son -= small;
            int dnew = dmin + cost[i];
            if (dist[son] > dnew) {
                dist[son] = dnew;
                H.insert(make_pair(dnew, son));
            }
        }
    }

    int sol = 0;
    for (int i = 0; i < small; ++i)
        if (dist[i] > sol)
            sol = dist[i];
    if (sol == 1 << 30)
        printf("-1");
    else
        printf("%d", sol - small);
    return 0;
}
