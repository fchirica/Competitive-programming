#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n,m,q;
#define maxn 805
#define lsb(x) (x & (-x))
int mat[maxn][maxn];
int AIB[maxn*maxn];
 
int cr;
int rem;
 
void AIB_update(int poz,const int &del)
{
    for(;poz<=cr;poz += lsb(poz))
        AIB[poz] += del;
}
 
int AIB_query(int poz)
{
    int ret = 0;
    for(;poz;poz -= lsb(poz))
        ret += AIB[poz];
    return ret;
}
 
int bs(int val)
{
    int i,step;
    for(step=1;step<cr;step<<=1);
    for(i=cr;step;step>>=1)
        if(i - step >= 1 && AIB_query(i-step) >= val)
            i -= step;
    return i;
}
 
struct data
{
    short x,y;
    int val;
    void init(const short &i,const short &j,const int &wat)
    {
        x = i;
        y = j;
        val = wat;
    }
}v[maxn*maxn];
 
 
struct comp
{
    inline bool operator () (const data &a,const data &b)const
    {
        return a.val < b.val;
    }
};
 
 
void init()
{
    freopen("amedie.in","r",stdin);
    freopen("amedie.out","w",stdout);
 
    scanf("%d %d %d\n",&n,&m,&q);
    rem = n*m;
    int i,j;
 
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            scanf("%d",&mat[i][j]);
            v[++cr].init(i,j,mat[i][j]);
        }
 
    sort(v+1,v+cr+1,comp());
 
    for(i=1;i<=cr;++i)
    {
        mat[v[i].x][v[i].y] = i;
        AIB_update(i,1);
    }
 
}
 
void del_lin(int line)
{
    int i;
    for(i=1;i<=m;++i)
    {
        if(mat[line][i])
        {
            AIB_update(mat[line][i],-1);
            mat[line][i]=0;
            --rem;
        }
    }
}
 
void del_col(int col)
{
    int i;
    for(i=1;i<=n;++i)
    {
        if(mat[i][col])
        {
            AIB_update(mat[i][col],-1);
            --rem;
            mat[i][col]=0;
        }
    }
}
 
int getQ()
{
    int ret = 0,sz;
    if(rem&1)
    {
        sz = (rem+1)>>1;
        ret = bs(sz);
        return v[ret].val;
    }
    else
    {
        sz = rem/2;
        ret = bs(sz);
        ++sz;
        int aux;
        aux = bs(sz);
        return min(v[ret].val,v[aux].val);
 
    }
}
 
void solve()
{
    char x;
    int wat;
    while(q--)
    {
        scanf("\n%c",&x);
 
        if(x == 'Q')
            printf("%d\n",getQ());
 
        else if(x == 'L')
        {
            scanf("%d",&wat);
            del_lin(wat);
        }
 
        else
        {
            scanf("%d",&wat);
            del_col(wat);
        }
    }
}
 
int main()
{
    init();
    solve();
    return 0;
}
