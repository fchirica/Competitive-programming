#include <stdio.h>

int main()
{
	int N, M;
	
	freopen("dmin2.in", "r", stdin);
	freopen("dmin2.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	
	long long ret = 1LL * N * (N - 1) / 2 - M - N + 1;
	
	printf("%lld", ret);
	return 0;
}
