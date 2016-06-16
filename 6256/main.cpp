#include <stdio.h>
#include <string.h>
#include <algorithm>
 
using namespace std;
 
int x[200100], zero[200100], Fenwick[200100];

//zero[i] is LSB(i) function
void Preprocess(int N) {
    int i, pow = 1;
 
    zero[1] = 1;
    for (i = 2; i <= N; i ++)
        if (pow * 2 == i)
            pow = pow * 2, zero[i] = i;
        else
            zero[i] = zero[i - pow];
}
 
void AddFenwick(int val, int N) {
    while (val <= N) {
        Fenwick[val] ++;
        val = val + zero[val];
    }
}
 
int QueryFenwick(int val) {
    int ans = 0;
	while (val) {
        ans = ans + Fenwick[val];
        val = val - zero[val];
    }
	return ans;
}
 
void MakePerm(int N) {
    int now[200100], i, left, right, med;
	for (i = 1; i <= N; i ++)
        now[i] = x[i];
    sort (now + 1, now + N + 1);
	for (i = 1; i <= N; i ++) {
        left = 1; right = N;
		while (left <= right) {
            med = (left + right) / 2;
            if (now[med] < x[i])
                left = med + 1;
            else
                right = med - 1;
        }
		x[i] = left;
    }
}
 
void RunSlow(int N) {
    int i, j, sol = 0;
	for (i = 1; i < N; i ++)
        for (j = i + 1; j <= N; j ++)
            if (x[i] > x[j])
                sol ++;
	printf ("EXPECTED: %d\n", sol);
}
 
void Solve(int N) {
    int i;
	long long sol = 0;
	for (i = N; i >= 1; i -- ) {
        sol = sol + QueryFenwick(x[i] - 1);
        AddFenwick(x[i], N);
    }
	printf ("%lld\n", sol);
}
 
int main()
{
	//freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
 
	Preprocess(200000);
	
	int testCases;
	scanf("%d", &testCases);
	while (testCases --) {
	    int i, N;
		memset(Fenwick, 0, sizeof(Fenwick));
		scanf ("%d", &N);
		for (i = 1; i <= N; i ++)
			scanf("%d", &x[i]);
 
		//RunSlow(N);
		MakePerm(N);
		Solve(N);
	}
    return 0;
}
