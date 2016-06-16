#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[100100];
int deg[100100];

int main()
{
	int T, N, i;
	
	freopen("itree.in", "r", stdin);
	freopen("itree.out", "w", stdout);
	
	scanf("%d", &T);
	while (T --)
	{
		int x0, y0;
		
		scanf("%d", &N);
		for (i = 1; i < N; i ++)
		{
			scanf("%d%d", &x0, &y0);
			G[x0].push_back(y0);
			G[y0].push_back(x0);
			deg[x0] ++; deg[y0] ++;
		}
		
		bool isSolution = true;
		vector <int> :: iterator it;
		
		for (i = 1; i <= N && isSolution; i ++)
		{
			int cnt = 0;
			
			for (it = G[i].begin(); it != G[i].end(); it ++)
				if (deg[*it] > 1)
					cnt ++;
			if (cnt > 2)
				isSolution = false;
		}
		
		if (isSolution)
			printf("YES\n");
		else
			printf("NO\n");
		
		for (i = 1; i <= N; i ++)
		{
			G[i].clear();
			deg[i] = 0;
		}
	}
	
	return 0;
}
