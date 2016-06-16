#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int G[100100][2][11], G2[100100][2][11], shit1[100], shit2[100];
bool root[11], root2[11];

int curPula, curRoot;
map <pair <unsigned, unsigned>, int> M;

void dfs(int nod, int sh[], int type) {
    sh[++sh[0]] = type;
    for (int i = 0; i <= 1; ++i)
        if (G[curPula][i][nod] != -1) {
            if (i == 0)
                dfs(G[curPula][i][nod], sh, -1);
            else
                dfs(G[curPula][i][nod], sh, 1);
           sh[++sh[0]] = type;
        }
}

int sum;

void check() {
    if (shit1[0] != shit2[0])
        return ;
    else {
        bool good = true;
        for (int i = 1; i <= shit1[0]; ++i)
            if (shit1[i] != shit2[i])
                good = false;
        sum += good;
    }
}

bool vis[55];

int load(int myPula, int sh[]) {
    for (int i = 1; i <= 10; ++i)
        vis[i] = 1;
    for (int son = 0; son <= 1; ++son)
        for (int i = 1; i <= 10; ++i)
            if (G[myPula][son][i] != -1)
                vis[G[myPula][son][i]] = 0;
    for (int i = 1; i <= 10; ++i)
        if (vis[i])
            return 1;
    return 0;
}

pair <unsigned, unsigned> amPulaMare() {
    pair <unsigned, unsigned> hsh = 0, hsh2 = 0;
    for (int i = 1; i <= shit1[0]; ++i) {
        hsh = 666013 * (hsh + shit1[i] * 71);
        hsh2 = 666777 * (hsh + shit1[i] * 71);
    }
    return hsh;
}

int main() {
    freopen("brazi.in", "r", stdin);
    freopen("brazi.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int pula = 1; pula <= T; ++pula) {
        int N;
        scanf("%d", &N);

        for (int i = 1; i <= N; ++i)
            G[pula][0][i] = G[pula][1][i] = -1;
        for (int i = 1; i < N; ++i) {
            int xx, yy, tt;
            scanf("%d%d%d", &xx, &yy, &tt);
            if (tt == 0)
                G[pula][0][xx] = yy;
            else
                G[pula][1][xx] = yy;
        }

        int root1 = load(pula, shit1);
        curPula = pula;
        shit1[0] = 0;
        dfs(root1, shit1, 0);
        unsigned laba = amPulaMare();
        printf("%d\n", M[laba]);
        ++M[laba];
    }

    return 0;
}

