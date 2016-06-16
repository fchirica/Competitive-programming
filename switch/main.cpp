#include <stdio.h>

int main()
{
	int A, B, sol = 1, i;

	freopen("cifre3.in", "r", stdin);
	freopen("cifre3.out", "w", stdout);

	scanf("%d%d", &A, &B);

	for (i = 1; i <= B; i ++)
		sol = sol + (i + 1) * (i + 1) * (i + 1);

	if (B > 1)
		sol ++;
	printf("%d", sol);
	return 0;
}
