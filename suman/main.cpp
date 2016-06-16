#include <stdio.h>
#include <algorithm>

using namespace std;

int K, N, x[25], st[25];
long long sol = 0;

void update(int lev, int lcm) {
	if (lev % 2)
		sol += 1LL * lcm * (N / lcm) * (N / lcm + 1) / 2;
	else
		sol -= 1LL * lcm * (N / lcm) * (N / lcm + 1) / 2;
}

int gcd(int A, int B) {
	int r;
	while (B) {
		r = A % B;
		A = B;
		B = r;
	}
	return A;
}

void back(int lev, int lcm) {
	int i;
	for (i = st[lev - 1] + 1; i <= K; i ++) {
		long long nlcm;
		nlcm = 1LL * lcm * x[i] / gcd(lcm, x[i]);
		if (nlcm > N)
			continue;
		st[lev] = i;
		update(lev, nlcm);
		back(lev + 1, nlcm);
	}
}

int main() {
	freopen("suman.in", "r", stdin);
	freopen("suman.out", "w", stdout);
	
	int i;
	scanf("%d%d", &N, &K);
	for (i = 1; i <= K; i ++)
		scanf("%d", &x[i]);
	sort(x + 1, x + K + 1);

	back(1, 1);
	printf("%lld", sol);
	
	return 0;
}
