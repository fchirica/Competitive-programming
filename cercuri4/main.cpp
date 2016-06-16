#include <stdio.h>
#include <algorithm>
#include <math.h>
#define NMAX 5100

using namespace std;

struct cerc
{
	int x0, y0, R, F;
} x[NMAX];

inline long long dist(cerc A, cerc B)
{
	return ((long long)((long long)A.x0-B.x0)*(A.x0-B.x0)+(long long)((long long)A.y0 - B.y0)*(A.y0 - B.y0));
}

inline bool match(cerc A, cerc B)
{
	long long dst = dist(A, B);
	
	return dst <= ((long long)A.R - B.R) * ((long long)A.R - B.R);
}

inline bool comp(cerc A, cerc B)
{
	return A.R > B.R;
}

int sol[NMAX];

int main()
{
	int i, j, N;
	
	freopen("cercuri4.in", "r", stdin);
	freopen("cercuri4.out", "w", stdout);
	
	scanf("%d", &N);
	for (i = 1; i <= N; i ++)
		scanf("%d%d%d%d", &x[i].x0, &x[i].y0, &x[i].R, &x[i].F);
	sort(x + 1, x + N + 1, comp);

	for (i = 1; i <= N; i ++)
		sol[i] = x[i].F;

	for (i = 1; i <= N; i ++)
		for (j = 1; j < i; j ++)
			if (match(x[j], x[i]))
				sol[i] = max(sol[i], sol[j] + x[i].F);
	
	int ans = 0;
	
	for (i = 1; i <= N; i ++)
		if (sol[i] > ans)
			ans = sol[i];
	
	printf("%d", ans); 
	return 0;
}

