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

class RangeFixer {
public:
	vector <int> closestValue(int, int, vector <int>);
};

int ret; 
int goLow(int bit, int lim, int val)
{
	ret = 0;
	if (bit == -1)
		return 0;
	int i, j, minB = 1 << 30;
	
	for (i = bit; i >= -1; i --)
	{
		int now;
		if (i != -1) 
			now = lim & (1 << i);
		else
			now = 0;
		if (now == 0)
		{
			for (j = bit; j > i; j --)
			{
				int bit1 = lim & (1 << j);
				if (bit1)
					bit1 = 1;
				int bit2 = val & (1 << j);
				if (bit2)
					bit2 = 1;
				if (bit1 != bit2)
					now ++;
			}
			if (i > 0 && (val & (1 << i)) == 0)		
				now ++; 
			if (now < minB)
			{
				minB = now; ret = 0;
				for (j = bit; j >= 0; j --)
				{
					if (j == i)
						ret = ret | (1 << j);
					int bit1 = lim & (1 << j);
					if (j > i)
						if (bit1)
							ret = ret | (1 << j);
					bit1 = val & (1 << j);
					if (j < i)
						if (bit1)
							ret = ret | (1 << j);
				}
			}
		}		
	}
	
	return minB;
}

int goHigh(int bit, int lim, int val)
{
	ret = 0;
	if (bit == -1)
		return 0;
	int i, j, minB = 1 << 30;
	
	for (i = bit; i >= -1; i --)
	{
		int now;
		if (i != -1) 
			now = lim & (1 << i);
		else
			now = 1;
		if (now)
		{
			for (j = bit; j > i; j --)
			{
				int bit1 = lim & (1 << j);
				if (bit1)
					bit1 = 1;
				int bit2 = val & (1 << j);
				if (bit2)
					bit2 = 1;
				if (bit1 != bit2)
					now ++;
			}
			if (i > 0 && (val & (1 << i)))		
				now ++; 
			if (now < minB)
			{
				minB = now; ret = 0;
				for (j = bit; j >= 0; j --)
				{
					if (j == i)
						continue;
					int bit1 = lim & (1 << j);
					if (j > i)
						if (bit1)
							ret = ret | (1 << j);
					bit1 = val & (1 << j);
					if (j < i)
						if (bit1)
							ret = ret | (1 << j);
				}
			}
		}		
	}
	
	return minB;
}

vector <int> RangeFixer::closestValue(int low, int high, vector <int> values) {
	int i, j;
	vector <int> sol;
	
	for (i = 0; i < values.size(); i ++)
		for (j = 30; j >= 0; j --)
		{
			int bit1 = low & (1 << j);
			int bit2 = high & (1 << j);
			int bit3 = values[i] & (1 << j);
			if (bit1)
				bit1 = 1;
			if (bit2)
				bit2 = 1;
			if (bit3)
				bit3 = 1;
			if (bit1 != bit2)
			{
				int val1 = goLow(j - 1, low, values[i]) + (bit3 ^ 0);
				int ret1 = ret;			
				int val2 = goHigh(j - 1, high, values[i]) + (bit3 ^ 1);
				if (val1 <= val2)
					sol[i] = sol[i] | ret1;
				else
					sol[i] = sol[i] | ret;
			}
			else
				if (bit1)
					sol[i] = sol[i] | (1 << j); 
		}
		
		return sol;
}


//Powered by [KawigiEdit] 2.0!