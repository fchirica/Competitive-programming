#include <bits/stdc++.h>

using namespace std;

int a, b, c, n, k;
int invers;

int cnt[500500];
bool used[500500];

int putere(int A, int B) {
    if (B == 0)
        return 1;
    int res = putere(A, B / 2);
    res = static_cast <long long> (res) * res % c;
    if (B % 2)
        res = static_cast <long long> (res) * A % c;
    return res;
}

bool flagged;

inline int goNext(int i, int prev) {
    return (static_cast <long long> (prev) * a + static_cast <long long> (b) * i) % c;
}

inline int goPrev(int i, int cur) {
    if (flagged) {
        if (i == 2)
            return 1;
        return (static_cast <long long> (b) * (i - 1)) % c;
    }
    int val = cur - (static_cast <long long> (b) * i) % c;
    if (val < 0)
        val += c;
    val = static_cast <long long> (val) * invers % c;
    return val;
}

int main() {
    freopen("reg.in", "r", stdin);
    freopen("reg.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &n, &k);
        invers = putere(a, c - 2);

        flagged = 0;
        if (a % c == 0)
            flagged = 1;

        cnt[1] = 1;
        int prev = 1;
        for (int i = 2; i <= n; ++i) {
            prev = goNext(i, prev);
            ++cnt[prev];
            }
        int reg = 0, from_right = prev;
        int val = 1, ptr_left = 1, ptr_right = n, res;
        while (ptr_left <= ptr_right) {
            if (!used[val]) {
                if (reg < k) {
                    ++reg;
                    used[val] = 1;
                } else {
                    while (ptr_right >= ptr_left) {
                        --cnt[from_right];
                        if (used[from_right] && cnt[from_right] == 0) {
                            used[val] = 1;
                            break;
                        }
                        from_right = goPrev(ptr_right, from_right);
                        --ptr_right;
                    }
                    from_right = goPrev(ptr_right, from_right);
                    --ptr_right;
                }
            }

            if (ptr_left <= ptr_right)
                res = ptr_left;
            --cnt[val];
            if (cnt[val] == 0)
                --reg;
            val = goNext(ptr_left + 1, val);
            ++ptr_left;
        }

        printf("%d\n", res);
        for (int i = 0; i <= c; ++i)
            used[i] = 0;
    }

    return 0;
}
