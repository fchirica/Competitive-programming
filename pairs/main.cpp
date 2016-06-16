#include <stdio.h>
 
int x[100100], stieve[1000100], cnt[1000100];
bool is[1000100], bad[1000100];
 
int main()
{
    int i, j, N, vmax = -1;
     
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
     
    scanf("%d", &N);
    for (i = 1; i <= N; i ++)
    {
        scanf("%d", &x[i]);
        if (x[i] > vmax)
            vmax = x[i];
        is[x[i]] = true;
    }
     
    for (i = 2; i <= vmax; i ++)
        if (stieve[i] == 0)
            for (j = i; j <= vmax; j = j + i)
                stieve[j] ++;
	
	for (i = 2; i * i <= vmax; i ++)
		if (stieve[i] == 1)
			for (j = i * i; j <= vmax; j += i * i)
				bad[j] = true;
	
    for (i = 2; i <= vmax; i ++)
		if (bad[i] == false)
			for (j = i; j <= vmax; j = j + i)
				if (is[j])
					cnt[i] ++;
             
    long long ans = 1LL * N * (N - 1) / 2;
     
    for (i = 2; i <= vmax; i ++)
        if (stieve[i] % 2 == 0)
            ans = ans + 1LL * cnt[i] * (cnt[i] - 1) / 2;
        else
            ans = ans - 1LL * cnt[i] * (cnt[i] - 1) / 2;
         
    printf("%lld", ans);
    return 0;
}
