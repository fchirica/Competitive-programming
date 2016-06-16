#include <stdio.h>
#include <vector>
#define NMAX 50100
 
using namespace std;
 
int D[NMAX], Q[50 * NMAX]; 
vector <pair <int, int> > G[NMAX];
bool is[NMAX];

int main() {
    freopen("bellmanford.in", "r", stdin);
    freopen("bellmanford.out", "w", stdout);
     
    int i, N, M;
    scanf("%d%d", &N, &M);
    for (i = 1; i <= M; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        G[x].push_back(make_pair(y, c));
    }
     
    int p = 1, u = 0;
    D[1] = 0; Q[++u] = 1; is[1] = true;
    for (i = 2; i <= N; ++i)
        D[i] = 1 << 30;
     
    for (i = 1; i <= N + 1; ++i) {
        if (i == N + 1 && p <= u) {
            printf("Ciclu negativ!");
            return 0;
        }
        if (p > u)
            break;
        int lastu = u;
        while (p <= lastu) {
            vector <pair <int, int> > :: iterator it;
            int nod = Q[p]; 
			is[nod] = false;
            for (it = G[nod].begin(); it != G[nod].end(); ++it)
                if (D[nod] + it -> second < D[it -> first]) {
                    D[it -> first] = D[nod] + it -> second;
					if (is[it -> first] == false) {
						Q[++u] = it -> first; 
						is[it -> first] = true;
					}
                }
            ++p;
        }
    }
     
    for (i = 2; i <= N; ++i)
        printf("%d ", D[i]);
    return 0;
}
