#include <stdio.h>
#include <math.h>

int K, x[100100], next[100100], st[100100];
int memo[1024][1024];

int dist(int x0, int y0, int x1, int y1) {
	return (int)sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int solve(int where, int sum) {
	if (sum < 0)
		return 1 << 30;
	if (where >= K)
		return 0;
	if (memo[where][sum])
		return memo[where][sum];
	
	int go = next[where], sol;
	if (x[where] <= x[go]) 
		sol = dist(where, x[where], go, x[go]) + solve(go, sum - x[go] + x[where]);
	else {
		int choice = dist(where, x[where], go, x[go]) + solve(go, sum);
		int choice2 = 1 + solve(go, sum - x[where] + x[go]);
		if (choice < choice2)
			sol = choice;
		else
			sol = choice2;
	}
		
	return memo[where][sum] = sol;
}

int main() {
	freopen("telecab.in", "r", stdin);
	freopen("telecab.out", "w", stdout);
	
	int i, N, S;
	scanf("%d%d%d", &N, &K, &S);
	for (i = 1; i <= N; i ++) {
		scanf("%d", &x[i]);
		next[i] = i + 1;
	}
	
	for (i = 1; i <= N; i ++) {
		while (st[0] > 0 && x[i] > x[st[st[0]]]) {
			next[st[st[0]]] = i;
			st[0] --;
		}
		st[++ st[0]] = i;
	}
	
	int lenth = 0;
	for (i = 1; i < N; i = next[i]) 
		lenth += dist(i, x[i], next[i], x[next[i]]);
	
	printf("%d\n", lenth);
	printf("%d", solve(1, S));
	
	return 0;
}
