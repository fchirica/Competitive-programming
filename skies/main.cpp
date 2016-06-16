#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[5100];
int N;
bool vis[5100], newPath;
bool specialCase = true;

void DFS(int node) {
	if (node == N) {
		newPath = true;
		return ;
	}
	
	vis[node] = true;
	vector <int> :: iterator it;
	for (it = G[node].begin(); it != G[node].end() && !newPath; ++it) {
		if (node == 1 && *it == N) {
			if (specialCase) {
				DFS(N);
				specialCase = false;
			}
			continue;
		}
		if (!vis[*it])
			if (newPath == false)
				DFS(*it);
	}
}

int main() {
	scanf("%d", &N);
	int i, j;
	for (i = 1; i < N; ++i) {
		int cnt;
		scanf("%d", &cnt);
		for (j = 1; j <= cnt; ++j) {
			int tmp;
			scanf("%d", &tmp);
			G[i].push_back(tmp);
		}
	}
	
	int sol = 0;
	do {
		newPath = false;
		DFS(1);
		sol += newPath;
	} while (newPath == true);
	
	printf("%d", sol);
	return 0;
}
