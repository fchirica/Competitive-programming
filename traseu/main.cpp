/* Eu sunt adevaratul Teodor Ionescu, cel de mai jos este doar o facatura nerusinata... */

#include <bits/stdc++.h>

using namespace std;

const int kNMax = 100;

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

int in[kNMax], out[kNMax];

int main() {
    freopen("traseu.in", "r", stdin);
    freopen("traseu.out", "w", stdout);

    int n, m, res = 0;
    scanf("%d%d", &n, &m);

    MaxFlowMinCost flowSolver(n + 1, 0, n + 1);
    for (int i = 1; i <= m; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        res += cc;
        ++out[xx];
        ++in[yy];
        flowSolver.addEdge(xx, yy, 1000000, cc);
    }

    for (int i = 1; i <= n; ++i) {
        if (out[i] < in[i])
            flowSolver.addEdge(0, i, in[i] - out[i], 0);
        if (in[i] < out[i])
            flowSolver.addEdge(i, n + 1, out[i] - in[i], 0);
    }

    flowSolver.runFlow();
    res += flowSolver.getCost();
    printf("%d", res);
    return 0;
}
