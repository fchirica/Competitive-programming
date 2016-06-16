#include <stdio.h>
#include <vector>

using namespace std;

vector <pair <int, int> > G[250500];
vector <int> dmin[1024];
int sol[250500];

const int DIM = 1 << 13;
char buff[DIM];
int poz = 0;
 
void read (int &numar)
{
    numar = 0; 
    while (buff[poz] < '0' || buff[poz] > '9')     
		if (++poz == DIM) 
            fread(buff,1,DIM,stdin),poz=0;
    
	while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar = numar*10 + buff[poz] - '0';
        if (++poz == DIM) 
            fread(buff,1,DIM,stdin),poz=0;               
    }     
     
}

inline int max(int A, int B)
{
	if (A > B)
		return A;
	return B;
}

void relax(int nod)
{
	vector <pair <int, int> > :: iterator it;
	
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (max(sol[nod], it -> second) < sol[it -> first])
		{
			sol[it -> first] = max(sol[nod], it -> second);
			dmin[max(sol[nod], it -> second)].push_back(it -> first);
		}
}

int main()
{
	int i, j, N, M, X, Y, maxC = 0;
	
	freopen("pscnv.in", "r", stdin);
	freopen("pscnv.out", "w", stdout);
	
	read(N); read(M); read(X); read(Y);
	for (i = 1; i <= M; i ++)
	{
		int x0, y0, c;
		
		read(x0); read(y0); read(c);
		G[x0].push_back(make_pair(y0, c));
		if (c > maxC)
			maxC = c;
	}
	
	vector <int> :: iterator it;
	
	for (i = 1; i <= N; i ++)
		sol[i] = 1 << 30;
	sol[X] = 0; relax(X);
	
	for (i = 1; i <= maxC; i ++)
		for (j = 0; j < dmin[i].size(); j ++)
		{
			if (dmin[i][j] == Y)
			{
				printf("%d", sol[Y]);
				return 0;
			}
			if (sol[dmin[i][j]] == i)
				relax(dmin[i][j]);
		}
	
	return 0;
}
