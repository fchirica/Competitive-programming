//un mare si calduros mlc pentru autorul acestei probleme :)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

//input
int N, M, source, sink, mlc;
vector <int> G[50000];

//componente biconexe
int low[150000], ord[50000], vis_biconex[50000];
pair <int, int> st[50000];
vector <int> cbc[50500], which[50500];
int timp = 0, cntBiconex = 0, cntSt = 0;

//un drum oarecare de la source la sink
bool vis_path[50000];
int path[50000];
int freqBiconex[50000];

//toate nodurile / componentele biconexe care treb sa apara in solutie
bool biconPath[50000];
vector <int> critical, biconOrder;

//backtracking
int sol[50000], sticky[50000];
bool back_used[50000];

void read() {
    freopen("santa.in", "r", stdin);
    freopen("santa.out", "w", stdout);

    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= 10; ++j)
            random_shuffle(G[i].begin(), G[i].end());
    scanf("%d%d%d", &source, &sink, &mlc);
}

void load_component(int xx, int yy) {
    ++cntBiconex;
    map <int, bool> MP;
    while (cntSt > 0) {
        int curx = st[cntSt].first;
        int cury = st[cntSt].second;
        if (MP[curx] == 0) {
            MP[curx] = 1;
            cbc[cntBiconex].push_back(curx);
            which[curx].push_back(cntBiconex);
        }
        if (MP[cury] == 0) {
            MP[cury] = 1;
            cbc[cntBiconex].push_back(cury);
            which[cury].push_back(cntBiconex);
        }
        --cntSt;
        if (curx == xx && cury == yy)
            break;
    }
}

void dfs_biconex(int nod) {
    vector <int> :: iterator it;
    vis_biconex[nod] = 1;
    ord[nod] = low[nod] = ++timp;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis_biconex[*it]) {
            st[++cntSt].first = nod; st[cntSt].second = *it;
            dfs_biconex(*it);
            if (low[*it] >= ord[nod])
                load_component(nod, *it);
            if (low[*it] < low[nod])
                low[nod] = low[*it];
        } else if (ord[*it] < low[nod])
            low[nod] = ord[*it];
}

bool dfs_path(int nod, int target) {
    vis_path[nod] = 1;
    path[++path[0]] = nod;

    if (nod == target)
        return 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis_path[*it])
            if (dfs_path(*it, target))
                return 1;

    --path[0];
    return 0;
}

int findComponent(int nod) {
    vector <int> :: iterator it;
    for (it = which[nod].begin(); it != which[nod].end(); ++it)
        if (freqBiconex[*it] > 1)
            return *it;
    return 69;
}

bool get_good_intersections() {
    bool isEvenPossible = dfs_path(source, sink);
    if (!isEvenPossible)
        return 0;

    for (int i = 1; i <= path[0]; ++i)
        for (vector <int> :: iterator it = which[path[i]].begin(); it != which[path[i]].end(); ++it)
            ++freqBiconex[*it];

    for (int i = 1; i <= path[0]; ++i) {
        int nod = path[i];
        if (which[nod].size() == 1) {
            int comp = which[nod][0];
            if (!biconPath[comp]) {
                biconPath[comp] = 1;
                biconOrder.push_back(comp);
            }
        } else {
            vector <int> :: iterator it;
            for (it = which[nod].begin(); it != which[nod].end(); ++it)
                if (freqBiconex[*it] > 1 && !biconPath[*it]) {
                    biconPath[*it] = 1;
                    biconOrder.push_back(*it);
                    if (nod != source)
                        critical.push_back(nod);
                }
        }
    }

    int compS = findComponent(source);
    int compD = findComponent(sink);
    int compQ = findComponent(mlc);

    if (compQ == compS || compQ == compD) {
        if (compQ == compD) {
            critical.push_back(mlc);
            reverse(critical.begin(), critical.end());
            reverse(biconOrder.begin(), biconOrder.end());
        } else {
            reverse(critical.begin(), critical.end());
            critical.push_back(mlc);
            reverse(critical.begin(), critical.end());
        }
        return 1;
    }
    return 0;
}

bool back(int current, int target, int numComponent, int cntNodes) {
    if (current == target && cntNodes + 1 != cbc[numComponent].size())
        return 0;
    sol[++sol[0]] = current;
    ++cntNodes;
    back_used[current] = 1;
    if (cntNodes == (int)cbc[numComponent].size()) {
        if (target == -1 || target == current)
            return 1;
        --sol[0]; back_used[current] = 0;
        return 0;
    }

    vector <int> :: iterator it;
    for (it = G[current].begin(); it != G[current].end(); ++it)
        if (!back_used[*it] && sticky[*it])
            if (back(*it, target, numComponent, cntNodes))
                return 1;

    --sol[0];
    --cntNodes;
    back_used[current] = 0;
    return 0;
}

bool solve() {
    for (int i = 0; i < (int)biconOrder.size(); ++i) {
        int comp = biconOrder[i];
        int start = critical[i];
        int finish = ((i + 1) != (int)biconOrder.size()) ? critical[i + 1] : -1;
        for (vector <int> :: iterator it = cbc[comp].begin(); it != cbc[comp].end(); ++it)
            sticky[*it] = 1;
        bool solution = back(start, finish, comp, 0);
        if (!solution)
            return 0;
        if (i != (int)biconOrder.size() - 1)
            --sol[0];
        for (vector <int> :: iterator it = cbc[comp].begin(); it != cbc[comp].end(); ++it) {
            sticky[*it] = 0;
            back_used[*it] = 0;
        }
    }
    return 1;
}

void writePath() {
    printf("%d\n", sol[0]);
    for (int i = 1; i <= sol[0]; ++i)
        printf("%d ", sol[i]);
}

int main() {
    read();
    dfs_biconex(1);
    bool solution = get_good_intersections();
    if (!solution) {
        printf("No chance\n");
        return 0;
    }
    solution = solve();
    if (!solution) {
        printf("No chance\n");
        return 0;
    }
    writePath();
    return 0;
}
