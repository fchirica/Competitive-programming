#include <bits/stdc++.h>

using namespace std;

const int kNMax = 37;

int g[kNMax][kNMax], sub[1 << 18];
int match_left[1 << 18];
vector <int> set_one, set_two;

int len, stk[kNMax];

void buildSet(vector <int> &mySet, int left, int right, int mask) {
    for (int i = left; i <= right; ++i)
        if (i > stk[len]) {
            bool ok = true;
            for (int j = 1; j <= len; ++j)
                if (g[stk[j]][i])
                    ok = false;
            if (ok) {
                stk[++len] = i;
                mask |= (1 << (i - left));
                mySet.push_back(mask);
                buildSet(mySet, left, right, mask);
                --len;
                mask ^= (1 << (i - left));
            }
        }
}

int count_bits(int val) {
    int res = 0;
    while (val) {
        ++res;
        val = val & (val - 1);
    }
    return res;
}

int main() {
    freopen("alianta.in", "r", stdin);
    freopen("alianta.out", "w", stdout);

    int tests;
    scanf("%d", &tests);
    while (tests--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            int xx, yy;
            scanf("%d%d", &xx, &yy);
            g[xx][yy] = 1;
            g[yy][xx] = 1;
        }

        int middle = (n + 1) / 2;
        buildSet(set_one, 1, middle, 0);
        buildSet(set_two, middle + 1, n, 0);

        set_one.push_back(0);
        set_two.push_back(0);

        for (int i = 0; i < set_two.size(); ++i)
            sub[set_two[i]] = count_bits(set_two[i]);
        for (int b = 0; b < n - middle; ++b)
            for (int i = 0; i < (1 << (n - middle)); ++i)
                if (i & (1 << b))
                    sub[i] = max(sub[i], sub[i - (1 << b)]);

        int res = 0;

        for (int i = middle + 1; i <= n; ++i) {
            int allowed_mask = 0;
            for (int b = 0; b < middle; ++b)
                if (!g[b + 1][i])
                    allowed_mask |= (1 << b);
            for (int j = 0; j < set_one.size(); ++j) {
                int myMask = set_one[j];
                if ((myMask & ~allowed_mask) == 0)
                    match_left[myMask] |= (1 << (i - middle - 1));
            }
        }

        for (int i = 0; i < set_one.size(); ++i)
            res = max(res, count_bits(set_one[i]) + sub[match_left[set_one[i]]]);
        printf("%d\n", res);

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = 0;
        set_one.clear();
        set_two.clear();
        for (int i = 0; i < (1 << (n - middle)); ++i)
            sub[i] = 0;
        for (int i = 0; i < (1 << middle); ++i)
            match_left[i] = 0;
    }

    return 0;
}
