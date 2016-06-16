#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

const int NMAX = 50100;
const int INF = 1 << 30;

class Dijkstra
{
	public:
	int N, M;
	int dist[NMAX];
	vector <pair <int, int> > G[NMAX];
	
	Dijkstra (int _N, int _M)
	{
		N = _N; M = _M;
	}
	void addEdge(int source, int sink, int cost)
	{
		G[source].push_back(make_pair(sink, cost));
	}
	
	void solve(int source)
	{
		multiset <pair <int, int> > Heap;
		vector <pair <int, int> > :: iterator it;
		pair<int, int> minnow, now;
		
		Heap.insert(make_pair(0, source));
		
		int i;
		for (i = 0; i <= N; i ++)
			dist[i] = INF;
		
		while (!Heap.empty())
		{
			minnow = *Heap.begin();
			Heap.erase(Heap.begin());
		
			if (dist[minnow.second] != INF)
				continue;
			dist[minnow.second] = minnow.first;
			
			for (it = G[minnow.second].begin(); it != G[minnow.second].end(); it ++)
			{
				now = *it;
				Heap.insert(make_pair(minnow.first + now.second, now.first));
			}
		}
	}
	
	int MinPath(int nod)
	{
		if (dist[nod] == INF)
			return 0;
		return dist[nod];
	}
};

int main()
{
	int i, N, M, source, sink, cost;
	
	freopen("dijkstra.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	
	Dijkstra x(N, M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d%d%d", &source, &sink, &cost);
		x.addEdge(source, sink, cost);
	}
	
	x.solve(1);
	for (i = 2; i <= N; i ++)
		printf("%d ", x.MinPath(i));
	return 0;
}
