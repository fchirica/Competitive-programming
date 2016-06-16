#include <stdio.h>
#include <string.h>

char x[300];
int A, B, C, D;

void solve(int st, int dr, int type) {
	int i, a = 0, b = 0, semn = 1, num = 0;
	x[++ dr] = '+';
	
	for (i = st; i <= dr; i ++) {
		if ('0' <= x[i] && x[i] <= '9')
			num = num * 10 + x[i] - '0';
		if (x[i] == 'x') {
			if (num == 0)
				num = 1;
			a = a + num * semn;
			num = 0;
		}
		if (x[i] == '+' || x[i] == '-') {
			b += num * semn; num = 0;
			if (x[i] == '+')
				semn = 1;
			else
				semn = -1;
		}
	}
	
	if (type == 1)
		A = a, B = b;
	else
		C = a, D = b;
}

int main() {
	freopen("ecuatii2.in", "r", stdin);
	freopen("ecuatii2.out", "w", stdout);
	
	int T;
	scanf("%d\n", &T);
	while (T --) {
		gets(x + 1);
		int i, N = strlen(x + 1);
		for (i = 1; i <= N; i ++)
			if (x[i] == '=') {
				solve(1, i - 1, 1);
				solve(i + 1, N, 2);
			}
		
		if (A - C == 0) {
			if (D - B == 0)
				printf("infinit\n");
			else
				printf("imposibil\n");
		} else 
			printf("%.4lf\n", (double)(D - B) / (A - C));
	}
	
	return 0;
}
