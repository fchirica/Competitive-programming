#include <stdio.h>

char x[1000100];

int main() {
	//freopen("BBB.in", "r", stdin);
	//freopen("BBB.out", "w", stdout);
	
	int N, ini, fin, c0, c1;
	scanf("%d%d%d%d%d\n", &N, &ini, &fin, &c0, &c1);
	gets(x + 1);
	
	int i, plus = 0, minus = 0;
	for (i = 1; i <= N; ++i)
		if (x[i] == '+')
			++plus;
		else
			++minus;
	int delta = (fin - (ini + plus - minus)) / 2, supply = delta;
	if (delta > 0) {
		for (i = 1; i <= N && supply; ++i)
			if (x[i] == '-') {
				x[i] = '+';
				--supply;
			}
	}
	else
		delta = delta * (-1);
	int num = 0, sum = ini;
	for (i = 1; i <= N; ++i)
		if (x[i] == '+')
			++sum;
		else {
			--sum;
			if (sum == -1)
				sum = 0, ++num;
		}
	
	int sol = (num + num % 2) * c0, cur = 0, left = num, done = 0;
	for (i = N; i >= 1; --i) {
		if (left == 0)
			break;
		if (x[i] == '+') {
			++cur; 
			if (cur == 1) {
				--left; ++done; cur = 0;
				int curCost = (N - i + 1) * c1;
				curCost += ((num - done) + (num - done) % 2) * c0;
				if (curCost < sol)
					sol = curCost;
			}
		}
		else
			--cur;
	}
	
	printf("%d", sol + delta * c0);
	return 0;
}
