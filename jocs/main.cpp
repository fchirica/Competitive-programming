#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <assert.h>

using namespace std;

char x[100010];
int SA[18][100010], ord[100010], nxt[100010], lcp[100010];
long long key[100010];

struct comp {
	inline bool operator () (int A, int B) {
		return key[A] < key[B];
	}
};

int maxPower;

void suffixArrays(int n) {
	for (int i = 1; i <= n; ++i)
		SA[0][i] = x[i] - 'a' + 1;
	for (int pw = 1; (1 << pw) <= 2 * n; ++pw) {
		int power = 1 << (pw - 1);
		maxPower = pw;
		for (int j = 1; j <= n; ++j) {
			key[j] = (long long)SA[pw - 1][j] * max(5000, n + 100);
			if (j + power <= n)
				key[j] += SA[pw - 1][j + power];
			ord[j] = j;
		}
		sort(ord + 1, ord + n + 1, comp());
		int cnt = 0;
		SA[pw][ord[1]] = ++cnt;
		for (int j = 2; j <= n; ++j) {
			int curIdx = ord[j];
			int lastIdx = ord[j - 1];
			if (key[curIdx] != key[lastIdx])
				++cnt;
			SA[pw][curIdx] = cnt;
		}
	}
}

void kasai(int n) {
	for (int i = 1; i <= n; ++i)
		ord[SA[maxPower][i]] = i;
	for (int i = 1; i < n; ++i)
		nxt[ord[i]] = ord[i + 1];
	nxt[ord[n]] = -1;

	int currentLCP = 0;
	for (int i = 1; i <= n; ++i) {
		if (nxt[i] == -1)
			continue;
		for (; currentLCP == 0 || x[i + currentLCP - 1] == x[nxt[i] + currentLCP - 1]; ++currentLCP);
		--currentLCP;
		lcp[SA[maxPower][i]] = currentLCP;
		--currentLCP;
		if (currentLCP < 0)
			currentLCP = 0;
	}
}

int st[100100], lft[100100], rgt[100100];

void solve(int n, int k) {
    int u = 0;
    st[0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (u > 0 && lcp[st[u]] >= lcp[i])
            --u;
        st[++u] = i;
        lft[i] = st[u - 1];
    }

    u = 0;
    st[0] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (u > 0 && lcp[st[u]] >= lcp[i])
            --u;
        st[++u] = i;
        rgt[i] = st[u - 1];
    }

    int res = 0, _st, dr;
    for (int i = 1; i <= n; ++i)
        if (lcp[i] >= k) {
            int cur = rgt[i] - lft[i] + lcp[i];
            if (cur > res) {
                res = cur;
                _st = ord[i]; dr = ord[i] + lcp[i] - 1;
            }
        }
    printf("%d\n%d %d\n", res, _st, dr);
}

int main() {
    freopen("jocs.in", "r", stdin);
    freopen("jocs.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d\n", &n, &k);
        gets(x + 1);

        suffixArrays(n);
        kasai(n);
        solve(n - 1, k);
    }
}
