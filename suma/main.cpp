#include <stdio.h>

int main()
{
	int N, P;
	
	freopen("suma.in", "r", stdin);
	freopen("suma.out", "w", stdout);
	
	scanf("%d%d", &N, &P);
	int A = N, B = N + 1, C = 2 * N + 1;
	
	if (A % 2 == 0)
		A = A / 2;
	else
		B = B / 2;
	bool added = false;
	if (A % 3 == 0)
		A = A / 3, added = true;
	if (!added && B % 3 == 0)
		B = B / 3, added = true;
	if (!added && C % 3 == 0)
		C = C / 3, added = true;
	
	int res = 1LL * A * B % P;
	res = 1LL * res * C % P;
	
	int tmp = 1LL * (N % P) * ((N + 1) % P) / 2; 
	res = res - tmp % P;
	while (res < 0)
		res += P;
	
	printf("%d", res);
	return 0;
}
