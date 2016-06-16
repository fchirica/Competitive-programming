#include <vector>
#include <map>
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

template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

using namespace std;

char tmp[111];
pair <string, bool> x[2 * 11111];
int prev[2 * 11111], next[2 * 11111];
bool doned[2 * 11111];

struct shirt {
    int fi, se, cnt;
};

class comp {
    public: inline bool operator () (shirt A, shirt B) {
        return A.cnt > B.cnt;
    }
};

multiset <shirt, comp> H;

int lcp(int i, int j) {
    int cnt = 0;
    REP(k, 0, min(x[i].first.size(), x[j].first.size()) - 1)
        if (x[i].first[k] == x[j].first[k])
            ++cnt;
        else
            break;
    return cnt;
}

int main() {
    while (1) {
        int n;
        scanf("%d\n", &n);
        if (n == -1)
            break;
        int cnt = 0;
        FOR(i, n) {
            scanf("%s ", &tmp);
            x[++cnt] = make_pair(string(tmp), 0);
        }
        FOR(i, n) {
            scanf("%s ", &tmp);
            x[++cnt] = make_pair(string(tmp), 1);
        }
        sort(x + 1, x + 2 * n + 1);
        FOR(i, 2 * n) {
            prev[i] = i - 1;
            next[i] = i + 1;
            doned[i] = 0;
            if (i < 2 * n && x[i].second != x[i + 1].second) {
                shirt tmp;
                tmp.fi = i;
                tmp.se = i + 1;
                tmp.cnt = lcp(i, i + 1);
                H.insert(tmp);
            }
        }
        int win = 0;
        while (!H.empty()) {
            shirt cur = *H.begin();
            H.erase(H.begin());
            if (doned[cur.fi])
                continue;
            if (next[cur.fi] != cur.se)
                continue;
            win += cur.cnt;
            doned[cur.fi] = doned[cur.se] = 1;
            int newNext = next[cur.se];
            int newPrev = prev[cur.fi];
            next[newPrev] = newNext;
            prev[newNext] = newPrev;
            if (newPrev >= 1 && newNext <= 2 * n)
                if (x[newPrev].second != x[newNext].second) {
                    shirt tmp;
                    tmp.cnt = lcp(newPrev, newNext);
                    tmp.fi = newPrev;
                    tmp.se = newNext;
                    H.insert(tmp);
                }
        }
        printf("%d\n", win);
    }

    return 0;
}
