#include <cstring>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int N, M;
vector<int> V[100002];
int level[100002], minL[100002];
bool S[100002], Saux[100002], Del[100002];
vector<vector<int> > R;
set<int> Sn;

void getR(int x, int notlevel)
{
	Sn.insert(x);
	R.back().push_back(x);
	for (vector<int>::iterator it = V[x].begin(); it != V[x].end(); ++it)
		if (Sn.find(*it) == Sn.end() && level[*it] != notlevel && !Del[*it])
			getR(*it, notlevel);
}
void Dfs(int x)
{
	S[x] = true;
	
	minL[x] = level[x];
	for (vector<int>::iterator it = V[x].begin(); it != V[x].end(); ++it)
		if (!S[*it])
		{
			level[*it] = level[x] + 1;
			Dfs(*it);
			minL[x] = min(minL[x], minL[*it]);
			
			if (Del[*it])
			{
				R.push_back(vector<int>());
				R.back().push_back(x);
				R.back().push_back(*it);
			}
		}
		else if (level[*it] != level[x] - 1)
			minL[x] = min(minL[x], level[*it]);
	
	if (minL[x] == level[x])
	{
		Del[x] = true;
		Sn.clear();
		
		R.push_back(vector<int>());
		getR(x, level[x] - 1);
		if (R.back().size() == 1)
			R.pop_back();
	}
}

int main()
{
	ifstream fin("biconex.in");
	ofstream fout("biconex.out");
	
	fin >> N >> M;
	for (int i = 1, nod1, nod2; i <= M; ++i)
	{
		fin >> nod1 >> nod2;
		V[nod1].push_back(nod2);
		V[nod2].push_back(nod1);
	}
	
	Dfs(1);
	
	fout << R.size() << '\n';
	for (int i = 0; i < R.size(); ++i)
	{
		for (vector<int>::iterator it = R[i].begin(); it != R[i].end(); ++it)
			fout << *it << ' ';
		fout << '\n';
	}
	
	fin.close();
	fout.close();
}
