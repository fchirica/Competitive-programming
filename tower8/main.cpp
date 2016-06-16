#include <vector>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#define FOR(i, n) for(int (i)=1;(i)<=(n);++(i))
#define REP(i, a, b) for (int (i)=a;(i)<=(b);++(i))
#define FORIT(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define long long ll
#define DBG(val) cerr<<#val<<" = "<<(val)<<"\n"
#define SHOW(val) cerr<<(val)<<" "
#define ENTER cerr << "\n"
#define fi first
#define se second

template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

using namespace std;

int x[111][111];
vector <pair <int, int> > moves;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool canBuild(int xx, int yy, int size, bool keep, vector <pair <int, int> > &moves) {
    if (x[xx][yy])
        return 0;
    if (size == 1) {
        x[xx][yy] = 1;
        if (keep)
            moves.push_back(make_pair(xx, yy));
        return 1;
    }
    REP(d, 0, 7) {
        int newX = xx + dx[d];
        int newY = yy + dy[d];
        vector <pair <int , int> > neighbour_moves, cur_moves;
        if (canBuild(newX, newY, size - 1, keep, neighbour_moves)) {
            if (canBuild(xx, yy, size - 1, keep, cur_moves)) {
                x[newX][newY] = 0;
                x[xx][yy] = size;
                if (keep) {
                    FORIT(it, neighbour_moves)
                        moves.push_back(*it);
                    FORIT(it, cur_moves)
                        moves.push_back(*it);
                }
                return 1;
            } else
                x[newX][newY] = 0;
        }
    }
    return 0;
}

int main() {
    freopen("tower8.in", "r", stdin);
    freopen("tower8.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, n)
        FOR(j, m)
            scanf("%d", &x[i][j]);

    FOR(tSize, 9) {
        queue <pair <int, int> > q;
        FOR(i, n)
            FOR(j, m)
                if (x[i][j] == tSize)
                    q.push(make_pair(i, j));
        while (!q.empty()) {
            pair <int, int> now = q.front();
            q.pop();
            x[now.fi][now.se] = 0;
            if (canBuild(now.fi, now.se, tSize, 0, shit)) {
                x[now.fi][now.se] = 0;
                canBuild(now.fi, now.se, tSize, 1);
            } else {
                x[now.fi][now.se] = tSize;
                q.push(now);
            }
        }

    }
    return 0;
}
