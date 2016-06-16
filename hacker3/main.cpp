#include <fstream>
#include <iostream>
#include <stdio.h>

const int DIM = (1 << 14);

using namespace std;

struct hacker
{
	int x, y;
} X[DIM + 100];

ofstream fout("hacker3.out");

int main()
{
	int i, N = -1, x, y, numElem, N2, okay = 0;
	long long sol = 0, lastsol = 0;

	ifstream pula("hacker3.in");
	pula >> N;
	pula.close();
	
	while (N)
	{
		ifstream fin("hacker3.in");
		fin >> N2;
		for (i = 1; i + DIM <= N; i ++)
			fin >> x >> y;
		numElem = 0;
		for (; i <= N; i ++)
		{
			numElem ++;
			fin >> X[numElem].x >> X[numElem].y;
		}
		for (i = numElem; i >= 1; i --)
		{
			sol = 2 * lastsol + X[i].x;
			if (lastsol + X[i].y < sol)
				sol = lastsol + X[i].y;
			lastsol = sol;
		}
		N = N - numElem;
		if (N < 0)
			break;
		fin.close();
	}
	
	fout << sol;
	
	return 0;
}