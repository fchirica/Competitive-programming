#include <stdio.h>

int main()
{
	int x0, y0, x1, y1;
	
	freopen("scalecrop.in", "r", stdin);
	freopen("scalecrop.out", "w", stdout);
	
	scanf("%d%d%d%d", &x1, &y1, &x0, &y0);
	double scale = (double)x1 / x0;
	if ((double)y1 / y0 - scale > 0.0000001)
		scale = (double)y1 / y0;
	double newx = x0 * scale, newy = y0 * scale;
	
	printf("%.2lf %.2lf", newx, newy);
	return 0;
}