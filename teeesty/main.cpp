/*An AND-equation is an equation that looks like this:
X[0] AND X[1] AND ... AND X[N-1] = Y
Here X[i] and Y are non-negative integers and the bitwise
 AND operation is defined in the Notes.

In C++, C#, and Java the operator AND is denoted "&". 
So for example (P & Q & R) is the bitwise AND of numbers P, Q, and R. 
In VB the same operator is denoted "And".

You are given a vector <int> A that contains exactly N+1 elements. 
Your task is to construct an AND-equation using each element of A exactly once. (That is, N of them will be on the left hand side of the AND-equation and the remaining one will be on the right hand side.) If this is possible, return the value of Y in this AND-equation. If no AND-equation can be constructed, return -1. (It can be shown that for each A there is at most one possible value Y, so the return value is always defined correctly.)
	
	AND is a binary operation, performed on two numbers in binary notation. 
First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each position where both numbers have 1 in their binary representations, the result also has 1. It has 0 in all other positions.
-
For example 42 AND 7 is performed as follows. First, the numbers are converted to binary: 
42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 AND 000111 = 000010 (the result has ones only in the positions where both numbers have ones). Then the result can be converted back to decimal notation. In this case 000010 = 2, so 42 AND 7 = 2.
-
One of the ways to calculate the AND of more than 
two numbers X[0], X[1], ..., X[N-1] is "X[0] AND (X[1] AND (... AND X[N-1]))..))". 
Since the function is commutative and associative, you can also express it as "X[0] AND X[1] AND ... AND X[N-1]" and group the operands in any way you like.

{1, 3, 5}
Returns: 1
5 AND 3 = 1
1)

    
{31, 7}
Returns: -1
Clearly, no AND-equation is possible in this case.
2)

    
{31, 7, 7}
Returns: 7
7 AND 31 = 7

Note that duplicate elements are possible in the input. If an element appears several times in A, it must be used the same number of times in the equation.
3)

    
{1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,
 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1}
Returns: 0
Zeros are possible in the input.
4)

    
{191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
 191411,191411,191411}
Returns: 191411

5)

    
{1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211}
Returns: -1

6)

    
{2, 3, 7, 19}
Returns: -1 */

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

class ANDEquation {
public:
	int restoreY(vector <int>);
};

int ANDEquation::restoreY(vector <int> A) {
	int i, now, j;
	
	for (i = 0; i < A.size(); i ++)
	{
		now = -1000;
		for (j = 0; j < A.size(); j ++)
			if (i != j)
			{
				if (now == -1000)
					now = A[j];
				else
					now = now & A[j];
			}
		if (now == A[i])
			return A[i];
	}
	
	return -1;
}


double test0() {
	int t0[] = {1, 3, 5}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {31, 7}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	int t0[] = {31, 7, 7}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int t0[] = {1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,
 0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
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
double test4() {
	int t0[] = {191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
 191411,191411,191411};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 191411;
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
double test5() {
	int t0[] = {1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
double test6() {
	int t0[] = {2, 3, 7, 19};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ANDEquation * obj = new ANDEquation();
	clock_t start = clock();
	int my_answer = obj->restoreY(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
