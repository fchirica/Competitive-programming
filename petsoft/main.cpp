#include <bits/stdc++.h>

using namespace std;

const int kNmax = 1001;

vector <int> G[kNmax];
int dp[2][kNmax];
bool vis[kNmax];
int innerDP0[kNmax][kNmax], innerDP1[kNmax][kNmax];

inline void chmax(int &A, int B) {
    if (A < B)
        A = B;
}

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> sons;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            dfs(*it);
            sons.push_back(*it);
        }
    sort(sons.begin(), sons.end());
    if (sons.size() == 0) {
        dp[0][nod] = 0;
        dp[1][nod] = 0;
        return ;
    }
    for (int i = 0; i < sons.size(); ++i)
        for (int j = 0; j < sons.size(); ++j)
            innerDP0[i][j] = innerDP1[i][j] = 0;
    for (int i = 0; i < sons.size(); ++i) {
        int currentSon = sons[i];
        innerDP0[i][i] = max(dp[0][currentSon], dp[1][currentSon]);
        innerDP1[i][i] = abs(nod - currentSon) + dp[0][currentSon];
    }
    for (int d = 1; d < sons.size(); ++d)
        for (int i = 0; i < sons.size(); ++i) {
            int j = i + d;
            if (j == sons.size())
                break;
            //pair them
            innerDP0[i][j] = abs(sons[i] - sons[j]) + innerDP0[i + 1][j - 1] + dp[0][sons[i]] + dp[0][sons[j]];
            innerDP1[i][j] = abs(sons[i] - sons[j]) + innerDP1[i + 1][j - 1] + dp[0][sons[i]] + dp[0][sons[j]];
            //i unpaired
            int mySon = sons[i];
            chmax(innerDP0[i][j], (max(dp[0][mySon], dp[1][mySon]) + innerDP0[i + 1][j]));
            chmax(innerDP1[i][j], (max(dp[0][mySon], dp[1][mySon]) + innerDP1[i + 1][j]));
            chmax(innerDP1[i][j], (abs(nod - mySon) + innerDP0[i + 1][j]));
            //j unpaired
            mySon = sons[j];
            chmax(innerDP0[i][j], (max(dp[0][mySon], dp[1][mySon]) + innerDP0[i][j - 1]));
            chmax(innerDP1[i][j], (max(dp[0][mySon], dp[1][mySon]) + innerDP1[i][j - 1]));
            chmax(innerDP1[i][j], (abs(nod - mySon) + innerDP0[i][j - 1]));
        }
    dp[0][nod] = innerDP0[0][sons.size() - 1];
    dp[1][nod] = innerDP1[0][sons.size() - 1];
}

int main() {
    freopen("petsoft.in", "r", stdin);
    freopen("petsoft.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int father;
        scanf("%d", &father);
        G[father].push_back(i);
    }

    dfs(1);
    printf("%d", dp[0][1]);
    return 0;
}
