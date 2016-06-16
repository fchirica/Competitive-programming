#include <stdio.h>

inline int cnt(int X)
{
	int sol = 0;
	
	while (X)
	{
		sol ++;
		X = X & (X - 1);
	}
	
	return sol;
}

int main()
{
	int i, N, b1, b2, max = 0, sol = 0;
	
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i < (1 << N); i ++)
	{
		bool valid = true;
		
		for (b1 = 0; b1 < N; b1 ++) 
			for (b2 = b1 + 1; b2 < N; b2 ++)
				if ((i & (1 << b1)) && (i & (1 << b2)))
					if (3 * (b2 + 1) - 2 * (b1 + 1) <= N)
						if (i & (1 << (3 * (b2 + 1) - 2 * (b1 + 1) - 1)))
							valid = false;
		if (valid)
			if (cnt(i) > max)
				max = cnt(i), sol = i;
	}
	
	printf("%d\n", max);
	for (i = 0; i < N; i ++)
		if (sol & (1 << i))
			printf("%d ", i + 1);
	return 0;
}
