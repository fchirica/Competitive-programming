#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#define prev savafutingurademuisti

using namespace std;

int swaps[33][21], pw2[1 << 20];
vector <pair <int, int> > prev, nxt;

int getBit(int mask, int pos) {
    if (mask & (1 << pos))
        return 1;
    return 0;
}

void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

void do_swap(int &mask, int pos1, int pos2) {
    if (pos1 > pos2)
        swap(pos1, pos2);
    int b1 = getBit(mask, pos1);
    int b2 = getBit(mask, pos2);
    if (b1 == 1 && b2 == 0) {
        mask -= (1 << pos1);
        mask += (1 << pos2);
    }
}

pair <int, int> swap_pairs[12];
int cur[1 << 20];

int f[1 << 20];
int cnt = 0;

void magic_order(int layer, int n) {
    int pairs_cnt = 0;
    for (int i = 0; i < n; ++i) {
        int i2 = swaps[layer][i];
        if (i < i2)
            swap_pairs[++pairs_cnt] = make_pair(i, i2);
    }
    cnt = 0;
    cur[++cnt] = 0;
    cur[++cnt] = 1 << swap_pairs[1].second;
    cur[++cnt] = (1 << swap_pairs[1].first) + (1 << swap_pairs[1].second);
    for (int i = 2; i <= pairs_cnt; ++i) {
        int ncnt = cnt;
        for (int j = cnt; j >= 1; --j)
            cur[++ncnt] = cur[j] + (1 << swap_pairs[i].second);
        for (int j = 1; j <= cnt; ++j)
            cur[++ncnt] = cur[j] + (1 << swap_pairs[i].first) + (1 << swap_pairs[i].second);
        cnt = ncnt;
    }
}

void setBit(int &mask, int val, int pos) {
    if (val)
        mask |= (1 << pos);
}

bool isSorted(int mask, int n) {
    int firstOne = 1 << 30;
    int lastZero = -1;
    for (int i = 0; i < n; ++i)
        if ((mask & (1 << i)) == 0)
            lastZero = i;
        else if (firstOne == 1 << 30)
            firstOne = i;
    return lastZero <= firstOne;
}

int main() {
    freopen("sortnet.in", "r", stdin);
    freopen("sortnet.out", "w", stdout);

    int n, m;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i)
        pw2[1 << i] = i;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            int xx, yy;
            scanf("<%d,%d> ", &xx, &yy);
            --xx;
            --yy;
            swaps[i][xx] = yy;
            swaps[i][yy] = xx;
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        int mask = i;
        for (int j = 0; j < n; ++j) {
            int j2 = swaps[1][j];
            if (j < j2)
                do_swap(mask, j, j2);
        }
        ++f[mask];
    }

    for (int i = 0; i < (1 << n); ++i)
        if (f[i])
            prev.push_back(make_pair(i, f[i]));

    for (int layer = 2; layer <= m; ++layer) {
        magic_order(layer - 1, n);

        nxt.clear();
        int after_layer = 0;
        for (int i = 1; i <= cnt; ++i) {
            if (f[cur[i]]) {
                nxt.push_back(make_pair(after_layer, f[cur[i]]));
                f[cur[i]] = 0;
            }
            int bit = cur[i] ^ cur[i + 1];
            if (after_layer & bit)
                after_layer ^= bit;
            bit = pw2[bit];
            int bit2 = swaps[layer][bit];
            if (after_layer & (1 << bit2))
                after_layer ^= (1 << bit2);
            int b1 = getBit(cur[i + 1], bit);
            int b2 = getBit(cur[i + 1], bit2);
            setBit(after_layer, b1, bit);
            setBit(after_layer, b2, bit2);
            do_swap(after_layer, bit, bit2);
        }

        for (int i = 0; i < prev.size(); ++i)
            f[prev[i].first] = 0;
        for (int i = 0; i < nxt.size(); ++i) {
            prev[i] = nxt[i];
            f[prev[i].first] += prev[i].second;
        }
    }

    int res = 0;
    for (int i = 0; i < (1 << n); ++i)
        if (f[i] && isSorted(i, n))
            res += f[i];
    printf("%d", res);
    return 0;
}
