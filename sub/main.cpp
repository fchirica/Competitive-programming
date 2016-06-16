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

struct trie {
    short cnt, lastMarked;
    int ap[26];

    trie() {
        cnt = lastMarked = 0;
        for (int i = 0; i < 26; ++i)
            ap[i] = 0;
    }
};

vector <trie> T;

char tmp[355];

void baga(int nod, int pos, int cnt, int idx) {
    if (pos == cnt + 1)
        return ;
    int nextNod = T[nod].ap[tmp[pos] - 'a'];
    if (nextNod == 0) {
        trie emptyNod;
        int ret = T.sz();
        T.pb(emptyNod);
        nextNod = T[nod].ap[tmp[pos] - 'a'] = ret;
    }
    bool good = true;
    if (T[nextNod].cnt < idx - 1)
        good = false;
    if (good)
        baga(nextNod, pos + 1, cnt, idx);
    if (T[nextNod].lastMarked < idx) {
        T[nextNod].lastMarked = idx;
        ++T[nextNod].cnt;
    }
}

void scoate(int nod, int pos, int cnt) {
    if (pos == cnt + 1)
        return ;
    int nextNod = T[nod].ap[tmp[pos] - 'a'];
    if (!nextNod)
        return ;
    scoate(nextNod, pos + 1, cnt);
    --T[nextNod].cnt;
}

int need;

int dfs(int nod) {
    int res = 0;
    if (T[nod].cnt == need)
        ++res;
    for (int i = 0; i < 26; ++i)
        if (T[nod].ap[i])
            res += dfs(T[nod].ap[i]);
    return res;
}

int main() {
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);

    int NA;
    scanf("%d\n", &NA);

    trie emptyNod;
    T.pb(emptyNod);

    for (int i = 1; i <= NA; ++i) {
        gets(tmp + 1);
        int n = strlen(tmp + 1);
        for (int j = 1; j <= n; ++j)
            baga(0, j, n, i);
    }

    int NB;
    scanf("%d\n", &NB);
    for (int i = 1; i <= NB; ++i)  {
        gets(tmp + 1);
        int n = strlen(tmp + 1);
        for (int j = 1; j <= n; ++j)
            scoate(0, j, n);
    }

    need = NA;
    printf("%d", dfs(0));
    return 0;
}
