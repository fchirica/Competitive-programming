#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

int x[5100], uq[5100];
map <int, bool> used;

int main()
{
	int i, j, n = 0, N;
	
	freopen("secv.in", "r", stdin);
	freopen("secv.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d", &x[i]);
		if (used[x[i]] == 0)
		{
			uq[++ n] = x[i];
			used[x[i]] = 1;
		}
	}
	
	sort(uq + 1, uq + n + 1);
	
	int best = 1 << 30;
	
	for (i = 1; i <= N; i ++)
		if (x[i] == uq[1])
		{
			int matched = 1;
			for (j = i + 1; j <= N + 1; j ++)
			{
				if (matched == n)
				{
					int ret = j - i;
					if (ret < best)
						best = ret;
					break;
				}
				if (x[j] == uq[matched + 1])
					matched ++;
			}	
		}
		
	if (best == 1 << 30)
		best = -1;
	
	printf("%d", best);
	return 0;
}
