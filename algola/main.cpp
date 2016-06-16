/* Mai du-te-n gatul ma-tii
   Mai da-te-n pizda ma-tii
   Floooow
   Floooooow

   Sunt Jamaica man
*/

#include <bits/stdc++.h>

using namespace std;

const int kNMax = 5555; //Babenko

int lim;

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
        for (int i = 0; i < m_edges.size(); ++i)
            m_edges[i].flow = 0;
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
        for (int i = 0; i <= lim; ++i)
            vis[i] = 0;
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

vector <pair <int, int> > G[kNMax];
int people[kNMax];

int n;

inline int compress(int nod, int t) {
    return nod + n * t;
}

int main() {
    freopen("algola.in", "r", stdin);
    freopen("algola.out", "w", stdout);

    MaxFlow flowSolver;

    int m, totPeople = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &people[i]);
        totPeople += people[i];
    }
    for (int i = 1; i <= m; ++i) {
        int xx, yy, cc;
        scanf("%d%d%d", &xx, &yy, &cc);
        G[xx].push_back(make_pair(yy, cc));
        G[yy].push_back(make_pair(xx, cc));
    }

    for (int i = 1; i <= n; ++i)
        flowSolver.addEdge(0, i, people[i]);

    for (int res = 1; ; ++res) {
        for (int i = 1; i <= n; ++i) {
            flowSolver.addEdge(compress(i, res - 1), compress(i, res), 1 << 29);
            vector <pair <int, int> > :: iterator it;
            for (it = G[i].begin(); it != G[i].end(); ++it)
                flowSolver.addEdge(compress(i, res - 1), compress(it -> first, res), it -> second);
        }
        lim = compress(n, res);
        int myFlow = flowSolver.solve(0, compress(1, res));
        if (myFlow == totPeople) {
            printf("%d", res);
            return 0;
        }
        flowSolver.reset();
    }

    return 0;
}
