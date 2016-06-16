#include <stdio.h>

int x[250100], st[250100];

int main() {
	//freopen("pla.in", "r", stdin);
	//freopen("pla.out", "w", stdout);
	
	int i, N;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d%d", &tmp, &x[i]);
	}
	
	int sol = 0;
	for (i = 1; i <= N; ++i) {
		while (st[0] && st[st[0]] >= x[i]) {
			if (st[st[0]] == x[i])
				--sol;
			--st[0];
		}
		++sol;
		st[++st[0]] = x[i];
	}
	
	printf("%d", sol);
	return 0;
}
