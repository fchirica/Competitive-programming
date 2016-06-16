#include <stdio.h>

int main()
{
	int x;
	long long sol = 1;
	
	freopen("drepte2.in", "r", stdin);
	freopen("drepte2.out", "w", stdout);
	
	scanf("%d", &x);
	sol += (long long)x * (x + 1) / 2;
	
	printf("%lld", sol);
	return 0;
}
