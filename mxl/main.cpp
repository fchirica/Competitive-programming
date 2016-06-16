#include <stdio.h>
#include <string.h>

long long x[50][50];
char formula[50][50][300];

long long solve(int lin, int col) {
	if (x[lin][col])
		return x[lin][col];
	
	if (formula[lin][col][0] != '=') {
		int i, N = strlen(formula[lin][col]);
		long long sol = 0;
		for (i = 0; i < N; i ++)
			sol = sol * 10 + formula[lin][col][i] - '0';
		
		return x[lin][col] = sol;
	}
	
	int i, j, last = 0, N = strlen(formula[lin][col]);
	long long sol = 0; 
	formula[lin][col][N] = '+';
	
	for (i = 1; i <= N; i ++)
		if (formula[lin][col][i] == '+') {
			bool recurse = false;
			int k;
			for (j = last + 1; j < i; j ++)
				if (formula[lin][col][j] == ':')
					k = j, recurse = true;
			
			long long num1 = 0, num2 = 0;
			for (j = last + 1; j < i; j ++)
				if (recurse == false || j < k) 
					num1 = num1 * 10 + formula[lin][col][j] - '0';
				else 
					if (j != k)
						num2 = num2 * 10 + formula[lin][col][j] - '0';
		
			if (recurse == false)
				sol += num1;
			else
				sol += solve(num1, num2);
			
			last = i;
		}
	
	return x[lin][col] = sol;
}

int main() {
	freopen("mxl.in", "r", stdin);
	freopen("mxl.out", "w", stdout);
	
	int i, N, M;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++) {
		int lin, col;
		scanf("%d %d ", &lin, &col);
		scanf("%s", &formula[lin][col]);
	}
	
	int j;
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= N; j ++)
			if (strlen(formula[i][j]))
				solve(i, j);
	
	for (i = 1; i <= N; i ++) {
		for (j = 1; j <= N; j ++)
			printf("%lld ", x[i][j]);
		printf("\n");
	}
	return 0;
}
