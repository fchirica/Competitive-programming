#include <stdio.h>

int perm[2000100], sol[2000100], now[2000100], pos[2000100];
bool used[2000100];

void build(int N)
{
	int middle = N / 2 + 1;
	int i;
	
	if (N == 0)
		return ;
	
	for (i = middle; i <= N; i ++)
		perm[++ perm[0]] = i;
	build(middle - 1);
}

int main()
{
	int i, j, N, guta, salam, len = 0;
	long long K;
	
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	
	scanf("%d%lld", &N, &K);
	build(N);
	
	for (i = 1; i <= N; i ++)
		if (used[i] == 0)
		{
			len = 0;
			now[0] = 0;
			guta = i; 
			pos[0] = 0; pos[++ pos[0]] = i;
			while (1)
			{
				guta = perm[guta];
				if (used[guta])
					break;
				now[++ len] = guta;
				pos[++ pos[0]] = guta;
				used[guta] = 1;
			}
			salam = (K - 1) % len;
			for (j = 1; j <= len; j ++)
			{
				int where = j - salam;
				if (where <= 0)
					where = len - salam + j;
				sol[pos[where]] = now[j];
			}
		}
	
	int ret = 0;
	for (i = 1; i <= N; i ++)
		ret = (ret * 13 + sol[i]) % 1299827;
	printf("%d", ret);
	return 0;
}

