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

pair <string, int> words[100100];
char tmp[100100];
int type[100100], pos[100100], val[100100], used[100100], aint[4 * 100100], ret[100100];

bool comp(pair <string, int> A, pair <string, int> B) {
        if (A.x.sz() == B.x.sz())
            return A.x < B.x;
        return A.x.sz() < B.x.sz();
}

void add(int st, int dr, int nod, int wanted) {
    ++aint[nod];
    if (st >= dr)
        return ;
    int med = (st + dr) / 2;
    if (wanted <= med)
        add(st, med, 2 * nod, wanted);
    else
        add(med + 1, dr, 2 * nod + 1, wanted);
}

int query(int st, int dr, int nod, int left) {
    if (st == dr)
        return st;
    int med = (st + dr) / 2;
    if (aint[2 * nod] >= left)
        return query(st, med, 2 * nod, left);
    else
        return query(med + 1, dr, 2 * nod + 1, left - aint[2 * nod]);
}

int main() {
    freopen("nums.in", "r", stdin);
    freopen("nums.out", "w", stdout);

    int N, cnt = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d ", &type[i]);
        if (type[i] == 1) {
            gets(tmp);
            words[++cnt] = mp(string(tmp), i);
        } else
            scanf("%d", &pos[i]);
    }

    sort(words + 1, words + cnt + 1, comp);
    for (int i = 1; i <= cnt; ++i) {
        if (words[i].x == words[i - 1].x)
            val[words[i].y] = val[words[i - 1].y];
        else
            val[words[i].y] = val[words[i - 1].y] + 1;
        ret[val[words[i].y]] = i;
    }


    for (int i = 1; i <= N; ++i)
        if (type[i] == 1) {
            int cur = val[i];
            if (used[cur])
                continue;
            used[cur] = 1;
            add(1, cnt, 1, cur);
        } else {
            int idx = ret[query(1, cnt, 1, pos[i])];
            printf("%s\n", words[idx].x.c_str());
        }

    return 0;
}
