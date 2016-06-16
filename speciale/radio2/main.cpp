#include <stdio.h>
#include <vector>
#define MOD 666013
#define BASE 30

using namespace std;

int N, M, L, K, len;
char x[1000100], word[3000];
vector <int> H[MOD];

void buildHash()
{
	int i, ret = 0, diff = 1;
	
	for (i = 1; i <= len; i ++)
		ret = (ret * BASE + x[i] - 'a') % MOD;
	H[ret].push_back(1);
	
	for (i = 1; i < len; i ++)
		diff = diff * BASE % MOD;
	
	for (i = len + 1; i <= N; i ++)
	{
		ret = ret - (x[i - len] - 'a') * diff;
		while (ret < 0)
			ret += MOD;
		ret = (ret * BASE + x[i] - 'a') % MOD;
		H[ret].push_back(i - len + 1);
	}
}

bool match(int posx, int posw)
{
	int i;
	
	for (i = 1; i <= len; i ++)
		if (x[posx + i - 1] != word[posw + i - 1])
			return 0;
	return 1;
}

bool solution(int start)
{
	int i, diff = 0;
	
	for (i = start; i < start + L; i ++)
		if (x[i] != word[i - start + 1])
		{
			++ diff;
			if (diff > K)
				return 0;
		}
	return 1;
}

void solve()
{
	int i, j;
	vector <int> :: iterator it;
	
	for (i = 1; i + len - 1 <= L; i += len)
	{
		int hash = 0;
		
		for (j = i; j < i + len; j ++)
			hash = (hash * BASE + word[j] - 'a') % MOD;
		
		for (it = H[hash].begin(); it != H[hash].end(); it ++)
			if (match(*it, i))
			{
				int pos = *it - i + 1;
				
				if (solution(pos))
				{
					printf("1\n");
					return ;
				}
			}
	}
	
	printf("0\n");
}

int main()
{
	int i;
	
	freopen("radio2.in", "r", stdin);
	freopen("radio2.out", "w", stdout);
	
	scanf("%d%d%d%d\n", &N, &M, &L, &K);
	gets(x + 1);
	
	len = L / (K + 1);
	buildHash();
	
	for (i = 1; i <= M; i ++)
	{
		gets(word + 1);
		solve();
	}
	
	return 0;
}
