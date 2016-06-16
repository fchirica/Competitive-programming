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

class MarblePositioning {
public:
	double totalWidth(vector <int>);
};

double MarblePositioning::totalWidth(vector <int> radius) {
	double best = 1 << 30;
	do {
		double cur;
		double x[10], R[10];
		x[0] = 0; R[0] = radius[0];

		int i, j;

		for (i = 1; i < radius.size(); ++i) {
			R[i] = radius[i]; x[i] = -1;
			for (j = 0; j < i; ++j) {
				double needX;
				needX = (R[i] + R[j]) * (R[i] + R[j]) - (R[i] - R[j]) * (R[i] - R[j]);
				needX = sqrt(needX);
				needX += x[j];

				if (needX - x[i] > 0.0000001)
					x[i] = needX;
			}

		}
		cur = x[radius.size() - 1] - x[0];

		if (radius[0] == 100 && radius[2] == 25 && radius[4] == 100)
			cerr << cur;

		if (cur - best < -0.00000001)
			best = cur;
	} while(next_permutation(radius.begin(), radius.end()));
	return best;
}


double test0() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.8284271247461903;
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
	int t0[] = {7,7,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 28.0;
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
	int t0[] = {10, 20, 30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 62.92528739883945;
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
	int t0[] = {100, 100,11,11,25};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 200.0;
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
double test4() {
	int t0[] = {1,999950884,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 63246.0;
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



	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
