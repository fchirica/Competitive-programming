#include <stdio.h>
#include <vector>

using namespace std;

struct edge {
	int to, cap, ord;
};

vector <edge> G[2 * 100100];
int sol[2 * 100100], Q[2 * 100100], need[2 * 100100];
int xx[2 * 100100], yy[2 * 100100];

edge make(int X, int Y, int Z) {
	edge tmp;
	tmp.to = X; tmp.ord = Y; tmp.cap = Z;
	return tmp;
}

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	int i, N, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		G[x].push_back(make(y, i, c));
		G[y].push_back(make(x, i, c));
		need[x] += c;
		need[y] += c;
		sol[i] = -1;
		xx[i] = x; yy[i] = y;
	}
	
	for (i = 2; i < N; ++i)
		need[i] /= 2;
	
	int p = 1, u = 0;
	Q[++u] = 1;

	while (p <= u) {
		int nod = Q[p];
		vector <edge> :: iterator it;
		for (it = G[nod].begin(); it != G[nod].end(); ++it)
			if (sol[it -> ord] == -1) {
				if (nod == xx[it -> ord])
					sol[it -> ord] = 0;
				else
					sol[it -> ord] = 1;
				need[it -> to] -= it -> cap;
				if (need[it -> to] == 0 && it -> to != N)
					Q[++u] = it -> to;
			}
		++p;
	}
	
	for (i = 1; i <= M; ++i)
		printf("%d\n", sol[i]);
	
	return 0;
}
