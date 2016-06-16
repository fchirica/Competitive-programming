#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

using namespace std;

class LCMSet {
public:
	string equal(vector <int>, vector <int>);
};

int x[55], y[55];
int pp[55], qq[55];

void desc(int xx) {
//	cerr << xx << "\n";
	pp[0] = qq[0] = 0;
	for (int d = 2; d * d <= xx; ++d) {
		int pw = 0;
		while (xx % d == 0) {
			xx /= d;
			++pw;
		}
		if (pw)
			pp[++pp[0]] = d, qq[++qq[0]] = pw;
	}
	if (xx > 1)
		pp[++pp[0]] = xx, qq[++qq[0]] = 1;
//	for (int i = 1; i <= pp[0]; ++i)
//		cerr << pp[i] << " " << qq[i] << "\n";
}

bool cannot(int val, int a[], int N) {
	map <int, int> M1, M2;
	desc(val);
	for (int i = 1; i <= pp[0]; ++i)
		M1[pp[i]] = qq[i];
	for (int i = 1; i <= N; ++i) {
		desc(a[i]);
		bool good = true;
		for (int i = 1; i <= pp[0]; ++i)
			if (qq[i] > M1[pp[i]])
				good = false;
		if (good) {
			//cerr << a[i] << " ";
			for (int i = 1; i <= pp[0]; ++i)
				chmax(M2[pp[i]], qq[i]);
			}
	}
	map <int, int> :: iterator it;
	for (it = M1.begin(); it != M1.end(); ++it)
		if (it -> second != M2[it -> first])
			return 1;
	return 0;
}

string LCMSet::equal(vector <int> A, vector <int> B) {
	for (int i = 0; i < A.size(); ++i)
		x[i + 1] = A[i];
	for (int i = 0; i < B.size(); ++i)
		y[i + 1] = B[i];
	int n = A.size(), m = B.size();

	for (int i = 1; i <= n; ++i)
		if (cannot(x[i], y, m)) {
			cerr << "1" << " " << x[i] << "\n";
			return "Not equal";
		}
	return "Equal";
}


double test0() {
	int t0[] = {2,3,4,12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Equal";
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
	int t0[] = {4,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6,36};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Not equal";
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
	int t0[] = {2,3,5,7,14,105};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,5,6,7,30,35};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Equal";
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
	int t0[] = {2,3,5,7,14,105};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,5,6,7,30,36};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Not equal";
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
double test4() {
	int t0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Equal";
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
double test5() {
	int t0[] = {999999999,1953125,512,1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {999999999,1953125,512};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Equal";
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
double test6() {
	int t0[] = {999999998,999999999,1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {999999999,1000000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	LCMSet * obj = new LCMSet();
	clock_t start = clock();
	string my_answer = obj->equal(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Not equal";
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

	time = test5();
	if (time < 0)
		errors = true;

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
