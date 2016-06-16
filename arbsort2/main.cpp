#include <stdio.h>
#include <string.h>

int dp[200][200][300], pos[300];
char tmp[300];

void baga(int A[], int B[], int C[])
{
	int i, tr = 0;
	
	C[0] = A[0];
	if (B[0] > C[0])
		C[0] = B[0];
	
	for (i = 1; i <= C[0]; i ++)
	{
		C[i] = A[i] + B[i] + tr;
		tr = C[i] / 10;
		C[i] = C[i] % 10;
	}

	if (tr)
		C[++ C[0]] = 1;
}

void scoate(int A[], int B[])
{
	int i, tr = 0;
	
	for (i = 1; i <= A[0]; i ++)
	{
		A[i] = A[i] - B[i] - tr;
		
		tr = 0;
		if (A[i] < 0)
			A[i] += 10, tr = 1;
	}

	while (A[0] && A[A[0]] == 0)
		A[0] --;
}

bool notGreater(int A[], int B[])
{
	if (A[0] > B[0])
		return 0;
	if (A[0] < B[0])
		return 1;
	
	int i;
	
	for (i = A[0]; i >= 1; i --)
	{
		if (A[i] > B[i])
			return 0;
		if (A[i] < B[i])
			return 1;
	}
	
	return 1;
}

int main()
{
    int i, j, N;
	
	freopen("arbsort.in", "r", stdin);
    freopen("arbsort.out", "w", stdout);
 
    scanf("%d\n", &N);
    N --; printf("0 ");
 
	gets(tmp + 1);
	pos[0] = strlen(tmp + 1);
	for (i = 1; i <= pos[0]; i ++)
		pos[pos[0] - i + 1] = tmp[i] - '0';
	
    for (i = N; i >= 1; i --)
        dp[N][i][0] = dp[N][i][1] = 1;
    for (i = N - 1; i >= 1; i --)
    {
        baga(dp[i + 1][i], dp[i + 1][i + 1], dp[i][i]);
        for (j = i - 1; j >= 1; j --)
            baga(dp[i][j + 1], dp[i + 1][j], dp[i][j]);
    }
 
    int last = 1;
 
    for (i = 1; i <= N; i ++)
        if (notGreater(pos, dp[i][last]))
            printf("%d ", last);
        else
            scoate(pos, dp[i][last ++]), i --;
 
    return 0;
}
