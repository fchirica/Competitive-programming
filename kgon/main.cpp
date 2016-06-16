//Eu sunt Aladdin cel fermecat si va frec pe toti.

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#define PI 2 * acos(0)
#define EPS 0.000001

using namespace std;

double x[100100];

inline int comp(double A, double B) {
	return A - B <= EPS * (-1);
}

double ab(double X) {
	if (X > EPS)
		return X;
	return -X;
}

bool search(double val, int N) {
	int st = 1, dr = N, med;
	while (st <= dr) {
		med = (st + dr) / 2;
		if (ab(x[med] - val) <= EPS)
			return 1;
		if (x[med] - val >= EPS)
			dr = med - 1;
		else
			st = med + 1;
	}
	return 0;
}

void read(double &X) {
	char num[1024];
	gets(num + 1);
	int i, N = strlen(num + 1);
	
	double r1 = 0, pt = 0, sw = 1;
	int parse = 0;
	for (i = 1; i <= N; i ++) {
		if (num[i] == '.') {
			parse ++; continue; 
		}
		if (parse == 0)
			r1 = r1 * 10 + num[i] - '0';
		else
			sw = sw / 10, pt = pt * 10 + num[i] - '0';
	}
	
	X = r1 + sw * pt;
}

int main() {
	freopen("kgon.in", "r", stdin);
	freopen("kgon.out", "w", stdout);
	
	int i, j, N, K;
	double R;
	
	scanf("%d%d", &N, &K);
	scanf("%lf\n", &R);
	for (i = 1; i <= N; i ++) {
		double val;
		read(val);
		x[i] = 180 * val / (PI * R);
	}
	
	sort(x + 1, x + N + 1, comp);
	
	double step = (double)360 / K;
	int sol = 0;
	
	for (i = 1; i <= N && step - x[i] >= EPS; i ++) {
		double unghi = x[i];
		bool valid = true;
		
		for (j = 1; j <= K; j ++) {
			if (search(unghi, N) == 0) {
				valid = false;
				break;
			}
			unghi += step;
		}
		
		sol += valid;
	}
		
	printf("%d", sol);
	return 0;
}
