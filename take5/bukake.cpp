#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, x[1024];

struct suma
{
	short x, y;
};

vector <suma> sleft, sright;

int get(suma X)
{
	return x[X.x] + x[X.y];
}

inline bool comp(suma A, suma B)
{
	return get(A) < get(B);
}

void makeRight()
{
	suma ret;
	
	for (ret.x = 1; ret.x <= N; ret.x ++)
		for (ret.y = ret.x + 1; ret.y <= N; ret.y ++)
			sright.push_back(ret);
	
	sort(sright.begin(), sright.end(), comp);
}

void scoate(int X)
{
	//Stergerea cu smenul lui Radu

	vector <suma> good;
	int i;
	
	for (i = 0; i < (int)sright.size(); i ++)
		if (sright[i].x != X)
			good.push_back(sright[i]);
	
	sright = good;
}

void baga(int X)
{
	//Interclasare clasica

	vector <suma> news, good;
	int i;

	//news contine toate sumele de forma (i, X) care trebuiesc interclasate la sirul vechi (sleft).	
	//good va contine sirul interclasat

	for (i = 1; i < X; i ++)
	{
		suma wefgef;
		wefgef.x = i; wefgef.y = X;
		news.push_back(wefgef);
	}
	
	int N = news.size(), M = sleft.size(), j = 0;
	i = 0;
	
	while (i != N || j != M)
	{
		if (i == N)
		{
			good.push_back(sleft[j ++]);
			continue;
		}
		if (j == M)
		{
			good.push_back(news[i ++]);
			continue;
		}
		if (get(news[i]) < get(sleft[j]))
			good.push_back(news[i ++]);
		else
			good.push_back(sleft[j ++]);
	}
	
	sleft = good;
}

int main()
{
	int i, S, sol = 0;
	
	freopen("take5.in", "r", stdin);
	freopen("take5.out", "w", stdout);
	
	scanf("%d%d", &N, &S);
	for (i = 1; i <= N; i ++)
		scanf("%d", &x[i]);
	
	//Initial toate sumele sunt in dreapta. Fac toate sumele posibile si le sortez. 
	sort(x + 1, x + N + 1);
	makeRight();
	
	for (i = 1; i <= N; i ++)
	{
		//Elimin toate sumele care il contineau pe i din dreapta
		scoate(i);
		//Adaug toate sumele care se pot forma cu i - 1
		baga(i - 1);
		
		//Am x[i] un termen fixat din cele 5, iar sumele sunt corecte acum. Aleg 2 din stanga si 2 din dreapta
		//Suma totala a celor 4 elemente trebuie sa fie wanted.
		int wanted = S - x[i];
		//howl si howr tin minte cate sume am in total in stanga si in dreapta.
		int howl = sleft.size() - 1, howr = sright.size() - 1, idx1, idx2 = howr;

		if (wanted < 0)
			continue;

		//idx1 si idx2 sunt cei 2 pointeri. Initial, idx1 e pozitionat pe prima suma din stanga si idx2 pe ultima din dreapta.
		for (idx1 = 0; idx1 <= howl; idx1 ++)
		{
			//Pt un idx1 fixat, gasesc cel mai mare idx2 astfel incat x[i] + suma(idx1) + suma(idx2) <= S

			while (idx2 >= 0 && get(sleft[idx1]) + get(sright[idx2]) > wanted)
				idx2 --;
			
			if (idx2 < 0)
				break;
			//Verific daca x[i] + suma(idx1) + suma(idx2) = S. Daca da, vad cu where cea mai din stanga pozitie
			//posibila pt idx2 astfel incat x[i] + suma(idx1) + suma(where) = S
			if (get(sleft[idx1]) + get(sright[idx2]) == wanted)
			{
				int where;
				
				where = idx2;
				while (where >= 0 && get(sleft[idx1]) + get(sright[where]) == wanted)
					where --;
				//O solutie de suma S va fi cu idx2 intre where + 1, where + 2, ... , idx2 - 1, idx2.
				//Deci, in total avem idx2 - (where + 1) + 1 = idx2 - where solutii posibile.
				sol += idx2 - where;
			}			
		}			
	}
	
	printf("%d", sol);
	return 0;
}
