#include <stdio.h>
#include <string.h>

int poz = 1, N, val[300], used[300];
char x[20100];

void termen(int sign);
void eval(int sign) {
	int semn = sign;
	while (poz <= N) {
		termen(semn);
		semn = sign;
		if (x[poz] == '/')
			semn = semn * (-1);
		
		if (x[poz] == ')')
			return ;
		poz ++;
	}
}

void termen(int sign) {
	if ('a' <= x[poz] && x[poz] <= 'z') {
		val[x[poz]] += sign; poz ++;
		return ;
	}
	
	poz ++; eval(sign); poz ++;
}

int main() {
	freopen("expresie3.in", "r", stdin);
	freopen("expresie3.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);

	eval(1);
	
	int i;
	for (i = 1; i <= N; i ++)
		if ('a' <= x[i] && x[i] <= 'z')
			used[x[i]] = 1;
	
	for (i = 'a'; i <= 'z'; i ++)
		if (used[i])
			printf("%c %d\n", (char)i, val[i]);
	return 0;
}
