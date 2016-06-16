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
#include <string.h>

using namespace std;

class TheNumberGame {
public:
	string determineOutcome(int, int);
};

int dp[2][2][15][15][15][15][2];
int AA[15], BB[15];

const int INF = (1 << 28);

void rev(int x[], int st, int dr) {
	while (st <= dr) {
		int tmp = x[st];
		x[st] = x[dr];
		x[dr] = tmp;
		++st; --dr;
	}
}

void make(int number, int x[]) {
	x[0] = 0;
	while (number) {
		x[++x[0]] = number % 10;
		number = number / 10;
	}
	rev(x, 1, x[0]);
}

void chmin(int &A, int B) {
	if (A > B)
		A = B;
}

void chmax(int &A, int B) {
	if (A < B)
		A = B;
}	

//Petr coded this in 270.00 points. I'm really supposed to concure with such geniouses? 

int go(int ord1, int ord2, int st1, int dr1, int st2, int dr2, int turn) {
	if (dp[ord1][ord2][st1][dr1][st2][dr2][turn] != -1)
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn];
	//winning state for Manao?!
	bool wins = true;
	if (st1 == 1 && dr1 == 0 && st2 == 1 && dr2 == 0) { //both zero {
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn] = 0;
		cout << ord1 << " " << ord2 << " " << st1 << " " << dr1 << " " << st2 << " " << dr2 << " " << turn << "\n";	
	}
	if (st1 == dr1 + 1 && st2 == dr2 + 1) {
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn] = 0;
		cout << ord1 << " " << ord2 << " " << st1 << " " << dr1 << " " << st2 << " " << dr2 << " " << turn << "\n";
	}
	int i;
	if (dr1 - st1 != dr2 - st2)
		wins = false;
	if (wins) {
		int j = st2;
		if (ord1)
			rev(AA, st1, dr1);
		if (ord2)
			rev(BB, st2, dr2);
		for (i = st1; i <= dr1; i ++, j ++) 
			if (AA[i] != BB[j])
				wins = false;
		if (ord1)
			rev(AA, st1, dr1);
		if (ord2)
			rev(BB, st2, dr2);
	}
	if (wins) {
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn] = 0;
		cout << ord1 << " " << ord2 << " " << st1 << " " << dr1 << " " << st2 << " " << dr2 << " " << turn << "\n";
	}
	//just recurse
	if (turn == 0) {
		int ret = INF;
		chmin(ret, go(1 - ord1, ord2, st1, dr1, st2, dr2, 1 - turn));
		if (ord1 == 0 && dr1)
			chmin(ret, go(ord1, ord2, st1, dr1 - 1, st2, dr2, 1 - turn));
		if (ord1 && st1 <= dr1)
			chmin(ret, go(ord1, ord2, st1 + 1, dr1, st2, dr2, 1 - turn));
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn] = ret + 1;
	} else {
		int ret = -INF;
		chmax(ret, go(ord1, 1 - ord2, st1, dr1, st2, dr2, 1 - turn));
		if (ord2 == 0 && dr2)
			chmax(ret, go(ord1, ord2, st1, dr1, st2, dr2 - 1, 1 - turn));
		if (ord2 && st2 <= dr2)
			chmax(ret, go(ord1, ord2, st1, dr1, st2 + 1, dr2, 1 - turn));
		return dp[ord1][ord2][st1][dr1][st2][dr2][turn] = ret + 1;
	}
}

string TheNumberGame::determineOutcome(int A, int B) {
	make(A, AA); make(B, BB);
	memset(dp, -1, sizeof(dp));
	int moves =	go(0, 0, 1, AA[0], 1, BB[0], 0);
	cout << moves;
	if (moves <= 1000)
		return "Manao wins";
	return "Manao loses";
}


double test0() {
	int p0 = 45;
	int p1 = 4;
	TheNumberGame * obj = new TheNumberGame();
	clock_t start = clock();
	string my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Manao wins";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 45;
	int p1 = 5;
	TheNumberGame * obj = new TheNumberGame();
	clock_t start = clock();
	string my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Manao wins";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1;
	int p1 = 2;
	TheNumberGame * obj = new TheNumberGame();
	clock_t start = clock();
	string my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Manao loses";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 2356236;
	int p1 = 5666;
	TheNumberGame * obj = new TheNumberGame();
	clock_t start = clock();
	string my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Manao loses";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	/*time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	*/
	
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
