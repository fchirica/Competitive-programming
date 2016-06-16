#include <stdio.h>
#include <string.h>

char x[100010];

inline int min(int A, int B) {
	if (A < B)
		return A;
	return B;
}

int go(char ch, int n) {
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (x[i] != ch)
			++tot;
		if (ch == '+')
			ch = '-';
		else
			ch = '+';
	}
	return tot;
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		gets(x + 1);
		int n = strlen(x + 1);
		int res = min(go('+', n), go('-', n));
		printf("%d\n", res);
	}
	return 0;
}
