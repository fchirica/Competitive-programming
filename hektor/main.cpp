//Florin Chirica

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int cost[100010];

vector <int> G[100010];

int dp1[100010];
double dp2[100010];
bool vis[100010];

void go(int nod) {
    if (nod == b) {
        dp1[nod] = 1;
        dp2[nod] = cost[nod];
        return ;
    }
    vis[nod] = 1;
    vector <int> :: iterator it;
    int sons = 0;
    double sum = 0;
    for (it = G[nod].begin(); it != G[nod].end(); ++it) {
        if (!vis[*it])
            go(*it);
        if (dp1[*it]) {
            ++sons;
            sum += dp2[*it];
        }
    }
    if (sons > 0) {
        dp1[nod] = 1;
        dp2[nod] = ((double) 1 / sons) * sum + cost[nod];
    }
}

int main() {
    freopen("hektor.in", "r", stdin);
    freopen("hektor.out", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &cost[i]);
    for (int i = 1; i <= m; ++i) {
        int foo, bar;
        scanf("%d%d", &foo, &bar);
        G[foo].push_back(bar);
    }
    go(a);
    printf("%.7lf", dp2[a]);
    return 0;
}
