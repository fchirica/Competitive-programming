//-1 task not submitted

#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct contestant
{
	string name;
	int scores[7];
	int sure[6];
} x[100];

inline bool comp(contestant A, contestant B)
{
	if (A.scores[6] == B.scores[6])
		return A.name < B.name;
	return A.scores[6] > B.scores[6];
}

int maxScores[] = {0, 5, 5, 5, 10, 20};

int main()
{
	ifstream in("data.in");
	ofstream out("data.out");
	
	int i, n = 0, j;
	string now;
	
	while (in >> now)
	{
		x[++ n].name = now;
		for (i = 1; i <= 5; i ++)
		{
			in >> x[n].scores[i];
			if (x[n].scores[i] > 0)
				x[n].scores[6] += x[n].scores[i];
		}
		for (i = 1; i <= 5; i ++)
			in >> x[n].sure[i];
		for (i = 1; i <= 5; i ++)
			if (x[n].sure[i])
				if (x[n].scores[i] != maxScores[i])
					x[n].scores[6] --;
				else
					x[n].scores[6] ++;
	}
	
	sort(x + 1, x + n + 1, comp);

	out << "[TABLE][TR][TD][center]Position[/center][/TD][TD][center]Name[/center][/TD][TD][center]Points Q1[/center][/TD][TD][center]Points Q2[/center][/TD][TD][center]Points Q3[/center][/TD][TD][center]Points Q4[/center][/TD][TD][center]Points Q5[/center][/TD][TD][center]Total points[/center][/TD][/TR]\n";
	for (i = 1; i <= n; i ++)
	{
		out << "[TR][TD][center]" << i << "[/center][/td]";
		out << "[TD][center][b]" << x[i].name << "[/b][/center][/td]";
		for (j = 1; j <= 5; j ++)
		{
			if (x[i].scores[j] == -1)
				out << "[TD][center]N / A[/center][/td]";
			else
			if (x[i].sure[j] == 0)
				out << "[TD][center]" << x[i].scores[j] << "[/center][/td]";
			else
			if (x[i].sure[j])
			{
				if (x[i].scores[j] == maxScores[j])
					out << "[TD][center][color=blue][b]" << x[i].scores[j] << "[/b][/color][/center][/td]";
				else
					out << "[TD][center][color=red][b]" << x[i].scores[j] << "[/b][/color][/center][/td]";
			}
		}
		out << "[TD][center]" << x[i].scores[6] << "[/center][/td][/tr]\n";
	}
	
	out << "[/TABLE]";
	return 0;
}
