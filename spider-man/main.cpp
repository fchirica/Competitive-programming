#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	double xc, yc, R;
	double x1, y1, x2, y2;

	freopen("spider-man.in", "r", stdin);
	freopen("spider-man.out", "w", stdout);
	
	scanf("%lf%lf%lf%lf%lf%lf%lf", &xc, &yc, &R, &x1, &y1, &x2, &y2);
	
	x1 = x1 - xc; x2 = x2 - xc;
	y1 = y1 - yc; y2 = y2 - yc;
	
	double base = sqrt((x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2));
	double X = R * (x1 + x2) / base;
	double Y = R * (y1 + y2) / base;
		
	printf("%lf", dist(X, Y, x1, y1) + dist(X, Y, x2, y2));
	return 0;
}
