#include <bits/stdc++.h>

using namespace std;

const int kNMax = 1001;

int L[kNMax], R[kNMax];
vector <pair <int, int> > path;

bool vis[2][kNMax];

pair <int, int> sol_red[kNMax], sol_blue[kNMax];

int main() {
    freopen("zaharel.in", "r", stdin);
    freopen("zaharel.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        char ch;
        scanf("%d %d %c", &xx, &yy, &ch);
        if (ch == 'R')
            L[xx] = yy;
        else
            R[yy] = xx;
    }

    int nod = 1, side = 0;
    while (vis[side][nod] == 0) {
        vis[side][nod] = 1;
        path.push_back(make_pair(side, nod));
        vector <int> :: iterator it;
        if (side == 0)
            nod = L[nod];
        else
            nod = R[nod];
        side = 1 - side;
    }

    path.push_back(make_pair(side, nod));
    int cntR = 0, cntB = 0;
    for (int i = 0; i < path.size(); ++i)
        if (path[i].first == side && path[i].second == nod) {
            for (int j = i; j < path.size() - 1; ++j)
                if (path[j].first == 0)
                    sol_red[++cntR] = make_pair(path[j].second, path[j + 1].second);
                else
                    sol_blue[++cntB] = make_pair(path[j + 1].second, path[j].second);
            break;
        }

    printf("%d\n", cntR);
    for (int i = 1; i <= cntR; ++i)
        printf("%d %d ", sol_red[i].first, sol_red[i].second);
    printf("\n");
    for (int i = 1; i <= cntB; ++i)
        printf("%d %d ", sol_blue[i].first, sol_blue[i].second);
    return 0;
}
