//Florin Chirica

#include <bits/stdc++.h>

using namespace std;

const int kNMax = 1200;

int n, m;
int st[kNMax], dr[kNMax], nr[kNMax];

class MaxFlow {
  public:
    void addEdge(int xx, int yy, int cap) {
        int index1 = m_edges.size();
        int index2 = m_edges.size() + 1;
        m_edges.push_back(flow_edge(xx, yy, cap, index2));
        m_edges.push_back(flow_edge(yy, xx, 0, index1));
        m_graph[xx].push_back(index1);
        m_graph[yy].push_back(index2);
    }

    int solve(int source, int sink) {
        answer = 0;
        while (bfs(source, sink))
            answer += augment(source, sink);
        return answer;
    }
    void reset() {
        for (int i = 0; i < (int) m_edges.size(); ++i)
            m_graph[m_edges[i].from].clear();
        m_edges.clear();
    }

  private:
    struct flow_edge {
        int from;
        int to;
        int cap;
        int flow;
        int rev_edge;

        flow_edge() {

        }

        flow_edge(int _from, int _to, int _cap, int _rev) {
            from = _from;
            to = _to;
            cap = _cap;
            flow = 0;
            rev_edge = _rev;
        }
    };

    bool bfs(int source, int sink) {
        memset(vis, 0, sizeof(vis));
        memset(father, 0, sizeof(father));
        int p = 1, u = 0;
        q[++u] = source;
        vis[source] = 1;
        while (p <= u) {
            int nod = q[p];
            vector <int> :: iterator it;
            for (it = m_graph[nod].begin(); it != m_graph[nod].end(); ++it) {
                flow_edge myEdge = m_edges[*it];
                if (!vis[myEdge.to] && myEdge.flow < myEdge.cap) {
                    vis[myEdge.to] = 1;
                    q[++u] = myEdge.to;
                    father[myEdge.to] = *it;
                }
            }
            ++p;
        }
        return vis[sink];
    }

    int augment(int source, int sink) {
        vector <int> :: iterator it;
        int myFlow = 0;
        for (it = m_graph[sink].begin(); it != m_graph[sink].end(); ++it) {
            flow_edge myEdge = m_edges[m_edges[*it].rev_edge];
            int fmin = 1 << 30;
            while (fmin) {
                fmin = min(fmin, myEdge.cap - myEdge.flow);
                if (myEdge.from == source)
                    break;
                myEdge = m_edges[father[myEdge.from]];
            }
            if (fmin) {
                int idxEdge = m_edges[*it].rev_edge;
                myEdge = m_edges[idxEdge];
                while (1) {
                    m_edges[idxEdge].flow += fmin;
                    m_edges[myEdge.rev_edge].flow -= fmin;
                    if (myEdge.from == source)
                        break;
                    idxEdge = father[myEdge.from];
                    myEdge = m_edges[idxEdge];
                }
                myFlow += fmin;
            }
        }
        return myFlow;
    }

    vector <int> m_graph[kNMax];
    vector <flow_edge> m_edges;
    bool vis[kNMax];
    int father[kNMax];
    int q[kNMax];
    int answer;
};

bool can(int val) {
    MaxFlow flowSolver;
    flowSolver.reset();
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int xx;
        if (nr[i] >= val)
            xx = (nr[i] - val) / 2 + (nr[i] - val) % 2;
        else
            xx = 0;
        if (2 * xx > nr[i])
            return 0;
        int yy = nr[i] - 2 * xx;
        sum += nr[i];
        for (int j = 1; j <= st[i]; ++j)
            flowSolver.addEdge(3 * i, 3 * n + 2 + j, 1);
        for (int j = m - dr[i] + 1; j <= m; ++j)
            flowSolver.addEdge(3 * i + 1, 3 * n + 2 + j, 1);
        for (int j = 1; j <= st[i]; ++j)
            flowSolver.addEdge(3 * i + 2, 3 * n + 2 + j, 1);
        for (int j = m - dr[i] + 1; j <= m; ++j)
            flowSolver.addEdge(3 * i + 2, 3 * n + 2 + j, 1);
        flowSolver.addEdge(1, 3 * i, xx);
        flowSolver.addEdge(1, 3 * i + 1, xx);
        flowSolver.addEdge(1, 3 * i + 2, yy);
    }
    for (int i = 1; i <= m; ++i)
        flowSolver.addEdge(3 * n + 2 + i, 2, 1);
    int res = flowSolver.solve(1, 2);
    return (res == sum);
}

int main() {
    freopen("mingiute.in", "r", stdin);
    freopen("mingiute.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &st[i], &dr[i], &nr[i]);
    int st = 0, dr = m, rez = -1;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(med)) {
            rez = med;
            dr = med - 1;
        } else
            st = med + 1;
    }
    printf("%d", rez);
    return 0;
}
