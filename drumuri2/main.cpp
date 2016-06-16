//nu dati vina pe mine... Alex Valeanu m-a invatat ca a da copy paste e o idee buna :)
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<set>
#include<stack>
#define FIT(a,b) for(vector<int>::iterator a=b.begin();a!=b.end();a++)
#define ROF(a,b,c) for(int a=b;a>=c;--a)
#include<vector>
#define pii pair<int,int>
#include<algorithm>
#define FOR(a,b,c) for(int a=b;a<=c;++a)
#include<cstring>
#include<bitset>
#include<cmath>
#include<iomanip>
#include<queue>
#define deb printf("OK!\n");
#define f cin
#define g cout
#define mp make_pair
#define pb push_back
#define fi first
#define N 110
#define mod 1000000007
#define se second
#define ll long long
#define infile "mst.in"
#define outfile "mst.out"
#define eps 1.e0
using namespace std;
//int dx[]={0,0,0,1,-1};
//int dy[]={0,1,-1,0,0};
ifstream f(infile);
ofstream g(outfile);

struct edg
{
    double cost,a,b,c;
    int x,y;
};
edg edge[N],kkt[N];
struct cmp{bool operator() (edg i,edg j) const {return i.cost<j.cost; } };
pair<int,int> capm[N],cs[N];
int T[N],R[N],n,m,x[N],y[N];
double A,B,C,maxt,mint,timp,valo,solt,solv,a[N],b[N],c[N];

int find(int x)
{
    int aux=x;
    while(x!=T[x])
    x=T[x];
    int tata=x;
    x=aux;
    while(x!=tata)
    {
        aux=T[x];
        T[x]=tata;
        x=aux;
    }
    return tata;
}
void unite(int x,int y)
{
    if(R[x]<R[y])
        swap(x,y);
    if(R[x]==R[y])
        ++R[x];
    T[y]=x;
}
void apm(double t)
{
    FOR(i,1,m)
    {
        edge[i]=kkt[i];
        edge[i].cost=kkt[i].a*t*t+kkt[i].b*t+kkt[i].c;
    }

    sort(edge+1,edge+m+1,cmp());

    FOR(i,1,n)
    {
        R[i]=0;
        T[i]=i;
    }

    A=B=C=0;
    int te=-1;
    FOR(i,1,m)
    {
        int t1=find(edge[i].x);
        int t2=find(edge[i].y);
        if(t1!=t2)
        {
            unite(t1,t2);
            cs[++te]=mp(edge[i].x,edge[i].y);
            A+=edge[i].a;
            B+=edge[i].b;
            C+=edge[i].c;
        }
    }
    sort(cs,cs+n-1);
}
void updt()
{
    timp=-B/(2*A);
    valo=-(B*B-4*A*C)/(4*A);

    if(valo<solv)
    {
        solv=valo;
        solt=timp;
    }
}
void updapm()
{
    FOR(i,0,n-2)
    capm[i].fi=cs[i].fi,capm[i].se=cs[i].se;
}
int check()
{
    FOR(i,0,n-2)
    if(capm[i]!=cs[i])
        return 0;
    return 1;
}
void solvest()
{
    double st=0,sol=-1;
    while(sol!=0)
    {
        sol=0;
        double dr=maxt;
        while(abs(st-dr)>=eps)
        {

            double mij=(st+dr)/2;
            apm(mij);
            if(check())
                st=mij+eps;
            else
            {
                sol=mij;
                dr=mij-eps;
            }
        }
        st=sol;
        apm(st);
        updt();
        updapm();
    }
}
void solvedr()
{
    double dr=0,sol=1;
    while(sol)
    {
        sol=0;
        double st=mint;
        while(abs(st-dr)>=eps)
        {
            double mij=(st+dr)/2;
            apm(mij);
            if(check())
                dr=mij-eps;
            else
            {
                sol=mij;
                st=mij+eps;
            }
        }
        dr=sol;
        apm(dr);
        updt();
        updapm();
    }
}
int main ()
{
    f>>n>>m;
    solv=1<<30;
    FOR(i,1,m)
    {
        f>>kkt[i].x>>kkt[i].y>>kkt[i].a>>kkt[i].b>>kkt[i].c;
        kkt[i].x++;
        kkt[i].y++;
    }
    maxt=(1.e4)*4;
    mint=(-1.e4)*4;

    apm(0);
    updt();
    updapm();

    solvest();

    apm(0);
    updt();
    updapm();

    solvedr();

    g<<fixed<<setprecision(9)<<solt<<" "<<solv;
    return 0;
}

//Look at me! Look at me! The monster inside me has grown this big!
