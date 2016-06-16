#include <stdio.h>
#include <vector>
#define INF (1 << 30)

using namespace std;

struct edge {
    int next, sum;
};

int maxV[500500];
bool cc[500500], color[500500];
int nod[500500];
vector <edge> G[500500];

edge mp(int A, int B) {
    edge tmp;
    tmp.next = A; tmp.sum = B;
    return tmp;
}

void DFS(int nod) {
    cc[nod] = true;
    vector <edge> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!cc[it -> next])
            DFS(it -> next);
}

int edgeCycle1, edgeCycle2;
int father[500500];
int curComponent[500500], eval[500500];

void DFS_color(int node, int col) {
    color[node] = col;
    curComponent[++curComponent[0]] = node;
    vector <edge> :: iterator it;
    for (it = G[node].begin(); it != G[node].end(); ++it) {
        if (color[it -> next] == -1) {
            DFS_color(it -> next, 1 - color);
            father[it -> next] = nod;
        }
        if (color[it -> next] == col)
            edgeCycle1 = node, edgeCycle2 = it -> next;
    }
}

void setToInf() {
    int i;
    for (i = 1; i <= curComponent[0]; ++i)
        eval[curComponent[i]] = INF;
}

int adjustPos() {
    int i, mx = 0;
    for (i = 1; i <= curComponent[0]; ++i)
        if (eval[curComponent[i]] < 0 && -eval[curComponent[i]] > mx)
            mx = -eval[curComponent[i]];
    return mx;
}

void adjustNeg() {
    int i, mx = 0;
    for (i = 1; i <= curComponent[0]; ++i)
        if (eval[curComponent[i]] > maxV[curComponent[i]] && eval[curComponent[i]] - maxV[curComponent[i]] > mx)
            mx = eval[curComponent[i]] - maxV[curComponent[i]];
    return mx;
}

int solveComponent(int node, int type) {
    edgeCycle1 = -1; edgeCycle2 = -1;
    DFS_color(node, 0);
    father[node] = -1;
    if (edgeCycle1 != -1) { //Am ciclu impar

    } else { //Graf bipartit
        int whiteCnt = 0, blackCnt = 0;
        for (i = 1; i <= curComponent[0]; ++i)
            if (color[curComponent[i]] == 0)
                ++whiteCnt;
            else
                ++blackCnt;
        if (whiteCnt < blackCnt) {
            swap(whiteCnt, blackCnt);
            for (i = 1; i <= curComponent[0]; ++i)
                color[curComponent[i]] = 1 - color[curComponent[i]];
        }
        setToInf();
        eval[component[1]] = 0;
        if (!simulate())
            return -INF;

    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= N; ++i) {
        scanf("%d", &maxV[i]);
        color[i] = -1;
    }
    for (i = 1; i <= M; ++i) {
        int X, Y, Z;
        scanf("%d%d%d", &X, &Y, &Z);
        G[X].push_back(mp(Y, Z));
        G[Y].push_back(mp(X, Z));
    }

    for (i = 1; i <= N; ++i)
        if (!cc[i]) {
            DFS(i);
            nod[++nod[0]] = i;
        }

    int solmin = 0, solmax = 0;
    for (i = 1; i <= nod[0]; ++i) {
        solmin += solveComponent(nod[i], 0);
        solmax += solveComponent(nod[i], 1);
    }

    if (solmin < 0)
        printf("NIE");
    else
        printf("%d %d", solmin, solmax);
    return 0;
}
