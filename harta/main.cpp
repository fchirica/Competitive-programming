#include <stdio.h>
#include <vector>

using namespace std;

int N, source, sink;
int F[250][250], C[250][250], dad[250], vis[250];
vector <int> G[250];

bool BFS() {
	int i;
	for (i = 0; i <= sink; i ++) {
		dad[i] = 0; vis[i] = 0;
	}
	
	int p = 1, u = 0;
	int Q[250];
	Q[++ u] = 0; dad[0] = -1; vis[0] = 1;
	
	while (p <= u) {
		int nod = Q[p];
		vector <int> :: iterator it;
		for (it = G[nod].begin(); it != G[nod].end(); it ++)
			if (F[nod][*it] < C[nod][*it] && vis[*it] == 0) {
				dad[*it] = nod;
				vis[*it] = 1;
				Q[++ u] = *it;
			}
		p ++;
	}
	
	return dad[sink];
}

void augment() {
	int nod = sink;
	while (nod != source) {
		F[nod][dad[nod]] --;
		F[dad[nod]][nod] ++;
		nod = dad[nod];
	}
}

int main() {
	freopen("harta.in", "r", stdin);
	freopen("harta.out", "w", stdout);
	
	scanf("%d", &N);
	source = 0; sink = 2 * N + 1;
	
	int i;
	for (i = 1; i <= N; i ++) {
		int in, out;
		scanf("%d%d", &out, &in);
		
		G[source].push_back(i); G[i + N].push_back(sink); 
		C[source][i] = out; C[i + N][sink] = in;
	}
	
	int j;
	for (i = 1; i <= N; i ++)
		for (j = N + 1; j <= 2 * N; j ++) 
			if (i != j - N) {
				G[i].push_back(j); G[j].push_back(i);
				C[i][j] = 1;
			}

	int sol = 0;
	while (BFS()) {
		sol ++; augment();
	}
	
	printf("%d\n", sol);
	for (i = 1; i <= N; i ++)
		for (j = N + 1; j <= 2 * N; j ++)
			if (F[i][j] == 1)
				printf("%d %d\n", i, j - N);
	
	return 0;
}
