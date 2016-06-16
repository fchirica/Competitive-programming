#include <stdio.h>
#include <vector>

using namespace std;

int V[3][200200];
bool del[3][200200];
int q[3][400200], sol[200200];
int T[200200];
vector <int> G[200200];

int unite(int X, int Y) {
    T[X] = Y;
    G[Y].push_back(X);
}

int find(int X) {
    return T[X] = ((T[X] == X) ? X : find(T[X]));
}

int Q[200200];
void bfs(int nod, int label) {
    int p = 1, u = 0;
    Q[++u] = nod; sol[nod] = label;
    while (p <= u) {
        int nod = Q[p];
        vector <int> :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (sol[*it] == 0) {
                sol[*it] = label;
                Q[++u] = *it;
            }
        ++p;
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &V[1][i], &V[2][i]);
    for (int i = 1; i <= N; ++i)
        T[i] = i;
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &q[1][i], &q[2][i]);
        del[q[2][i]][q[1][i]] = 1;
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= 2; ++j)
            if (!del[j][i] && V[j][i] != -1)
                if (find(i) != find(V[j][i])) {
                    int nod1 = find(i);
                    int nod2 = find(V[j][i]);
                    if (nod1 != 1 && nod2 != 1)
                        unite(nod1, nod2);
                    else
                    if (nod2 == 1)
                        unite(nod1, nod2);
                    else
                        unite(nod2, nod1);
                }

    for (int i = M; i >= 1; --i) {
        int nod1 = q[1][i];
        int nod2 = V[q[2][i]][q[1][i]];
        int root1 = find(nod1);
        int root2 = find(nod2);
        if (root1 == root2)
            continue;
        if (root1 == 1) {
            bfs(root2, i);
            unite(root2, root1);
        }
        else
        if (root2 == 1) {
            bfs(root1, i);
            unite(root1, root2);
        }
        else
            unite(root1, root2);
    }
    for (int i = 1; i <= N; ++i)
        printf("%d\n", sol[i] - 1);
    return 0;
}
