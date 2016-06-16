#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN		16000
#define MAX_COORD	10001
#define MARK_REP	0x8000

int n;
int xy[MAXN][2];
int a[MAXN], b[MAXN];
unsigned up[MAXN];
int xcnt[MAXN + 1];

void sort(int *a, int *b, int x)
{
	int cnt[MAX_COORD], i;

	memset(cnt, 0, sizeof(cnt));
	for(i = 0; i < n; i++)
		cnt[xy[i][x]]++;
	for(i = 1; i < MAX_COORD; i++)
		cnt[i] += cnt[i - 1];
	memmove(cnt + 1, cnt, sizeof(cnt) - sizeof(*cnt));
	*cnt = 0;
	for(i = n; i--; a++)
		b[cnt[xy[*a][x]]++] = *a;
}

int getrep(int x)
{
	int y;

	for(y = x; !(up[y] & MARK_REP); y = up[y]) ;
	while(x != y) {
		int tmp = up[x];
		up[x] = y;
		x = tmp;
	}
	return(y);
}

void uniq(int *p, int x)
{
	int i, rep1, rep2;

	for(i = n; --i; p++) {
		if((xy[*p][x] != xy[p[1]][x])
		  || (xy[*p][1 - x] + 1 != xy[p[1]][1 - x]))
			continue;
		rep1 = getrep(*p);
		rep2 = getrep(p[1]);
		if(rep1 == rep2)
			continue;
		if(up[rep1] < up[rep2]) {
			int tmp = rep1;
			rep1 = rep2, rep2 = tmp;
		}
		up[rep1] += up[rep2] - MARK_REP;
		up[rep2] = rep1;
	}
}

int main()
{
	int i, k, sum = 0, nz = 0;

	freopen("banana.in", "r", stdin);
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++) {
		scanf("%d%d", xy[i], xy[i] + 1);
		up[i] = MARK_REP + 1;
		a[i] = i;
	}
	sort(a, b, 0);
	sort(b, a, 1);
	uniq(a, 1);
	sort(a, b, 0);
	uniq(b, 0);
	for(i = 0; i < n; i++)
		if(up[i] > MARK_REP) {
			nz++;
			xcnt[up[i] - MARK_REP]++;
		}
	for(i = n; i; i--) {
		if(xcnt[i] >= k) {
			sum += k * i;
			break;
		}
		sum += xcnt[i] * i;
		k -= xcnt[i];
	}
	freopen("banana.")
	printf("%d %d\n", nz, sum);
	return(0);
}

