#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[100100];
int dad[100100], vis[100100], vis2[100100], next[100100];
int comp[100100];
bool fountCycle = false;

void DFS_conex(int nod) {
	vector <int> :: iterator it;
	vis2[nod] = true;
	comp[++comp[0]] = nod;
	for (it = G[nod].begin(); it != G[nod].end(); ++it)
		if (!vis2[*it])
			DFS_conex(*it);
}

void DFS(int nod, int from) {
	vector <int> :: iterator it;
	if (fountCycle == true) 
		return ;
	vis[nod] = true;
	for (it = G[nod].begin(); it != G[nod].end() && !fountCycle; ++it) {
		if (vis[*it] == true && *it != from) {
			fountCycle = true;
			dad[*it] = nod;
			next[nod] = *it;
			int i;
			for (i = *it; next[nod] != *it; i = next[i])
				dad[next[i]] = i;
			break;
		}
		if (vis[*it] == false) {
			next[nod] = *it;
			DFS(*it, nod);
		}
	}
}

void DFS2(int nod) {
	vector <int> :: iterator it;
	for (it = G[nod].begin(); it != G[nod].end(); ++it)
		if (!dad[*it]) {
			dad[*it] = nod;
			DFS2(*it);
		}
}

int main() {
	//freopen("clo.in", "r", stdin);
	//freopen("clo.out", "w", stdout);
	
	int i, j, N, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	bool solution = true;
	for (i = 1; i <= N; ++i)
		if (vis2[i] == 0) {
			comp[0] = 0;
			fountCycle = false;
			DFS_conex(i);
			DFS(i, -1);
			if (fountCycle == false)
				solution = false;
			for (j = 1; j <= comp[0]; ++j)
				if (dad[comp[j]])
					DFS2(comp[j]);
		}
	
	for (i = 1; i <= N; ++i)
		if (dad[i] == 0)
			solution = false;
	if (!solution) {
		printf("NIE\n");
		return 0;
	}
	printf("TAK\n");
	for (i = 1; i <= N; ++i)
		printf("%d\n", dad[i]);
	return 0;
}
