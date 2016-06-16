//sursa veche ftw $$$

#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#define lint long long
#define pi pair <int, lint>

using namespace std;

const int N = 100050;

struct line { lint k, c; } S[N];
int St;

inline double gt2 (line p, lint x) { return p.k * (double)x + double(p.c); }
inline double gt1 (line x, line y) { return gt2(y, double(y.c - x.c) / double(x.k - y.k)); }

int search1 (line cur, int l, int r)
{
    if (r - l < 4) {
        int id = l;
        for (int i = l + 1; i <= r; ++i)
            if (gt1(cur, S[i]) < gt1(cur, S[id])) id = i;
        return id;
    }
    int m = (l + r) >> 1, mr = (m + r) >> 1;
    double x = gt1(cur, S[m]), y = gt1(cur, S[mr]);
    if (x > y) return search1(cur, m, r);
    else return search1(cur, l, mr);
}
int search2 (lint x, int l, int r)
{
    if (r - l < 4) {
        int id = l;
        for (int i = l + 1; i <= r; ++i)
            if (gt2(S[i], x) < gt2(S[id], x)) id = i;
        return id;
    }
    int m = (l + r) >> 1, mr = (m + r) >> 1;
    double a = gt2(S[m], x), b = gt2(S[mr], x);
    if (a > b) return search2(x, m, r);
    else return search2(x, l, mr);
}

lint f[N], sp[N], dist[N], sst[N];
stack<line> R;
stack<int> top;
vector<pi> e[N];

inline void insert (int i) {
    line nl = (line){-dist[i], f[i]};
    int ps = search1(nl, 1, St);
    top.push(St); R.push(S[ps + 1]);
    S[St = ps + 1] = nl;
}
inline void restore (int i) {
    S[St] = R.top(); R.pop();
    St = top.top(); top.pop();
}

int vis[N];
stack<pair<int, vector<pi>::iterator> > tHeap;

void traverse ()
{
    tHeap.push(make_pair(1, e[1].begin()));
    vis[1] = true;
    while (!tHeap.empty())
    {
        int u = tHeap.top().first, v;
        vector<pi>::iterator &it = tHeap.top().second;
        if (it == e[u].end()) { tHeap.pop(); restore(u); continue; }
        if (it == e[u].begin())
        {
            if (u != 1)
            {
                int i = search2(sp[u], 1, St);
                f[u] = S[i].c + sp[u] * (dist[u] + S[i].k) + sst[u];
            }
            insert(u);
        }
        v = it->first;
        if (!vis[v])
        {
            dist[v] = dist[u] + it->second;
            tHeap.push(make_pair(v, e[v].begin()));
            vis[v] = true;
        }
        ++it;
    }
}

int main ()
{
    freopen("harbingers.in", "r", stdin);
    freopen("harbingers.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        long long c;
        scanf("%d%d%lld", &a, &b, &c);
        e[a].push_back(pi(b, c));
        e[b].push_back(pi(a, c));
    }
    for (int i = 2; i <= n; ++i)
        scanf("%lld%lld", &sst[i], &sp[i]);
    traverse();
    for (int i = 2; i <= n; ++i)
        printf("%lld ", f[i]);

    return 0;
}
