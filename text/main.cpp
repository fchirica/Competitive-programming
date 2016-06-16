#include <stdio.h>
#include <ctype.h>

int main()
{
	int words = 0, let = 0;
	char ch;
	bool isWord = false;
	
	freopen("text.in", "r", stdin);
	freopen("text.out", "w", stdout);
	
	while (scanf("%c", &ch) != EOF)
	{
		if (isalpha(ch))
			let ++, isWord = true;
		else
			if (isWord)
				words ++, isWord = false;
	}
	
	printf("%d", let / words);
	return 0;
}
