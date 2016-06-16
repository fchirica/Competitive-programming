#include <stdio.h>
#include <map>
#include <vector>
#define in(X) (2 * X)
#define out(X) (2 * X + 1)
#define mp make_pair
#define INF (1 << 30)
#define NMAX 10000 + 100

using namespace std;

vector <int> G[NMAX];

struct edge {
	int x, y;
};

edge E[50000];
int cntE = 0, F[50000], C[50000];

void addEdge(int x, int y, int c) {
	edge tmp;
	tmp.x = x; tmp.y = y; 
	E[++cntE] = tmp;
	C[cntE] = c;
	G[x].push_back(cntE);
}

int S, D, father[NMAX], vis[NMAX], Q[NMAX];

bool BFS() {
	int i;
	for (i = S; i <= D; ++i) {
		father[i] = -1;
		vis[i] = 0;
	}
	
	int fi = 1, la = 0;
	vector <int> :: iterator it;
	Q[++la] = S; vis[S] = 1;
	while (fi <= la) {
		int node = Q[fi];
		for (it = G[node].begin(); it != G[node].end(); ++it)
			if (F[*it] < C[*it] && !vis[E[*it].y]) {
				vis[E[*it].y] = true;
				father[E[*it].y] = *it;
				Q[++la] = E[*it].y;
				if (*it == D)
					return true;
			}
		++fi;
	}
	return vis[D];
}

int sol = 0;
void augment() {
	int nod = D;
	++sol;
	while (nod != S) {
		int dad = E[father[nod]].x;
		F[father[nod]] ++;
		F[father[nod] + 1] --;
		nod = dad;
	}
}

int main() {
	freopen("nar.in", "r", stdin);
	freopen("nar.out", "w", stdout);
	
	int i, j, N;
	scanf("%d", &N);
	S = out(1); D = in(N);
	for (i = 1; i < N; ++i) {
		int cnt;
		scanf("%d", &cnt);
		for (j = 1; j <= cnt; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (i == 1 && tmp == N)
				addEdge(out(i), in(tmp), 1);
			else
				addEdge(out(i), in(tmp), INF);
			addEdge(in(tmp), out(i), 0);
		}
	}
	for (i = 2; i < N; ++i) {
		addEdge(in(i), out(i), 1);
		addEdge(out(i), in(i), 0);
	}
	
	while (BFS()) 
		augment();
	
	printf("%d", sol);
	return 0;
}
