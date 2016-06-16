#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 10005

	typedef struct { unsigned long s,f,a,b; } talent;
	talent T[maxn];
	
	long n,i;

long min ( unsigned long a, unsigned long b )
{
	if ( a>b )
		return b;
	return a;
}
	
bool numara ( unsigned long val )
{
	long i,rez=0,xp;
	for ( i=1; i<=n; i++ )
	{
		xp=min ( T[i].f, val );
		xp-=T[i].s;
		xp++;

		rez+=(long)(xp/(T[i].a+T[i].b))*T[i].a;
		rez+=min ( T[i].a, xp%(T[i].a+T[i].b) );

		rez%=2;
	}
	return rez;
}	
	
unsigned long solve () 
{
	unsigned long ind=0;
	for ( unsigned long i=(long long)(1<<31); i ; i>>=1 )
	{
		if ( !numara (ind+i) )
			ind+=i;
	}
	return ind+1;
}


int main()
{
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	scanf ("%d", &n);
	for ( i=1; i<=n; i++ )
		scanf ( "%d %d %d %d", &T[i].s, &T[i].f, &T[i].a, &T[i].b );
	
	if ( numara ( INF ) )
	{
		printf ( "%d", solve() );		
	}
	else{
		printf ("0");
	}
	return 0;
}