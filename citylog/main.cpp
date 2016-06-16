#include <fstream>
#include <cassert>

using namespace std;

short smen[16][32100];
int TT[100100];

void get(int &X, int &how)
{
	int pw;
		
	for (pw = 0; (1LL << pw) <= how; pw ++)
		if (how & (1 << pw))
		{
			if (X > 32000)
				return ;
			X = smen[pw][X];
			how = how - (1 << pw);
		}
	
	return ;
}

void update(int A, int B)
{
	int pw;
	
	smen[0][A] = B;
	for (pw = 1; pw <= 15; pw ++)
	{
		B = smen[pw - 1][B];
		if (B == 0)
			return ;
		smen[pw][A] = B;
	}
}

int slow(int A, int B)
{
	while (B)
	{
		A = TT[A];
		B --;
		//if (A <= 32000)
		//	get(A, B);
		if (A == 0)
			return 0;
	}
	
	return A;
}

int main()
{
	int i, N, M;
	
	ifstream f("citylog.in");
	ofstream g("citylog.out");
	
	f >> N >> M;
	int current = 0;
	
	for (i = 1; i <= M; i ++)
	{
		int type, A, B;
		f >> type >> A >> B;
	
		A = A ^ current; B = B ^ current;
		if (type == 0)
		{
			TT[A] = B;
			//if (A <= 32000)
			//	update(A, B);
		}
		else
		{
			current = slow(A, B);
			g << current << "\n";
		}
	}
	
	return 0;
}
