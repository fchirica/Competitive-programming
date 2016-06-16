#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[100100];
int ord[100100], low[100100], arb[100100];
long long sol[100100];
int when = 0, N;

void DFS(int nod) {
	ord[nod] = low[nod] = ++when;
	arb[nod] = 1;
	
	vector <int> :: iterator it;
	vector <int> sons;
	int sonCount = 0;
	for (it = G[nod].begin(); it != G[nod].end(); ++it) {
		if (ord[*it] == 0) {
			DFS(*it);
			if (low[*it] < low[nod])
				low[nod] = low[*it];
			arb[nod] += arb[*it];
			++sonCount;
			sons.push_back(*it);
		}
		else
			if (ord[*it] < low[nod])
				low[nod] = ord[*it];
	}
	
	bool isArticulation = false;
	long long upper = 0, sum = 0, comb = 0;
	for (it = sons.begin(); it != sons.end(); ++it) 
		if (low[*it] >= ord[nod]) {
			isArticulation = true;
			sum += arb[*it];
			comb += 1LL * arb[*it] * (arb[*it] - 1);
		}
	if (nod == 1 && sonCount == 1)
		isArticulation = false;
	if (isArticulation == false)
		sol[nod] = 2 * N - 2;
	else {
		upper = N - 1 - sum;
		comb += 1LL * upper * (upper - 1);
		sol[nod] = 1LL * N * (N - 1) - comb;
	}
}

int main() {
	//freopen("blockade.in", "r", stdin);
	//freopen("blockade.out", "w", stdout);
	
	int i, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	DFS(1);
	
	for (i = 1; i <= N; ++i)
		printf("%lld\n", sol[i]);
	return 0;
}
