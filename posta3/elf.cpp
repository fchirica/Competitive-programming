#include <stdio.h>
#include <vector>

using namespace std;

const int kNmax = 3001;

int father[kNmax];
vector <int> G[kNmax];
bool onPath[kNmax];
int dp[kNmax][kNmax], val[kNmax];

int main() {
    freopen("posta3.in", "r", stdin);
    freopen("posta3.out", "w", stdout);

    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i < n; ++i) {
        int dad, son;
        scanf("%d%d", &dad, &son);
        father[son] = dad;
        G[dad].push_back(son);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);

    for (int nod = x; nod; nod = father[nod])
        onPath[nod] = 1;

    for (int nod = 1; nod != x; ) {
        int newNode;
        vector <int> :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (onPath[*it])
                newNode = *it;

        int minPrefix = 1 << 30;
        for (int j = 1; j <= n; ++j) {
            if (dp[nod][j] < minPrefix)
                minPrefix = dp[nod][j];

            int cost = 0;
            for (it = G[nod].begin(); it != G[nod].end(); ++it)
                if (!onPath[*it])
                    if (val[*it] > j)
                        ++cost;
            if (val[newNode] < j)
                ++cost;

            dp[newNode][j] = minPrefix + cost;
        }

        nod = newNode;
    }

    int res = 1 << 30;
    for (int i = 1; i <= n; ++i)
        if (dp[x][i] < res)
            res = dp[x][i];

    printf("%d", res);
    return 0;
}
