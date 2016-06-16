#include <stdio.h>

int cow1[50100], cow2[50100];

int main()
{
	int i, N, M, tot = 0, tot2 = 0;
	char ch;
	
	freopen("greetings.in", "r", stdin);
	freopen("greetings.out", "w", stdout);
	
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; i ++)
	{
		scanf("%d %c\n", &cow1[i], &ch);
		tot += cow1[i];
		if (ch == 'L')
			cow1[i] = cow1[i] * (-1);
	}
	
	for (i = 1; i <= M; i ++)
	{
		scanf("%d %c\n", &cow2[i], &ch);
		tot2 += cow2[i];
		if (ch == 'L')
			cow2[i] = cow2[i] * (-1);
	}
	
	int idx1 = 1, idx2 = 1, pos1 = 0, pos2 = 0, sol = 0;
	
	if (tot2 > tot)
		tot = tot2;
	for (i = 1; i <= tot; i ++)
	{
		bool hadMeeted = (pos1 == pos2);
		
		if (cow1[idx1] < 0)
			pos1 --;
		if (cow1[idx1] > 0)
			pos1 ++;
		if (cow2[idx2] < 0)
			pos2 --;
		if (cow2[idx2] > 0)
			pos2 ++;
		if (pos1 == pos2 && hadMeeted == false)
			sol ++;
		
		if (cow1[idx1] < 0)
			cow1[idx1] ++; 
		if (cow1[idx1] > 0)
			cow1[idx1] --;
		if (cow2[idx2] < 0)
			cow2[idx2] ++;
		if (cow2[idx2] > 0)
			cow2[idx2] --;
		
		if (cow1[idx1] == 0 && idx1 < N)
			idx1 ++;
		if (cow2[idx2] == 0 && idx2 < M)
			idx2 ++;
	}
	
	printf("%d", sol);
	return 0;
}
