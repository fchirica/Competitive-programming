#include <vector>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

#define DBG(val) cerr<<#val<<" = "<<(val)<<"\n"
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

class StringsNightmareAgain {
public:
	long long UniqueSubstrings(int, int, int, int, int);
};

char x[100010];
int SA[18][100010], ord[100010], nxt[100010], lcp[100010], lcpRMQ[17][100010], minPos[17][100010], maxPos[17][100010], Lg[100010];
long long key[100010];

struct comp {
	inline bool operator () (int A, int B) {
		return key[A] < key[B];
	}
};

int maxPower;

void suffixArrays(int n) {
	for (int i = 1; i <= n; ++i)
		SA[0][i] = (x[i] == 'a') ? 1 : 2;
	for (int pw = 1; (1 << pw) <= 2 * n; ++pw) {
		int power = 1 << (pw - 1);
		maxPower = pw;
		for (int j = 1; j <= n; ++j) {
			key[j] = (long long)SA[pw - 1][j] * max((n + 1), 300);
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

int getLcp(int pref1, int pref2) {
	if (pref1 > pref2)
		swap(pref1, pref2);
    if (pref1 == pref2)
        return 1000000000;
	--pref2;
	int pw = Lg[pref2 - pref1 + 1];
	return min(lcpRMQ[pw][pref1], lcpRMQ[pw][pref2 - (1 << pw) + 1]);
}

int compute(int xx, int yy) {
	int len = Lg[yy - xx + 1];
	int minIdx = min(minPos[len][xx], minPos[len][yy - (1 << len) + 1]);
	int maxIdx = max(maxPos[len][xx], maxPos[len][yy - (1 << len) + 1]);
	return maxIdx - minIdx;
}

void buildRMQ(int n) {
	for (int i = 2; i <= n; ++i)
		Lg[i] = Lg[i / 2] + 1;
	for (int i = 1; i <= n; ++i) {
		lcpRMQ[0][i] = lcp[i];
		minPos[0][i] = ord[i];
		maxPos[0][i] = ord[i];
	}
	for (int pw = 1; (1 << pw) <= n; ++pw)
		for (int i = 1; i <= n; ++i) {
			int power = 1 << (pw - 1);
			if (i + power - 1 > n)
				break;
			lcpRMQ[pw][i] = min(lcpRMQ[pw - 1][i], lcpRMQ[pw - 1][i + power]);
			minPos[pw][i] = min(minPos[pw - 1][i], minPos[pw - 1][i + power]);
			maxPos[pw][i] = max(maxPos[pw - 1][i], maxPos[pw - 1][i + power]);
		}
}

long long solve(int n) {
	long long res = 0;
	for (int i = 1; i < n; ++i) {
		int st = 1, dr = i, lo = i, want = lcp[i];
		while (st <= dr) {
			int med = (st + dr) / 2;
			if (getLcp(med, i) >= want) {
				lo = med;
				dr = med - 1;
			} else
				st = med + 1;
		}
		st = i; dr = n;
		int hi = i;
		while (st <= dr) {
			int med = (st + dr) / 2;
			if (getLcp(med, i) >= want) {
				hi = med;
				st = med + 1;
			} else
				dr = med - 1;
		}
		int curL = compute(lo, hi);
		chmin(curL, want);
		if (i + 1 < n)
            res += max(0, curL - lcp[i + 1]);
        else
            res += curL;
	}
	return res;
}

long long StringsNightmareAgain::UniqueSubstrings(int a, int b, int c, int d, int n) {
	string S = "";
	for (int i = 0; i < n; ++i)
		S += 'a';
	for (int i = 0; i < a; ++i) {
		b = ((long long)b * c + d) % n;
		S[b] = 'b';
	}
	for (int i = 0; i < n; ++i)
		x[i + 1] = S[i];

	suffixArrays(n);
	kasai(n);
	buildRMQ(n);

	return solve(n);
}
