#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define x first
#define y second
#define point pair <int, int>

using namespace std;

pair <int, int> P[100100];

struct APM {
    int Ex, Ey, Ec;
} E[400400];

inline int abs(int X) {
    return X > 0 ? X : -X;
}

int dj[100100];

inline int father(int x) {
    return dj[x] = ((dj[x] == x) ? x : father(dj[x]));
}

struct comp {
    inline bool operator () (APM A, APM B) {
        return A.Ec < B.Ec;
    }
};
int main() {
    srand(time(0));

    freopen("rrmst.in", "r", stdin);
    freopen("rrmst.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &P[i].x, &P[i].y);
    sort(P + 1, P + n + 1);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int best = 1000000000, idx = -1;
        for (int j = i + 1; j <= n; ++j) {
            if (abs(j - i) >= best)
                break;
            if (P[j].y < P[i].y + abs(j - i))
                continue;
            if (abs(j - i) + abs(P[j].y - P[i].y) < best)
                best = abs(j - i) + abs(P[j].y - P[i].y), idx = j;
        }
        if (idx != -1)
            E[++cnt].Ex = i, E[cnt].Ey = idx, E[cnt].Ec = best;
        best = 1000000000; idx = -1;
        for (int j = i + 1; j <= n; ++j) {
            if (abs(j - i) >= best)
                break;
            if (P[j].y >= P[i].y + abs(j - i) || P[j].y < P[i].y)
                continue;
            if (abs(j - i) + abs(P[j].y - P[i].y) < best)
                best = abs(j - i) + abs(P[j].y - P[i].y), idx = j;
        }
        if (idx != -1)
            E[++cnt].Ex = i, E[cnt].Ey = idx, E[cnt].Ec = best;
        best = 1000000000; idx = -1;
        for (int j = i + 1; j <= n; ++j) {
            if (abs(j - i) >= best)
                break;
            if (P[j].y >= P[i].y || P[j].y < P[i].y - abs(j - i))
                continue;
            if (abs(j - i) + abs(P[j].y - P[i].y) < best)
                best = abs(j - i) + abs(P[j].y - P[i].y), idx = j;
        }
        if (idx != -1)
            E[++cnt].Ex = i, E[cnt].Ey = idx, E[cnt].Ec = best;
        best = 1000000000; idx = -1;
        for (int j = i + 1; j <= n; ++j) {
            if (j - i >= best)
                break;
            if (P[j].y >= P[i].y - abs(j - i))
                continue;
            if (abs(j - i) + abs(P[j].y - P[i].y) < best)
                best = abs(j - i) + abs(P[j].y - P[i].y), idx = j;
        }
        if (idx != -1)
            E[++cnt].Ex = i, E[cnt].Ey = idx, E[cnt].Ec = best;
    }

    for (int i = 1; i <= n; ++i)
        dj[i] = i;
    sort(E + 1, E + cnt + 1, comp());

    long long sol = 0;
    for (int i = 1; i <= cnt; ++i) {
        int xx = E[i].Ex;
        int yy = E[i].Ey;
        int cc = E[i].Ec;
        if (father(xx) == father(yy))
            continue;
        if (rand() % 2)
            dj[father(xx)] = father(yy);
        else
            dj[father(yy)] = father(xx);
        sol += cc;
    }


    printf("%lld", sol);
    return 0;
}
