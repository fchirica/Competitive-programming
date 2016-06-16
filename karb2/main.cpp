#include <stdio.h>
#include <vector>

using namespace std;

bool special[100100], vis[100100];
vector <int> G[100100];

const int mod = 666013;
int fromSons[100100], fromParents[100100], seen[2 * 666013];

int fastPow(int A, int B) {
    if (B == 0)
        return 1;
    int res = fastPow(A, B / 2);
    res = (long long)res * res % mod;
    if (B & 1)
        res = (long long)res * A % mod;
    return res;
}

int invers(int X) {
    if (seen[X])
        return seen[X];
    return seen[X] = fastPow(X, mod - 2);
}

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> sons;
    for (vector <int> :: iterator it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            sons.push_back(*it);
        }
    if (special[nod]) {
        fromParents[nod] = 0;
        fromSons[nod] = 1;
        for (vector <int> :: iterator it = sons.begin(); it != sons.end(); ++it)
            fromSons[nod] = fromSons[nod] * ((long long)fromSons[*it] + fromParents[*it]) % mod;
    } else {
        fromParents[nod] = 1;
        for (vector <int> :: iterator it = sons.begin(); it != sons.end(); ++it)
            fromParents[nod] = fromParents[nod] * ((long long)fromSons[*it] + fromParents[*it]) % mod;
        fromSons[nod] = 0;
        for (vector <int> :: iterator it = sons.begin(); it != sons.end(); ++it) {
            int waysCurrentSon = (long long)fromParents[nod] * invers(fromParents[*it] + fromSons[*it]) % mod;
            waysCurrentSon = (long long)waysCurrentSon * fromSons[*it] % mod;
            fromSons[nod] = (fromSons[nod] + waysCurrentSon) % mod;
        }
    }
}

int main() {
    freopen("karb2.in", "r", stdin);
    freopen("karb2.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        int xx;
        scanf("%d", &xx);
        special[xx] = true;
    }
    for (int i = 1; i < n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    printf("%d", fromSons[1]);
    return 0;
}
