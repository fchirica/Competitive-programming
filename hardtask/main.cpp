//Florin Chirica

#include <bits/stdc++.h>

using namespace std;

const int kNMax = 100010 + 10;

vector <int> G[kNMax];
int edge[kNMax], cost[kNMax];

bool vis_l[kNMax];
int cntLin, lin[2 * kNMax];
int first_lin[kNMax], last_lin[kNMax];
int cntEuler, euler[2 * kNMax], height[kNMax];
int first_euler[kNMax];
int lg[2 * kNMax];
long long AIB[2 * kNMax];

int rmq[18][2 * kNMax];

void dfs_lin(int nod, int myHeight) {
    vis_l[nod] = 1;
    lin[++cntLin] = nod;
    euler[++cntEuler] = nod;
    first_euler[nod] = cntEuler;
    height[nod] = myHeight;
    first_lin[nod] = cntLin;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis_l[*it]) {
            dfs_lin(*it, myHeight + 1);
            euler[++cntEuler] = nod;
        }
    lin[++cntLin] = nod;
    last_lin[nod] = cntLin;
}

inline int lsb(int foo) {
    return foo & -foo;
}

void update_AIB(int nod, int val) {
    for (; nod <= cntLin; nod += lsb(nod))
        AIB[nod] += val;
}

long long path_cost(int nod) {
    long long ans = 0;
    for (int pos = first_lin[nod]; pos > 0; pos -= lsb(pos))
        ans += AIB[pos];
    return ans;
}

void update_edge(int nod, int newCost) {
    int oldCost = edge[nod];
    edge[nod] = newCost;
    update_AIB(first_lin[nod], newCost - oldCost);
    update_AIB(last_lin[nod], oldCost - newCost);
}

void load_lca() {
    for (int i = 1; i <= cntEuler; ++i)
        rmq[0][i] = euler[i];
    for (int pw = 1; (1 << pw) <= cntEuler; ++pw)
        for (int i = 1; i + (1 << pw) - 1 <= cntEuler; ++i) {
            int nod1 = rmq[pw - 1][i];
            int nod2 = rmq[pw - 1][i + (1 << (pw - 1))];
            if (height[nod1] < height[nod2])
                rmq[pw][i] = rmq[pw - 1][i];
            else
                rmq[pw][i] = rmq[pw - 1][i + (1 << (pw - 1))];
        }
    for (int i = 2; i <= cntEuler; ++i)
        lg[i] = lg[i / 2] + 1;
}

int LCA(int nod1, int nod2) {
    int pos1 = first_euler[nod1];
    int pos2 = first_euler[nod2];
    if (pos1 > pos2)
        swap(pos1, pos2);
    int step = lg[pos2 - pos1 + 1];
    int best1 = rmq[step][pos1];
    int best2 = rmq[step][pos2 - (1 << step) + 1];
    if (height[best1] < height[best2])
        return best1;
    return best2;
}

int mod;
vector <int> my_q;

vector <int> memo;
long long small_cost[kNMax];
int marked[kNMax];

long long get_cost_small_case(int nod) {
    if (marked[nod])
        return small_cost[nod];
    marked[nod] = 1;
    memo.push_back(nod);
    small_cost[nod] = path_cost(nod);
    return small_cost[nod];
}

long long solveSmall() {
    long long res = 0;
    for (int i = 0; i < my_q.size(); ++i)
        for (int j = i + 1; j < my_q.size(); ++j) {
            int nod1 = my_q[i];
            int nod2 = my_q[j];
            int dad = LCA(nod1, nod2);
            long long myCost = get_cost_small_case(nod1);
            myCost += get_cost_small_case(nod2);
            myCost -= 2 * get_cost_small_case(dad);
            if (myCost % mod == 0)
                ++res;
        }
    for (int i = 0; i < memo.size(); ++i)
        marked[memo[i]] = 0;
    memo.clear();
    return res;
}

long long sumPath[kNMax];
bool vis[kNMax];

void dfs(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            sumPath[*it] = (sumPath[nod] + edge[*it]) % mod;
            dfs(*it);
        }
}

map <int, int> M[kNMax];
long long answer;
int where[kNMax];
int weight[kNMax];

int n;

void dfs_solve(int nod) {
    vector <int> :: iterator it;
    vector <int> sons;
    vis[nod] = 1;
    int biggest = 0;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it]) {
            sons.push_back(*it);
            dfs_solve(*it);
            if (weight[where[*it]] > weight[where[biggest]])
                biggest = *it;
        }
    if (biggest) {
        for (it = sons.begin(); it != sons.end(); ++it)
            if (*it != biggest && weight[where[*it]]) {
                int my_map = where[*it];
                int big_map = where[biggest];
                map <int, int> :: iterator it;
                for (it = M[my_map].begin(); it != M[my_map].end(); ++it) {
                    int need = (2 * sumPath[nod] - it -> first + mod) % mod;
                    answer += (long long) it -> second * M[big_map][need];
                }
                for (it = M[my_map].begin(); it != M[my_map].end(); ++it)
                    M[big_map][it -> first] += it -> second;
                weight[big_map] += weight[my_map];
            }
        }
    if (where[nod]) {
        if (!biggest) {
            biggest = nod;
            return ;
        }
        answer += M[where[biggest]][sumPath[nod]];
        ++M[where[biggest]][sumPath[nod]];
        ++weight[where[biggest]];
    }
    where[nod] = where[biggest];
}

long long solveLarge() {
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for (int i = 0; i < my_q.size(); ++i) {
        ++M[my_q[i]][sumPath[my_q[i]]];
        ++weight[my_q[i]];
        where[my_q[i]] = my_q[i];
    }
    answer = 0;
    memset(vis, 0, sizeof(vis));
    dfs_solve(1);
    memset(where, 0, sizeof(where));
    for (int i = 0; i < my_q.size(); ++i) {
        weight[my_q[i]] = 0;
        M[my_q[i]].clear();
    }
    return answer;
}

int main() {
    freopen("hardtask.in", "r", stdin);
    freopen("hardtask.out", "w", stdout);

    int m, lim;
    scanf("%d%d", &n, &m);
    lim = 400;
    for (int i = 2; i <= n; ++i) {
        int dad;
        scanf("%d%d", &dad, &cost[i]);
        G[dad].push_back(i);
    }
    dfs_lin(1, 0);
    load_lca();
    for (int i = 2; i <= n; ++i)
        update_edge(i, cost[i]);
    for (int i = 1; i <= m; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int my_nod, my_cost;
            scanf("%d%d", &my_nod, &my_cost);
            update_edge(my_nod, my_cost);
        } else {
            my_q.clear();
            int cnt;
            scanf("%d%d", &cnt, &mod);
            for (int j = 1; j <= cnt; ++j) {
                int foo;
                scanf("%d", &foo);
                my_q.push_back(foo);
            }
            long long res;
            if (cnt <= lim)
                res = solveSmall();
            else
                res = solveLarge();
            printf("%lld\n", res);
        }
    }
    return 0;
}
