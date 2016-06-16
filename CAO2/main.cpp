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

char x[555][555];

struct triplet {
    int x0, y0, dir;
} Q[4 * 555 * 555];

triplet mt(int x0, int y0, int dir) {
    triplet tmp;
    tmp.x0 = x0; tmp.y0 = y0; tmp.dir = dir;
    return tmp;
}

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int dmin[4][555][555], prime[1000];

bool notGood(int i, int j, int N, int M) {
    if (i < 0 || j < 0 || i > N || j > M)
        return 1;
    return 0;
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int tests;
    scanf("%d", &tests);

    prime[2] = 1;
    for (int i = 3; i <= 1000; ++i) {
        bool flag = true;
        for (int d = 2; d * d <= i && flag; ++d)
            if (i % d == 0)
                flag = false;
        prime[i] = prime[i - 1] + flag;
    }
    while (tests--) {
        int N, M;
        scanf("%d%d\n", &N, &M);
        for (int i = 1; i <= N; ++i)
            gets(x[i] + 1);
        int p = 1, u = 0;
        for (int i = 0; i <= N + 1; ++i)
            for (int j = 0; j <= M + 1; ++j)
                if (x[i][j] == '#' || notGood(i, j, N, M)) {
                    Q[++u] = mt(i, j, 0);
                    Q[++u] = mt(i, j, 1);
                    Q[++u] = mt(i, j, 2);
                    Q[++u] = mt(i, j, 3);
                    for (int dir = 0; dir < 4; ++dir)
                        dmin[dir][i][j] = -1;
                } else
                    for (int dir = 0; dir < 4; ++dir)
                        dmin[dir][i][j] = 1 << 30;
        while (p <= u) {;
            int nx = Q[p].x0 + dx[Q[p].dir];
            int ny = Q[p].y0 + dy[Q[p].dir];
            int savedDir = Q[p].dir;
            ++p;
            if (notGood(nx, ny, N, M))
                continue;
            if (dmin[savedDir][nx][ny] == 1 << 30) {
                dmin[savedDir][nx][ny] = dmin[savedDir][Q[p - 1].x0][Q[p - 1].y0] + 1;
                Q[++u] = mt(nx, ny, savedDir);
            }
        }
        int res = 0;
        for (int i = 3; i <= N - 2; ++i)
            for (int j = 3; j <= M - 2; ++j) {
                int mi = 1 << 30;
                for (int dir = 0; dir < 4; ++dir)
                    chmin(mi, dmin[dir][i][j]);
                if (mi < 0)
                    continue;
                res += prime[mi];
            }
        printf("%d\n", res);
    }
    return 0;
}
