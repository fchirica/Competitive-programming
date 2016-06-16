#include<fstream>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1010
using namespace std;
ifstream f("fof.in");
ofstream g("fof.out");
vector<int> v[N];
struct el{int nb,id;} q[N];
struct cmp {
inline bool operator () (el a,el b){ if(a.nb!=b.nb) return a.nb>b.nb; return a.id<b.id;}
};
int j,n,m,viz[N],s[N],t,k,i,x,y,nr[N];
int main ()
{
    f>>n>>m;
    for(i=1;i<=m;++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++j)
        {
            viz[v[i][j]]=1;
            s[++t]=v[i][j];
        }
        viz[i]=1;
        m=t;
        for(j=1;j<=t;++j)
        {
            x=s[j];
            for(k=0;k<v[x].size();++k)
            if(!viz[v[x][k]])
            nr[v[x][k]]++;
        }
        t=0;
        for(j=1;j<=n;++j)
        if(nr[j])
        {
        q[++t].nb=nr[j];
        q[t].id=j;
        }
        sort(q+1,q+t+1,cmp());
        for(j=1;j<=t;++j)
        g<<q[j].id<<" ";
        g<<"\n";


        for(j=1;j<=m;++j)
        {
            x=s[j];
            for(k=0;k<v[x].size();++k)
            if(!viz[v[x][k]])
            nr[v[x][k]]--;
        }
        for(j=0;j<v[i].size();++j)
        {
            viz[v[i][j]]=0;
        }
        viz[i]=0;
    }
    return 0;
}
