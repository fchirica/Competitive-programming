#include <stdio.h>

int win[15000];

bool check(int X) {
	return win[X];
}

int main() {
	int i, d;
	
	for (i = 1; i < 15000; ++i)
		for (d = 2; d < i; ++d)
			if (i % d == 0)
				if (win[i - d] == false)
					win[i] = true;
	
	freopen("sol.out", "w", stdout);
	for (i = 2; i < 15000; ++i)
		if (win[i] == 0 && i % 2 == 0)
			printf("%d, ", i);
				
	return 0;
}