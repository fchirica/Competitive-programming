#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <time.h>

using namespace std;

long long modulo(long long a,long long b,long long c){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; 
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int cmp(long long X, int Y, long long Z)
{
	long long now = 1, lastnow = 1;
	
	int i;
	for (i = 1; i <= Y; i ++)
	{
		now = now * X;
		if (now < lastnow || now > Z)
			return 1;
		lastnow = now;
	}
	if (now == Z)
		return 0;
	if (now < Z)
		return -1;
	return 1;
}

long long findRoot(int pw, long long x) //verific daca exista un numar X ^ pw = x
{
	long long st = 1, dr = x - 1;
	
	while (st <= dr)
	{
		long long med = (st + dr) / 2;
		
		if (cmp(med, pw, x) == 0)
			return med;
		if (cmp(med, pw, x) == -1)
			st = med + 1;
		else
			dr = med - 1;
	}
	
	return -1;
}

int main()
{
	int T, pw;
	
	ifstream f("ubercool.in");
	ofstream g("ubercool.out");
	
	f >> T;
	srand(time(0));
	
	int test;
	for (test = 1; test <= T; test ++)
	{
		long long x;
		f >> x;
		
		bool isSol = false;
		
		for (pw = 2; pw <= 70; pw ++)
		{
			long long root = findRoot(pw, x);
			if (root == -1)
				continue;
			if (Miller(root, 100))
			{
				isSol = true;
				break;
			}
		}
		
		if (isSol)
			g << "DA\n";
		else
			g << "NU\n";
	}
	
	return 0;
}
