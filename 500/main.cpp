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

class TheFrog {
public:
	double getMinimum(int, vector <int>, vector <int>);
};

struct inter {
	int x, y;
} x[55];

bool valid(double val, int N, int D) {
	int i;
	
	if (val == 1)
		printf("");
	
	while (val < D) {
		for (i = 1; i <= N; i ++)
			if (x[i].x < val && val < x[i].y)
				return 0;
		val = val + D;
	}
	
	return 1;
}

double TheFrog::getMinimum(int D, vector <int> L, vector <int> R) {
	int N = L.size(), i; 
	
	for (i = 0; i < N; i ++)
		x[i + 1].x = L[i], x[i + 1].y = R[i];
	
	int j;
	double sol = 4000000;
	
	for (i = 1; i <= N; i ++)
		for (j = 1; j <= x[i].y; j ++) {
			double ret = (double)x[i].y / j;
			
			if (valid(ret, N, D))
				if (sol - ret >= 0.0000000001)
					sol = ret;
		}
		
	return sol;
}


double test0() {
	int p0 = 16;
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheFrog * obj = new TheFrog();
	clock_t start = clock();
	double my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 7.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 25;
	int t1[] = {11, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {21, 7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheFrog * obj = new TheFrog();
	clock_t start = clock();
	double my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 10.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 100;
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheFrog * obj = new TheFrog();
	clock_t start = clock();
	double my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 100.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 100;
	int t1[] = {0, 50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {50, 100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheFrog * obj = new TheFrog();
	clock_t start = clock();
	double my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 50.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 30000;
	int t1[] = {17, 25281, 5775, 2825, 14040};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {55, 26000, 5791, 3150, 14092};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TheFrog * obj = new TheFrog();
	clock_t start = clock();
	double my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 787.8787878787879;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
