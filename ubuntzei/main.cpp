#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int sticky[20], dist[20][20], K;
vector <pair <int, int> > G[2012];

void Dijkstra(int idx, int x0, int N)
{
	multiset <pair <int, int> > H;
	vector <pair <int, int> > :: iterator it;
	
	int i, _dist[2012], used[2012];
	for (i = 1; i <= N; i ++)
	{
		_dist[i] = 1 << 30;
		used[i] = 0;
	}
	_dist[x0] = 0; H.insert(make_pair(0, x0));
	
	while (!H.empty())
	{
		pair <int, int> nod = *H.begin();
		H.erase(H.begin());
		
		if (used[nod.second])
			continue;
		_dist[nod.second] = nod.first;
		used[nod.second] = 1;
		
		for (it = G[nod.second].begin(); it != G[nod.second].end(); it ++)
			if (nod.first + it -> second < _dist[it -> first])
			{
				_dist[it -> first] = nod.first + it -> second;
				H.insert(make_pair(nod.first + it -> second, it -> first));
			}
	}
	
	for (i = 0; i <= K + 1; i ++)
		dist[idx][i] = _dist[sticky[i]];
}

int dp[16][1 << 15];

void getmin(int &A, int B)
{
	if (A > B)
		A = B;
}

void solve()
{
	int mask, now, b;
	
	dp[0][0] = 0;
	for (mask = 0; mask < (1 << K); mask ++)
		for (now = 0; now <= K; now ++)
			if (dp[now][mask] != 1 << 30)
				for (b = 1; b <= K; b ++)
					if ((mask & (1 << (b - 1))) == 0)
						getmin(dp[b][mask ^ (1 << (b - 1))], dp[now][mask] + dist[now][b]);
}

int main()
{
	int i, j, N, M;
	
	freopen("ubuntzei.in", "r", stdin);
	freopen("ubuntzei.out", "w", stdout);
	
	scanf("%d%d%d", &N, &M, &K);
	for (i = 1; i <= K; i ++)
		scanf("%d", &sticky[i]);
	sticky[0] = 1; sticky[K + 1] = N;
	for (i = 1; i <= M; i ++)
	{
		int x0, y0, c;
		
		scanf("%d%d%d", &x0, &y0, &c);
		G[x0].push_back(make_pair(y0, c));
		G[y0].push_back(make_pair(x0, c));
	}
	
	for (i = 0; i <= K + 1; i ++)
		Dijkstra(i, sticky[i], N);
	
	for (i = 0; i <= K; i ++)
		for (j = 0; j < (1 << K); j ++)
			dp[i][j] = 1 << 30;
	solve();
	
	int sol = 1 << 30;
	for (i = 1; i <= K; i ++)
		getmin(sol, dp[i][(1 << K) - 1] + dist[i][K + 1]);
	if (K == 0)
		sol = dist[0][1];
	
	printf("%d", sol);
	return 0;
}
