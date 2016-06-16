#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class ColorfulChocolates {
public:
	int maximumSpread(string, int);
};

int ColorfulChocolates::maximumSpread(string chocolates, int maxSwaps) {
	int i, N = chocolates.size(), usedSwaps, left, right, bestLeft, bestRight, j, sol = -10000000, idleft, idright;
	bool used[100], canSupply;
	
	for (i = 0; i < N; i ++)
	{
		memset(used, 0, sizeof(used));
		left = right = i; 
		usedSwaps = 0;
		
		while (usedSwaps <= maxSwaps)
		{
			bestLeft = bestRight = 10000000;
			for (j = left - 1; j >= 0; j --)
				if (chocolates[j] == chocolates[i] && !used[j])
				{
					bestLeft = left - j - 1;
					idleft = j;
					break;
				}
			for (j = right + 1; j < N; j ++)
				if (chocolates[j] == chocolates[i] && !used[j])
				{
					bestRight = j - right - 1;
					idright = j;
					break;
				}
		
			if (bestLeft == bestRight && bestLeft == 10000000)
				break;
			canSupply = 0;
			if (bestLeft < bestRight)
			{
				if (bestLeft + usedSwaps <= maxSwaps)
				{
					used[idleft] = 1;
					left --;
					usedSwaps += bestLeft;
					canSupply = 1;
				}
			}
			else
			{
				if (bestRight + usedSwaps <= maxSwaps)
				{
					used[idright] = 1;
					right ++;
					usedSwaps += bestRight;
					canSupply = 1;
				}
			}
			if (canSupply == 0)
				break;
		}
		
		if (right - left + 1 > sol)
			sol = right - left + 1;
	}
	
	return sol;
}


double test0() {
	string p0 = "ABCDCBC";
	int p1 = 1;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "ABCDCBC";
	int p1 = 2;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "ABBABABBA";
	int p1 = 3;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "ABBABABBA";
	int p1 = 4;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
	int p1 = 77;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!