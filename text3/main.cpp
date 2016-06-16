#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

short dp[26][20001];
char words[20001][20];

inline bool match(int ch, char x[])
{
	ch = ch + (int)'a';
	int len = strlen(x) - 1;
	return x[len] == ch;
}

void recon(int idx, int letter)
{
	if (idx == 0)
		return ;
	
	if (match(letter, words[idx]))
		if (dp[letter][idx] == dp[words[idx][0] - 'a'][idx - 1])
		{
			recon(idx - 1, words[idx][0] - 'a');
			printf("%s\n", words[idx]);
			return ;
		}
		
	recon(idx - 1, letter);
}

int main()
{
	char nowWord[30];
	int i, j, N = 0;
	
	freopen("text3.in", "r", stdin);
	freopen("text3.out", "w", stdout);
	
	while (scanf(" %s ", &nowWord) != EOF)
		memcpy(words[++ N], nowWord, sizeof(nowWord));
	
	printf("%d\n", N);
	
	for (i = 0; i < 26; i ++)
		dp[i][0] = 0;
	for (i = 0; i < 26; i ++)
		for (j = 1; j <= N; j ++)
			dp[i][j] = 1000000000;
	
	for (j = 1; j <= N; j ++)
		for (i = 0; i < 26; i ++)
			if (match(i, words[j]))
				dp[i][j] = min((int)dp[words[j][0] - 'a'][j - 1], (int)dp[i][j - 1] + 1);
			else
				dp[i][j] = dp[i][j - 1] + 1;
	
	int sol = 1000000000;
	
	for (i = 0; i < 26; i ++)
		if (dp[i][N] < sol)
			sol = dp[i][N];
	printf("%d\n", sol);
	
	for (i = 0; i < 26; i ++)
		if (dp[i][N] == sol)
		{
			recon(N, i);
			break;
		}
	
	return 0;
}
