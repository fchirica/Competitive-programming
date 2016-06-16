#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
char x[555555];

const int B = 71;
unsigned long long H[555555], pw[555555];

int q[555555];
unsigned long long rt[555555];

unsigned long long get(int xx, int yy) {
    if (xx > yy)
        return 0;
    return H[xx] - pw[yy - xx + 1] * H[yy + 1];
}

unsigned long long getCenter(int O, int lim, int len, int how) {
    if (how <= lim - O + 1)
        return get(O, O + how - 1);
    unsigned long long hsh = get(O, lim);
    how -= (lim - O + 1);
    hsh = hsh + pw[lim - O + 1] * get(lim - len + 1, lim - len + how);
    return hsh;
}

bool better(int O1, int O2, int lim, int len) {
    int st = 1, dr = lim - len + 1, ret = 0;
    while (st <= dr) {
        int med = (st + dr) / 2;
        unsigned long long hash1 = getCenter(O1, lim, len, med);
        unsigned long long hash2 = getCenter(O2, lim, len, med);
        if (hash1 == hash2) {
            ret = med;
            st = med + 1;
        } else
            dr = med - 1;
    }
    ++ret;
    int pos1 = O1, pos2 = O2;
    if (ret > lim - O1 + 1) {
        int go = ret - (lim - O1 + 1);
        pos1 = go - 1 + lim - len + 1;
    } else
        pos1 += ret - 1;
    if (ret > lim - O2 + 1) {
        int go = ret - (lim - O2 + 1);
        pos2 = go - 1 + lim - len + 1;
    } else
        pos2 += ret - 1;
    return x[pos1] <= x[pos2];
}

void solve(int len) {
    int p = 1, u = 0, cnt = 0;
    for (int i = 1; i <= N; ++i) {
        while (p <= u && better(i, q[u], max(i, len), len))
            --u;
        q[++u] = i;
        if (q[p] + len == i)
            ++p;
        if (i >= len)
            rt[++cnt] = (unsigned long long)get(q[p], i) + (unsigned long long)pw[i - q[p] + 1] * get(i - len + 1, q[p] - 1);
    }
    sort(rt + 1, rt + cnt + 1);
    int best = 0, cur = 1;
    rt[cnt + 1] = rt[cnt] + 1;
    for (int i = 1; i <= cnt; ++i)
        if (rt[i] == rt[i + 1])
            ++cur;
        else {
            if (cur > best)
                best = cur;
            cur = 1;
        }
    printf("%d\n", best);
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int M;
    scanf("%d%d\n", &N, &M);
    gets(x + 1);
    for (int i = N; i >= 1; --i)
        H[i] = x[i] + B * H[i + 1];
    pw[0] = 1;
    for (int i = 1; i <= N; ++i)
        pw[i] = pw[i - 1] * B;
    for (int i = 1; i <= M; ++i) {
        int tmp;
        scanf("%d", &tmp);
        solve(tmp);
    }

    return 0;
}
