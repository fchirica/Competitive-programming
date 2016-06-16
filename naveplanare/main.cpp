/* Hai da-te-n pizda ma-tii
   Hai da-te-n gatul ma-tii
   Flooooow
   Floooooooow
*/

#include <bits/stdc++.h>

using namespace std;

const int kNMax = 2500;

class MaxFlowMinCost {
  public:
    void addEdge(int s, int t, int cap, int cost) {
        int index1 = all_edges.size();
        int index2 = all_edges.size() + 1;
        all_edges.push_back(flow_edge(s, t, cap, cost));
        all_edges.push_back(flow_edge(t, s, 0, -cost));
        neigh[s].push_back(make_pair(index1, index2));
        neigh[t].push_back(make_pair(index2, index1));
    }
    int getFlow() {
        return flow;
    }
    int getCost() {
        return cost;
    }
    MaxFlowMinCost(int _n, int s, int t) {
        flow = 0;
        cost = 0;
        n = _n;
        SOURCE = s;
        SINK = t;
    }
    void runFlow() {
        solve();
    }

  private:
    int flow;
    int cost;
    int n;
    int SOURCE;
    int SINK;

    struct flow_edge {
        int s;
        int t;
        int flow;
        int cap;
        int cost;

        flow_edge(int _s, int _t, int _cap, int _cost) {
            s = _s;
            t = _t;
            cap = _cap;
            cost = _cost;
            flow = 0;
        }
    };

    vector <flow_edge> all_edges;
    vector <pair <int, int> > neigh[kNMax]; //index of current edge, index of residual edge

    int dist[kNMax], in_queue[kNMax];
    pair <int, int> parent[kNMax];

    bool BellmanFord() {
        queue <int> Q;

        for (int i = 0; i <= n; ++i) {
            dist[i] = 1 << 30;
            in_queue[i] = 0;
        }

        Q.push(SOURCE);
        dist[SOURCE] = 0;

        while (!Q.empty()) {
            int nod = Q.front();
            Q.pop();
            in_queue[nod] = 0;

            vector <pair <int, int> > :: iterator it;
            for (it = neigh[nod].begin(); it != neigh[nod].end(); ++it) {
                flow_edge cur = all_edges[it -> first];
                if (cur.flow < cur.cap && dist[cur.t] > dist[cur.s] + cur.cost) {
                    dist[cur.t] = dist[cur.s] + cur.cost;
                    parent[cur.t].first = it -> first;
                    parent[cur.t].second = it -> second;
                    if (!in_queue[cur.t]) {
                        in_queue[cur.t] = 1;
                        Q.push(cur.t);
                    }
                }
            }
        }
        return dist[SINK] != (1 << 30);
    }

    void solve() {
        while (BellmanFord()) {
            int nod = SINK;
            int fmin = 1 << 30;
            while (nod != SOURCE) {
                int fcur = all_edges[parent[nod].first].cap - all_edges[parent[nod].first].flow;
                if (fcur < fmin)
                    fmin = fcur;
                nod = all_edges[parent[nod].first].s;
            }
            nod = SINK;
            while (nod != SOURCE) {
                all_edges[parent[nod].first].flow += fmin;
                all_edges[parent[nod].second].flow -= fmin;
                nod = all_edges[parent[nod].first].s;
            }
            flow += fmin;
            cost += fmin * dist[SINK];
        }
    }
};

int x[kNMax], y[kNMax];

int solve(int a[], int n, int k) {
    int lim_inf = a[1], lim_sup = a[1];
    for (int i = 2; i <= n; ++i) {
        lim_inf = min(lim_inf, a[i]);
        lim_sup = max(lim_sup, a[i]);
    }
    lim_inf -= k;
    lim_sup += k;
    int sink = 4 + n + lim_sup - lim_inf;
    MaxFlowMinCost flowSolver(sink, 0, sink);
    flowSolver.addEdge(0, 1, k, 0);
    for (int i = 1; i <= n; ++i) {
        flowSolver.addEdge(1, i + 1, 1, 0);
        flowSolver.addEdge(i + 1, a[i] - lim_inf + n + 2, 1, 0);
    }
    for (int i = n + 3; i <= n + 3 + lim_sup - lim_inf; ++i) {
        flowSolver.addEdge(i, i - 1, 100000, 1);
        flowSolver.addEdge(i - 1, i, 100000, 1);
    }
    for (int i = n + 2; i <= n + 3 + lim_sup - lim_inf; ++i)
        flowSolver.addEdge(i, sink, 1, 0);
    flowSolver.runFlow();
    return flowSolver.getCost();
}

int main() {
    freopen("naveplanare.in", "r", stdin);
    freopen("naveplanare.out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    printf("%d", solve(x, n, k) + solve(y, n, k));
    return 0;
}
