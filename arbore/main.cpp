//sursa mea are mai multa valoare ca cea a lui ericpts $$$

#include <stdio.h>
#include <vector>
#include <bitset>
#include <math.h>
#define low(X) (lim * (X - 1) + 1)
#define up(X) (lim * X)

using namespace std;

vector <int> G[110000];
bool vis[110000];
int lim, timp, val[110000], out[110000], in[110000];
int x[110000], supply[110000];
bitset <1000100> is[330];

void dfs(int nod) {
    vector <int> :: iterator it;
    vis[nod] = true;
    val[++timp] = nod; in[nod] = timp;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            dfs(*it);
    out[nod] = timp;
}

int getBucket(int X) {
    if (X % lim == 0)
        return X / lim;
    return X / lim + 1;
}

void update(int xx, int yy, int sum, int N) {
    for (int i = getBucket(yy); i >= getBucket(xx); --i)
        if (xx <= low(i) && up(i) <= yy)
            supply[i] += sum;
        else {
            for (int j = low(i); j <= up(i); ++j)
                is[i][x[j]] = 0;
            for (int j = low(i); j <= up(i); ++j) {
                if (j > N)
                    break;
                if (xx <= j && j <= yy)
                    x[j] += sum;
                is[i][x[j]] = 1;
            }
        }
}

int query(int sum, int maxBucket) {
    for (int i = 1; i <= maxBucket; ++i)
        if (sum - supply[i] >= 0 && is[i][sum - supply[i]])
            for (int j = low(i); j <= up(i); ++j)
                if (x[j] == sum - supply[i])
                    return val[j];
    return -1;
}

int main() {
    freopen("arbore.in", "r", stdin);
    freopen("arbore.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);
    lim = sqrt(N);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    dfs(1);
    for (int i = 1; i <= lim; ++i)
        is[i][0] = 1;
    for (int i = 1; i <= M; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int p, s;
            scanf("%d%d", &p, &s);
            int xx = in[p], yy = out[p];
            update(xx, yy, s, N);
        } else {
            int sum;
            scanf("%d", &sum);
            printf("%d\n", query(sum, getBucket(N)));
        }
    }

    return 0;
}
