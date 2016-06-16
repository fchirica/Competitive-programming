#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MAX 90020

char text[MAX]; long long key[MAX]; int N, sa[MAX], rank[MAX], *lcp=(int*)key;
struct Cmp { bool operator()(int i, int j) const { return key[i]<key[j]; } };
void build() {
for (int i = 0; i < N; i++) { sa[i] = i; key[i] = text[i]; }
sort(sa, sa+N, Cmp());
for (int K = 1; ; K *= 2) {
for (int i = 0; i < N; i++)
rank[sa[i]] = i>0 && key[sa[i-1]]==key[sa[i]] ? rank[sa[i-1]] : i;
if (K >= N) break;
for (int i = 0; i < N; i++)
key[i] = rank[i] * (N+1LL) + (i+K < N ? rank[i+K]+1 : 0);
sort(sa, sa+N, Cmp());
}
for (int i = 0, k = 0; i < N; i++) {
if (k > 0) k--;
if (rank[i] == N-1) { lcp[N-1] = -1; k = 0; continue; }
int j = sa[rank[i]+1];
while (text[i+k] == text[j+k]) k++;
lcp[rank[i]] = k;
}
}

int dod[MAX];
ll sum[MAX];

int main()
{
    scanf("%s",text);
    int n=strlen(text);
    int q;CZ(q);
    N=n;
    build();
    FOR(i,n)
    {
        dod[i]=n-sa[i];
        if (i) dod[i]-=lcp[i-1];
        //DBG(dod[i]);
    }
    FOR(i,n)
    {
        sum[i+1]=sum[i]+dod[i];
    }
    while(q--)
    {
        int z;CZ(z);
        int lo=0,hi=n,mid;
        while(hi-lo>1)
        {
            mid=(hi+lo)/2;
            if (sum[mid]>=z) hi=mid;
            else lo=mid;
        }
        z-=sum[hi-1];
        hi--;
        int lc=(hi?lcp[hi-1]:0);
        FOR(j,z+lc) printf("%c",text[sa[hi]+j]);
        puts("");
    }


    return 0;
}

