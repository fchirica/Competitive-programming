#include <stdio.h>
#include <set>
#include <algorithm>
#define NMAX (1 << 11)

using namespace std;

struct query
{
	short int fin;
	int sum;
};

struct classcomp {
  bool operator() (const query& lhs, const query& rhs) const
  {return lhs.fin<rhs.fin;}
};

set <query, classcomp> Q[NMAX];

query mq(short X, int Y)
{
	query now;
	
	now.fin = X; now.sum = Y;
	
	return now;
}

inline bool comp (query X, query Y)
{
	return X.fin < Y.fin;
}

struct inter
{
	short int x, y;
	int sum;
} x[NMAX];

void getGoodIntervals(int N, int &M)
{
	int i, last;
	set <query> :: iterator it;
	query now;
	
	M = 0;
	for (i = 1; i <= N; i ++)
	{
		last = 1 << 30;
		for (it = Q[i].begin(); it != Q[i].end(); Q[i].erase (it), it ++)
		{
			now = *it;
			if (now.fin == last)
				continue;
			if (last == 1 << 30)
			{
				x[++ M].x = i; x[M].y = now.fin; x[M].sum = now.sum;
				last = now.fin;
				continue;
			}
			if (Q[x[M].y + 1].find (mq(now.fin, now.sum - x[M].sum)) == Q[x[M].y + 1].end())
				Q[x[M].y + 1].insert(mq(now.fin, now.sum - x[M].sum));
			last = now.fin;
		}
	}
}

int sol[NMAX], AIB[NMAX];

inline int lsb(int x)
{
	return x & -x;
}

int query (int pos)
{
	int sum = 0;
	
	while (pos)
	{
		sum += AIB[pos];
		pos = pos - lsb(pos);
	}

	return sum;
}

void update (int pos, int N, int val)
{
	int i;
	
	for (i = pos; i <= N; i += lsb(i))
		AIB[i] += val;
}
int main()
{
	int i, N, M, x0, y0, sum;
	
	freopen("reconst.in", "r", stdin);
	freopen("reconst.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d%d", &x0, &y0, &sum);
		Q[x0].insert(mq(y0, sum));
	}
	
	getGoodIntervals(N, M);
	
	for (i = M; i >= 1; i --)
	{
		sum = query(x[i].y) - query(x[i].x - 1);
		sol[x[i].x] = x[i].sum - sum;
		update(x[i].x, N, x[i].sum - sum);
	}
	
	for (i = 1; i <= N; i ++)
		printf("%d ", sol[i]);
	return 0;
}
