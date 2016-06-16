//limita de timp de cacat

#include <bits/stdc++.h>

using namespace std;

int modx, mody;
int d_to_xy[1024 * 1024], q[1024 * 1024], cnt_modx[1111], cnt_mody[1111];
int res[700000];

vector <int> GT[1024 * 1024];

inline int compress(int x, int y) {
    return x * mody + y;
}

int main() {
    freopen("robotei.in", "r", stdin);
    freopen("robotei.out", "w", stdout);

    int n, m, x, y, offsetX, offsetY;
    scanf("%d%d%d%d%d%d%d%d", &n, &m, &x, &y, &modx, &mody, &offsetX, &offsetY);

    if (x >= modx || y >= mody) {
        printf("0 %lld\n1 1", (long long) n * n - 1);
        return 0;
    }

    for (int i = 0; i < modx; ++i)
        for (int j = 0; j < mody; ++j) {
            int next_i = (static_cast <long long> (i) * i + offsetX) % modx;
            int next_j = (static_cast <long long> (j) * j + offsetY) % mody;
            GT[compress(next_i, next_j)].push_back(compress(i, j));
            d_to_xy[compress(i, j)] = 1000000000;
        }

    int p = 1, u = 0;
    q[++u] = compress(x, y);
    d_to_xy[compress(x, y)] = 0;
    while (p <= u) {
        int nod = q[p];
        vector <int> :: iterator it;
        for (it = GT[nod].begin(); it != GT[nod].end(); ++it)
            if (d_to_xy[*it] == 1000000000) {
                d_to_xy[*it] = d_to_xy[nod] + 1;
                q[++u] = *it;
            }
        ++p;
    }

    int cycle;
    bool have_cycle = 0;
    int cur_x = x;
    int cur_y = y;
    for (cycle = 1; cycle <= modx * mody + 1; ++cycle) {
        cur_x = ((cur_x) * cur_x + offsetX) % modx;
        cur_y = ((cur_y) * cur_y + offsetY) % mody;
        if (cur_x == x && cur_y == y) {
            have_cycle = 1;
            break;
        }
    }
    if (!have_cycle)
        cycle = 1000000000;

    for (int i = 0; i < n; ++i)
        ++cnt_modx[i % modx];
    for (int i = 0; i < n; ++i)
        ++cnt_mody[i % mody];
    for (int i = 0; i < modx; ++i)
        for (int j = 0; j < mody; ++j) {
            int my_robots = cnt_modx[i] * cnt_mody[j];
            if (i == x && j == y) {
                res[m / cycle] += my_robots - 1;
                ++res[m / cycle + 1];
                continue;
            }
            int cycle_steps = m - d_to_xy[compress(i, j)];
            if (cycle_steps < 0) {
                res[0] += my_robots;
                continue;
            }
            res[1 + cycle_steps / cycle] += my_robots;
        }

    for (int i = 0; i <= m; ++i)
        if (res[i])
            printf("%d %d\n", i, res[i]);
    return 0;
}
