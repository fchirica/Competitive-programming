#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int i, N, K;
	map <int, int> M;
	
	freopen("facebook.in", "r", stdin);
	freopen("facebook.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i ++)
	{
		int x;
		scanf("%d", &x);
		
		M[x] ++;
		if (M[x] == K)
		{
			printf("%d", i - K);
			return 0;
		}
	}
	
	printf("-1");
	return 0;
}
