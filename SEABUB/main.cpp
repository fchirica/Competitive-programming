/*
 * Author: Cosmin Gheorghe
 * Time complexity: O(N^2 * big_numbers)
 */

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define NMAX 310
#define CMAX 1010
#define BASE 10000
#define NRC 4

int N, M;

char s[CMAX];

int poz[CMAX];

char used[NMAX];
int sol[NMAX];

int a[CMAX], b[CMAX], c[CMAX];
int na[NMAX], nb[NMAX];

void inm(int a[], int x)
{
	int i, t = 0;

	for (i = 1; i <= a[0] || t; i++, t /= BASE)
		a[i] = (t += a[i] * x) % BASE;

	a[0] = i - 1;
}

void imp(int a[], int x)
{
	int i, t = 0;

	for (i = a[0]; i >= 1; i--, t %= x)
		a[i] = (t = t * BASE + a[i]) / x;

	while (a[0] && !a[a[0]]) a[0]--;
}

void scad(int a[], int b[])
{
	int i;

	for (i = 1; i <= a[0] || i <= b[0]; i++) {
		a[i] -= b[i];
		if (a[i] < 0) a[i] += BASE, a[i + 1]--;
	}

	while (a[0] && !a[a[0]]) a[0]--;
}

int mai_mic(int a[], int b[])
{
	if (a[0] < b[0]) return 1;
	if (a[0] > b[0]) return 0;

	for (int i = a[0]; i >= 1; i--) {
		if (a[i] < b[i]) return 1;
		if (a[i] > b[i]) return 0;
	}

	return 0;
}

int main()
{
	int i, j;

	freopen("bubblesort.in", "r", stdin);
	freopen("bubblesort.out", "w", stdout);

	scanf("%d %d %s", &N, &M, s);

	int n = strlen(s);

	for (i = n - 1; i >= 0; i -= NRC) {
		int q = 0;
		for (j = max(0, i - NRC + 1); j <= i; j++)
			q = q * 10 + s[j] - '0';

		poz[++poz[0]] = q;
	}

//	print_nr(poz);

	// si acum reconstituirea


	a[0] = 1; a[1] = 1; b[0] = 1; b[1] = 1;
	for (i = 1; i <= N; i++) {

		na[i] = min(M, N - i + 1);
		nb[i] = min(M-1, N - i + 1);

		inm(a, na[i]);
		inm(b, nb[i]);
	}

	int ordc = 0;

	for (i = 1; i <= N; i++) {
		// vad ce pot sa pun pe pozitia i

		for (j = 1; j <= N; j++) {
			if (used[j]) continue;

			sol[i] = j;
			used[j] = 1;

			imp(a, na[j]);
			imp(b, nb[j]);

			memcpy(c, a, sizeof(a));
			scad(c, b);

			if (mai_mic(c, poz)) {
				scad(poz, c);

				used[j] = 0;
				na[j]--; nb[j]--;
				inm(a, na[j]);
				inm(b, nb[j]);
			} else break;
		}

		ordc = max(ordc, i - j + 1);
		if (ordc > M-1) memset(b, 0, sizeof(b));
	}

	for (i = 1; i <= N; i++) printf("%d ", sol[i]);

	return 0;
}


