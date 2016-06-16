#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define NMAX 300010

struct Points{

	int x, y;
	int oxA, oxB;
};

int N, nrLines;
int lines[NMAX];
Points points[NMAX];

bool cmp (const Points &x, const Points &y) {

	if (x.oxB == y.oxB) return x.oxA > y.oxA;
	return x.oxB < y.oxB;
}

int binarySearch (int value) {

	int left = 1, right = nrLines, midd, poz = nrLines + 1;
	while (left <= right) {
		midd = (left + right) >> 1;
		if ( lines[midd] >= value) poz = midd, right = midd - 1;
		else left = midd + 1;
	}

	return poz;
}

void solve () {

	sort (points + 1, points + N + 1, cmp);

	for (int i = 1; i <= N; i++) {

		int poz = binarySearch ( points[i].oxA );
		if (poz > nrLines) lines[++nrLines] = points[i].oxA;
		else lines[poz] = points[i].oxA;
	}

	printf ("%d\n", nrLines);
}

void readData () {

	scanf ("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf ("%d %d", &points[i].x, &points[i].y);
		points[i].oxA = points[i].x - points[i].y;
		points[i].oxB = points[i].x + points[i].y;
	}
}

int main () {

	freopen ("linii.in", "r", stdin);
    freopen ("linii.out", "w", stdout);

	readData ();
	solve ();

	return 0;
}

