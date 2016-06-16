#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

int x[125][125];
pair <int, int> pos[125 * 125];

inline bool comp(pair <int, int> A, pair <int, int> B) {
    return A.y < B.y;
}

int main() {
    freopen("trecere.in", "r", stdin);
    freopen("trecere.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &x[i][j]);

    int cost = 1 << 30, bestCol, bestCul;
    for (int col = 1; col <= M; ++col) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (x[i][j] == col)
                    pos[++cnt] = mp(i, j);
        sort(pos + 1, pos + cnt + 1, comp);
        int expectedCol = pos[(cnt + 1) / 2].y;
        sort(pos + 1, pos + cnt + 1);
        int curCost = 0;
        for (int i = 1; i <= cnt; ++i)
            curCost += abs(pos[i].x - i) + abs(pos[i].y - expectedCol);
        if (curCost < cost) {
            cost = curCost;
            bestCol = expectedCol;
            bestCul = col;
        }
    }

    printf("%d %d %d", cost, bestCul, bestCol);
    return 0;
}
