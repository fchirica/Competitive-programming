#include <stdio.h>
#include <vector>

using namespace std;

int F[200][200], C[200][200];
vector <int> G[200];

int getVertex(char ch) {
	if ('A' <= ch && ch <= 'Z')
		return ch - 'A' + 1;
	return 'Z' + ch - 'a' + 1;
}

int S = 1, D = 26;
int father[200], vis[200], Q[200];

bool BFS() {
	int i;
	for (i = 1; i < 200; ++i)
		father[i] = -1, vis[i] = 0;
	int p = 1, u = 0;
	vis[S] = 1; Q[++u] = S;
	
	while (p <= u) {
		int nod = Q[p];
		vector <int> :: iterator it;
		for (it = G[nod].begin(); it != G[nod].end(); ++it)
			if (F[nod][*it] < C[nod][*it] && !vis[*it]) {
				vis[*it] = 1;
				father[*it] = nod;
				Q[++u] = *it;
			}
		++p;
	}
	
	return vis[D];
}

int augment() {
	int nod = D, fmin = 1 << 30;
	while (nod != S) {
		if (C[father[nod]][nod] - F[father[nod]][nod] < fmin)
			fmin = C[father[nod]][nod] - F[father[nod]][nod];
		nod = father[nod];
	}
	nod = D;
	while (nod != S) {
		F[father[nod]][nod] += fmin;
		F[nod][father[nod]] -= fmin;
		nod = father[nod];
	}
	return fmin;
}

int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	
	int N;
	scanf("%d\n", &N);
	for (int i = 1; i <= N; ++i) {
		char a, b;
		int c;
		scanf("%c %c %d\n", &a, &b, &c);
		int A = getVertex(a), B = getVertex(b);
		if (C[A][B] == 0) {
			C[A][B] = c;
			G[A].push_back(B);
		} else 
			C[A][B] += c;
	}
	
	int flow = 0;
	while (BFS())
		flow += augment();
	
	printf("%d", flow);
	return 0;
}
