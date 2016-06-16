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

using namespace std;

class LargestGap {
public:
	int getLargest(vector <string>);
};

string x;
vector <int> sol, cur;
bool used[3000];

void setUsed() {
	int i;
	for (i = 0; i < x.size(); i ++)
		used[i] = 0;
}

void fillHole(int idx, int dir) {
	if (idx == 0)	
		fillHole(x.size() - 1, -1);
	int i;
	for (i = idx; i >= 0 && i < x.size(); i += dir) {
		if (x[i] == '.')
			break;
		used[i] = 1;
	}
}

void computeCur() {
	cur.clear();
	int i, gap = 0;
	bool firstCall = true;
	for (i = 0; i < x.size(); i ++)
		if (x[i] == '.' && !used[i]) {
			gap = 0;
			if (firstCall) {
				int pos = i - 1;
				while (1) {
					if (x[pos] == 'X' && !used[pos])
						break;
					if (pos == -1) {
						pos = x.size() - 1;
						continue;
					}
					if (x[pos] == 'X') {
						--pos;
						continue;
					}
					used[pos] = 1;
					++gap; --pos; 
				}
				firstCall = false;
			}
			int pos; 
			for (pos = i; pos < x.size(); pos ++) {
				if (x[pos] == 'X' && !used[pos])
					break;
				if (x[pos] == 'X')
					continue;
				used[pos] = 1;
				++gap;
			}
			cur.push_back(gap);
		}
			
}

int LargestGap::getLargest(vector <string> board) {
	int i;
	for (i = 0; i < board.size(); i ++)
		x += board[i];
	
	int pos; 
	for (i = 0; i < x.size(); i ++)
		if (x[i] == 'X') {
			setUsed();
			fillHole(i, 1);
			computeCur();
			if (cur > sol)	
				sol = cur, pos = i;
		}
		
	return pos;
}


double test0() {
	string t0[] = {".....X.X......."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"XXXX","....","XXXX","....","XXXX","...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"XXX.........XX...........XX..X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"XXX","X.....","....XX..XXXXXX","X........X..",".XXX."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	LargestGap * obj = new LargestGap();
	clock_t start = clock();
	int my_answer = obj->getLargest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 32;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!