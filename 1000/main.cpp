#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define DN 100005
#define LL long long
using namespace std;

int n,m;
LL aib[DN];
vector<int> a,b;
vector<LL> dnr;

int lsb(int x) {
	return (x&(x-1))^x;
}

void ins(int p,LL vl) {
	for(;p<=n; p+=lsb(p)) aib[p]^=vl;
}

LL query(int p) {
	LL r=0;
	if (p == 0)
        return 0;
	for(;p;p-=lsb(p)) r^=aib[p];
	return r;
}

int main() {
    ifstream cin("pula.in");
    ofstream cout("pula.out");

	srand(time(NULL));
	cin>>n>>m;
	for(;m--;) {
		int op,x,y;
		cin>>op>>x;
		if(op==1) {
			cin>>y;
			a.push_back(x); b.push_back(y);
			LL ra=((rand()*1LL)<<32)+rand();
			dnr.push_back(ra);
			ins(x,ra); ins(y,ra);
		}else if(op==2) {
		    --x;
			ins(a[x],dnr[x]);
			ins(b[x],dnr[x]);
		}
		else {
			cin>>y;
			if((query(y)^query(x-1))==0) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}
