//Algoritmul lui Kosajaru

#include <stdio.h>
#include <vector>
#include <algorithm>
#define maxEdges 50000 + 1

using namespace std;

vector<int> G[maxEdges], GT[maxEdges], SCC[maxEdges];
bool visited[maxEdges];
int blackEdges, numSCC, st[maxEdges];

void DF1(int node)
{
	vector <int> :: iterator it;
	
	visited[node] = 1;
	for (it = GT[node].begin(); it != GT[node].end(); it ++)
		if (!visited[*it])
			DF1(*it);
	st[++blackEdges] = node; 
}

void DF2(int node)
{
	vector <int> :: iterator it;
	
	visited[node] = 1;
	SCC[numSCC].push_back(node);
	
	for (it = G[node].begin(); it != G[node].end(); it ++)
		if (!visited[*it])
			DF2(*it);
}

inline bool comp(int A, int B)
{
	return SCC[A][0] < SCC[B][0];
}

int main()
{
	vector <int> :: iterator it;
	int i, x, y, N, M;
	
	freopen("retele.in", "r", stdin);
	freopen("retele.out", "w", stdout);
	
	//Citesc graful si construiesc graful transpus
	scanf("%d%d", &N, &M);
	for (i = 1; i <= M; i ++)
	{
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		GT[y].push_back(x);
	}
	
	//Calculez timpii de terminare pentru fiecare nod din graful transpus
	for (i = 1; i <= N; i ++)
		if (visited[i] == false)
			DF1(i);
	
	//Resetez vectorul de vizitare pe 0.
	for (i = 1; i <= N; i ++)
		visited[i] = 0;
	
	//Stiu sigur ca prima componenta tare conexa va fi cea cu cel mai mare timp de terminare. 
	//(nodul este "source" in graful transpus, asa ca devine "sink" in graful original). 
	//Dupa eliminarea componentei tare conexe, urmatoarea va fi exact cea cu cel mai mare timp terminal
	//care nu a fost deja eliminata. Deci e destul sa parcurg nodurile in ordinea descrescatoare timpilor terminali
	
	for (i = N; i >= 1; i --)
		if (!visited[st[i]])
		{
			++numSCC;
			DF2(st[i]);
		}
		
	//Afisez solutia
	printf("%d\n", numSCC);
	
	int index[maxEdges];
	for (i = 1; i <= numSCC; i ++)
	{
		index[i] = i;
		sort(SCC[i].begin(), SCC[i].end());
	}
	
	sort(index + 1, index + numSCC + 1, comp);
	for (i = 1; i <= numSCC; i ++, printf("\n"))
	{
		printf("%d ", SCC[index[i]].size());
		for (it = SCC[index[i]].begin(); it != SCC[index[i]].end(); it ++)
			printf("%d ", *it);
	}
	
	return 0;
}
