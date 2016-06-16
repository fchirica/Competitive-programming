#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector <int> G[100100], sol[100100];
int ord[100100], low[100100], stx[100100], sty[100100], cntst = 0, cntsol = 0;

int when = 0;

void addComponent(int stopx, int stopy) {
	map <int, bool> M;
	++cntsol;
	int curx, cury;
	do {
		curx = stx[cntst]; cury = sty[cntst];
		if (M[curx] == false) {
			M[curx] = true;
			sol[cntsol].push_back(curx);
		}
		if (M[cury] == false) {
			M[cury] = true;
			sol[cntsol].push_back(cury);
		}
		--cntst;
	}
	while (cntst > 0 && !(curx == stopx && cury == stopy));
}

void DFS(int nod) {
	vector <int> :: iterator it;
	ord[nod] = low[nod] = ++when;
	
	for (it = G[nod].begin(); it != G[nod].end(); ++it) 
		if (ord[*it] == 0) {
			stx[++cntst] = nod; sty[cntst] = *it;
			DFS(*it);
			if (low[*it] < low[nod])
				low[nod] = low[*it];
			if (low[*it] >= ord[nod]) 
				addComponent(nod, *it);
		}
		else
			if (low[nod] > ord[*it])
				low[nod] = ord[*it];
}

int main() { 
	freopen("biconex.in", "r", stdin);
	freopen("biconex.out", "w", stdout);
	
	int i, N, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	DFS(1);
	
	printf("%d\n", cntsol);
	for (i = 1; i <= cntsol; ++i) {
		vector <int> :: iterator it;
		for (it = sol[i].begin(); it != sol[i].end(); ++it)
			printf("%d ", *it);
		printf("\n");
	}
	return 0;
}
