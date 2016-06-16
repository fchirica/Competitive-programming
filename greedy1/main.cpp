#include <stdio.h>
#include <string.h>

using namespace std;

int x[100], AIB[100], pos[100];

inline int lsb(int value)
{
	return value & -value;
}

int query(int now)
{
	int ans = 0;
	for (; now > 0; now = now - lsb(now))
		ans += AIB[now];
	return ans;
}

void update(int now, int N)
{
	for (; now <= N; now = now + lsb(now))
		AIB[now] ++;
}

int main()
{
	int i, test, testCases, N, sol, now;
	
	scanf("%d", &testCases);
	for (test = 1; test <= testCases; test ++)
	{
		memset(x, 0, sizeof(x));
		memset(AIB, 0, sizeof(AIB));
		memset(pos, 0, sizeof(pos));
		
		scanf("%d", &N);
		for (i = 1; i <= N; i ++)
		{
			scanf("%d", &x[i]);
			pos[x[i]] = i;
		}
		
		sol = 0;
		for (i = 1; i <= N; i ++)
		{
			sol += pos[i] - query(pos[i]) - 1;
			update(pos[i], N);
		}
		
		printf("Optimal train swapping takes %d swaps.\n", sol);
	}
	
	return 0;
}
