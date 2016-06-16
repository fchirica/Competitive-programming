//Sincere condoleante Mihai Patrascu!

#include <stdio.h>
#include <vector>
#define MOD 666013

using namespace std;

vector <long long> H[MOD];

void add(long long now)
{
	int where = now % MOD;
	
	if (where < 0)
		where = where * (-1);
	H[where].push_back(now);
}

int exist(long long now)
{
	int where = now % MOD, num = 0;
	if (where < 0)
		where = where * (-1);
	vector <long long> :: iterator it;
	
	for (it = H[where].begin(); it != H[where].end(); it ++)
		if (*it == now)
			num ++;
	return num;
}

int main()
{
	int a1, a2, a3, a4, a5, x1, x2, x3, x4, x5, sol = 0;
	long long now;
	
	freopen("eqs.in", "r", stdin);
	freopen("eqs.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	a1 = a1 * (-1); a2 = a2 * (-1);
	
	for (x1 = -50; x1 <= 50; x1 ++)
		for (x2 = -50; x2 <= 50; x2 ++)
			if (x1 * x2)
			{
				now = x1 * x1 * x1 * a1 + x2 * x2 * x2 * a2;
				add(now);
			}
		
	for (x3 = -50; x3 <= 50; x3 ++)
		for (x4 = -50; x4 <= 50; x4 ++)
			for (x5 = -50; x5 <= 50; x5 ++)
				if (x3 * x4 * x5)
				{
					now = x3 * x3 * x3 * a3 + x4 * x4 * x4 * a4 + x5 * x5 * x5 * a5;
					if (exist(now))
						sol += exist(now);
				}
		
	printf("%d", sol);
	return 0;
}
