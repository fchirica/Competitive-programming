#include <stdio.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int N, cntR = 0;
char x[1024];
struct reteta {
	string x;
	int cnt;
} R[150];

int getInt(int pos) {
	while (!isdigit(x[pos]))
		pos ++;
	int num = 0;
	while (pos <= N && isdigit(x[pos])) {
		num = num * 10 + x[pos] - '0';
		pos ++;
	}
	return num;
}

string getString(int &pos) {
	string ans; 
	while (pos <= N) {
		if (!isalpha(x[pos]))
			return ans;
		ans += x[pos ++];
	}
	return ans;
}

inline int cmp(reteta A, reteta B) {
	return A.x < B.x;
}

void add(reteta A) {
	int i;
	for (i = 1; i <= cntR; i ++)
		if (R[i].x == A.x)  {
			R[i].cnt += A.cnt;
			return ;
		}
	R[++ cntR] = A;
}

void show(string X) {
	int i;
	for (i = 0; i < (int)X.size(); i ++)
		printf("%c", X[i]);
}

int main() {
	freopen("reteta2.in", "r", stdin);
	freopen("reteta2.out", "w", stdout);
	
	gets(x + 1);
	N = strlen(x + 1);
	
	int i, timp = 0;
	for (i = 1; i <= N; i ++) {
		if (x[i] == '(') 	
			x[i] = ' ';
		if (x[i] == ')') {
			x[i] = ' ';
			timp += getInt(i);
		}
	}
	
	printf("%d\n", timp);
	for (i = 1; i <= N; i ++)
		if (isalpha(x[i])) {
			reteta ret;
			ret.x = getString(i);
			ret.cnt = getInt(i);
			add(ret);
		}
		
	sort(R + 1, R + cntR + 1, cmp);
	for (i = 1; i <= cntR; i ++)
	{
		show(R[i].x); 
		printf(" %d\n", R[i].cnt);
	}
	return 0;
}
