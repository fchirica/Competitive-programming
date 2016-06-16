#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int gen[110];
char mat[110][110];
vector <int> G[110];
int L[110], R[110], U[110];

bool pairup(int node) {
	if (U[node])
		return 0;
	
	U[node] = true;
	vector <int> :: iterator it;
	for (it = G[node].begin(); it != G[node].end(); ++it)
		if (R[*it] == 0 || pairup(R[*it])) {
			L[node] = *it; R[*it] = node;
			return true;
		}
	return false;
}

int main() {
	///freopen("data.in", "r", stdin);
	///freopen("data.out", "w", stdout);
	
	int N, M;
	while (1) {
		scanf("%d%d\n", &M, &N);
		if (N == 0 && M == 0)
			break;
		int i, j;
		for (i = 1; i <= M; ++i)
			for (j = 1; j <= M; ++j) {
				char ch;
				do {
					scanf("%c", &ch);
				} 
				while (ch == ' ' || ch == '\n');
				mat[i][j] = ch;
			}
		for (i = 1; i <= N; ++i)
			G[i].clear();
		for (i = 1; i <= N; ++i) {
			scanf("%d", &gen[i]);
			++gen[i]; 
		}
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= N; ++j)
				if (mat[gen[i]][gen[j]] == 'D')
					G[i].push_back(j);
			L[i] = R[i] = 0;
		}
		int matching = 0;
		bool canAugment;
		do {
			canAugment = false;
			memset(U, 0, sizeof(U));
			for (i = 1; i <= N; ++i)
				if (L[i] == 0 && pairup(i)) {
					canAugment = true;
					break;
				}
			matching += canAugment;
		}
		while (canAugment);
		printf("%d\n", matching);
	}
	
	return 0;
}
