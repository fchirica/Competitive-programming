#include <stdio.h>

inline int ab(int X)
{
	return X > 0 ? X : -X;
}

int main()
{
	int i, x0, y0, S, N, sol = 0;
	
	freopen("cal.in", "r", stdin);
	freopen("cal.out", "w", stdout);
	
	scanf("%d%d%d%d", &x0, &y0, &S, &N);
	for (i = 1; i <= N; i ++)
	{
		int x1, y1;
		scanf("%d%d", &x1, &y1);
		if (ab(x0 - x1) + ab(y0 - y1) == S)
			sol ++;
	}
	
	printf("%d", sol);
	return 0;
}
