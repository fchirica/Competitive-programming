#include <stdio.h>

int main ()
{
	int wf, hf, wp, hp;
	double prodmax = 1, rep, x, y;
	
	freopen ("scalecrop.in", "r", stdin);
	freopen ("scalecrop.out", "w", stdout);
	
	scanf ("%d%d%d%d", &wf, &hf, &wp, &hp);
	
	x = wf;
	rep = (double)wf / wp;
	y = rep * hp;
	prodmax = x * y;
	
	newy = hf;
	rep = (double)hf / hp;
	newx = rep * 