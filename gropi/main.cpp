#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int S[100100], T[100100], E[100100], vis[100100], stack[100100];

int N, K, supply;
struct vertex
{
	int y, T, minT;
};

vertex make(int X, int Y, int Z)
{
	vertex aux; 
	aux.y = X; aux.T = Y; aux.minT = Z;
	return aux;
}

vector <vertex> G[100100];
int maxT;

void DFS1(int nod)
{
	vis[nod] = 1;
	
	vector <vertex> :: iterator it;
	for (it = G[nod].begin(); it != G[nod].end(); it ++)
		if (vis[it -> y] == 0)
		{
			T[it -> y] = it -> T;
			E[it -> y] = it -> T - it -> minT;
			DFS1(it -> y);
		}
}

bool isSolution;

void DFS2(int nod)
{
	vector <vertex> :: iterator it;
	
	vis[nod] = 1;
	stack[++ stack[0]] = nod;
	
	if (isSolution == false)
		return ;
	
	bool hasSon = false;
	for (it = G[nod].begin(); it != G[nod].end() && isSolution; it ++)
		if (vis[it -> y] == 0)
		{
			hasSon = true;
			S[it -> y] = S[nod] + T[it -> y];
			DFS2(it -> y);
		}
	
	if (hasSon == false && S[nod] > maxT)
	{
		int i;
		
		if (supply < S[nod] - maxT)
		{
			isSolution = false;
			return ;
		}
		supply = supply - S[nod] + maxT;
		
		int diff = S[nod] - maxT;
		for (i = 2; i <= stack[0]; i ++)
		{
			if (diff == 0)
				break;
			if (E[stack[i]] <= diff)
			{
				T[stack[i]] = T[stack[i]] - E[stack[i]];
				diff = diff - E[stack[i]];
				E[stack[i]] = 0;
			}
			else
			{
				T[stack[i]] = T[stack[i]] - diff;
				E[stack[i]] = E[stack[i]] - diff;
				diff = 0;
			}
		}
		
		if (diff)
		{
			isSolution = false;
			return ;
		}
		
		for (i = 2; i <= stack[0]; i ++)
			S[stack[i]] = S[stack[i - 1]] + T[stack[i]];
	}
	
	stack[0] --;
}

int main()
{
	int i, x0, y0, t0, tmin;
	
	freopen("gropi.in", "r", stdin);
	freopen("gropi.out", "w", stdout);
		
	scanf("%d%d", &N, &K);
	for (i = 1; i < N; i ++)
	{
		scanf("%d%d%d%d", &x0, &y0, &t0, &tmin);
		G[x0].push_back(make(y0, t0, tmin));
		G[y0].push_back(make(x0, t0, tmin));
	}
	
	int st = 1, dr = 10000000, med, sol;
	
	while (st <= dr)
	{
		med = (st + dr) / 2;
		for (i = 1; i <= N; i ++)
			vis[i] = 0;
		DFS1(1);

		stack[0] = 0;
		for (i = 1; i <= N; i ++)
			vis[i] = 0;
		isSolution = true;
		supply = K;
		maxT = med;
		DFS2(1);
		
		if (isSolution)
			dr = med - 1, sol = med;
		else
			st = med + 1;
	}
	
	printf("%d", sol);
	return 0;
}
