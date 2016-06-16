#include <stdio.h>
#include <queue>

using namespace std;

struct comp
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

priority_queue <int, vector <int>, comp> H;

int main()
{
	int i, N, K, sneg = 0, spos = 0, sol = 0, smin = 1 << 30;
	
	freopen("ephie.in", "r", stdin);
	freopen("ephie.out", "w", stdout);
	
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i ++)
	{
		int good, bad;
		
		scanf("%d%d", &good, &bad);
		
		sneg = sneg - bad;
		if (i <= K)
		{
			H.push(good + bad);
			if (good + bad < smin)
				smin = good + bad;
			spos += good + bad;
		}
		else
		{
			if (good + bad > smin)
			{
				H.pop();
				H.push(good + bad);
				spos = spos - smin + good + bad;
				smin = H.top();
			}
		}
		
		if (spos + sneg > sol)
			sol = spos + sneg;
	}
	
	printf("%d", sol);
	return 0;
}
