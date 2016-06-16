#include <stdio.h>

int n, k, m, blocked[10100], left[10100], right[10100];

void solve() {
	scanf("%d%d%d", &n, &k, &m);
	
	int i;
	for (i = 1; i <= n; i ++)
		blocked[i] = left[i] = right[i] = 0;
	
	int x;
	for (i = 1; i <= k; i ++) {
		scanf("%d", &x);
		blocked[x] = 1;
	}
	
	blocked[1] = blocked[n] = 1;
	for (i = 1; i <= n; i ++)
		if (blocked[i])
			left[i] = i;
		else
			left[i] = left[i - 1];
	for (i = n; i >= 1; i --)
		if (blocked[i])
			right[i] = i;
		else
			right[i] = right[i + 1];
	
	int odd = 0, even = 0, unsure = 0;
	for (i = 1; i <= m; i ++) {
		scanf("%d", &x);
		if (blocked[x])
			continue;
		int dist1 = x - left[x], dist2 = right[x] - x;
		if (dist1 % 2 == 0 && dist2 % 2 == 0)
			even ++;
		else
		if (dist1 % 2 && dist2 % 2)
			odd ++;
		else
			unsure ++;
	}
	
	if (unsure % 2 || odd % 2)
		printf("1");
	else
		printf("0");
}

int main() {
	freopen("cutie.in", "r", stdin);
	freopen("cutie.out", "w", stdout);
	
	int tests;
	scanf("%d", &tests);
	
	while (tests --) 
		solve();
	
	return 0;
}
