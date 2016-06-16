#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector <int> G[200200], GT[200200];
bool vis[200200], vis2[200200];
int st[200200];
int ctc[200200];

int non(int X) {
    if (X <= N)
        return X + N;
    return X - N;
}

void add(int A, int B) {
    GT[A].push_back(non(B));
    GT[B].push_back(non(A));
    G[non(A)].push_back(B);
    G[non(B)].push_back(A);
}

void dfs1(int nod) {
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs1(*it);
    st[++st[0]] = nod;
}

void dfs2(int nod, int C) {
    vis2[nod] = 1;
    ctc[nod] = C;
    vector <int> :: iterator it;
    for (it = GT[nod].begin(); it != GT[nod].end(); ++it)
        if (!vis2[*it])
            dfs2(*it, C);
}

int main() {
    //freopen("2sat.in", "r", stdin);
    //freopen("2sat.out", "w", stdout);

    int M;
    scanf("%d%d", &N, &M);
    N = N * 2;
    for (int i = 1; i <= N; ++i) {
        add(2 * i - 1, 2 * i);
        add(non(2 * i - 1), non(2 * i));
    }
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        add(non(xx), non(yy));
    }
    for (int i = 1; i <= 2 * N; ++i)
        if (!vis[i])
            dfs1(i);
    int tmp = 0;
    for (int i = st[0]; i >= 1; --i)
        if (!vis2[st[i]])
            dfs2(st[i], ++tmp);
    bool solution = true;
    for (int i = 1; i <= N; ++i)
        if (ctc[i] == ctc[non(i)])
            solution = false;
    if (!solution) {
        printf("NIE");
        return 0;
    }
    for (int i = 1; i <= N; ++i)
        if (ctc[i] > ctc[non(i)])
            printf("%d\n", i);
    return 0;
}
