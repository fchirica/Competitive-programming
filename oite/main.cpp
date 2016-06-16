#include <stdio.h>
#include <vector>
#define MOD 6971

using namespace std;

int x[1030];
vector <int> H[MOD];

void baga(int val)
{
	int where = val % MOD;
	
	H[where].push_back(val);
}

int search(int val)
{
	int where = val % MOD;
	vector <int> :: iterator it;
	
	int sum = 0;
	
	if (val < 0)
		return 0;
	
	for (it = H[where].begin(); it != H[where].end(); it ++)
		if (*it == val)
			sum ++; 
	return sum;
}

int take4(int x[], int N, int S)
{
	int i, j, ans = 0;
	
	for (i = 1; i <= N; i ++)
	{
		for (j = i + 1; j <= N; j ++)
		{
			int ret = S - x[i] - x[j];
			ans += search(ret);
		}
		for (j = 1; j < i; j ++)
			baga(x[i] + x[j]);
	}
	
	return ans;
}

int main()
{
	int i, N, S;
	
	freopen("oite.in", "r", stdin);
	freopen("oite.out", "w", stdout);
	
	scanf("%d%d", &N, &S);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);

	printf("%d", take4(x, N, S));
	return 0;
}
