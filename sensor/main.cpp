#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

point x[111];
int n;
vector <int> G[111];

int dist(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

int set1[111], set2[111], L[111], R[111], isL[111], isR[111], partSol[111], bestSol[111];
bool used[111];

int pairup(int nod) {
    if (used[nod])
        return 0;
    used[nod] = 1;

    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!R[*it] || pairup(R[*it])) {
            L[nod] = *it;
            R[*it] = nod;
            return 1;
        }
    return 0;
}

void support(int nod) {
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!isR[*it]) {
            isR[*it] = 1;
            isL[R[*it]] = 0;
            support(R[*it]);
        }
}

int solve(int idx1, int idx2) {
    int maxd = dist(x[idx1], x[idx2]);
    set1[0] = set2[0] = 0;
    for (int i = 1; i <= n; ++i)
        if (dist(x[idx1], x[i]) <= maxd && dist(x[idx2], x[i]) <= maxd) {
            if (ccw(x[idx1], x[idx2], x[i]) <= 0 || i == idx1 || i == idx2)
                set1[++set1[0]] = i;
            else
                set2[++set2[0]] = i;
        }

    for (int i = 1; i <= set1[0]; ++i)
        G[i].clear();
    for (int i = 1; i <= set1[0]; ++i)
        for (int j = 1; j <= set2[0]; ++j)
            if (dist(x[set1[i]], x[set2[j]]) > maxd)
                G[i].push_back(j);

    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    memset(isL, 0, sizeof(isL));
    memset(isR, 0, sizeof(isR));
    memset(used, 0, sizeof(used));

    bool match = 1;
    while (match) {
        match = 0;
        for (int i = 1; i <= set1[0]; ++i)
            if (L[i] == 0 && pairup(i))
                match = 1;
    }

    for (int i = 1; i <= set1[0]; ++i)
        if (L[i])
            isL[i] = 1;
    for (int i = 1; i <= set1[0]; ++i)
        if (!isL[i])
            support(i);

    int cnt = 0;
    for (int i = 1; i <= set1[0]; ++i)
        if (!isL[i])
            partSol[++cnt] = set1[i];
    for (int i = 1; i <= set2[0]; ++i)
        if (!isR[i])
            partSol[++cnt] = set2[i];

    return cnt;
}

int main() {
    int maxd;
    scanf("%d%d", &n, &maxd);
    maxd = maxd * maxd;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);

    int best = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            if (dist(x[i], x[j]) > maxd)
                continue;
            int ret = solve(i, j);
            if (ret > best) {
                best = ret;
                memcpy(bestSol, partSol, sizeof(bestSol));
            }
        }

    if (best == 0) {
        printf("1\n1");
        return 0;
    }

    printf("%d\n", best);
    for (int i = 1; i <= best; ++i)
        printf("%d ", bestSol[i]);
    return 0;
}
