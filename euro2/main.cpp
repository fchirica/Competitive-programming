#include<stdio.h>
#define pb push_back
#include<vector>
#include<stack>
#define LMAX 169

using namespace std;

int x[LMAX][LMAX],f[LMAX*LMAX],dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int Q[LMAX*LMAX*2];
vector<int> w[LMAX*LMAX];


int main()
{
    int n,m,k,i,j,top,X,Y,newX,newY,val,p,u;
    vector<int> :: iterator it;

    freopen("castel.in","r",stdin);
    freopen("castel.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&x[i][j]);
    Q[1]=k; f[k]=1; p=u=1;
    while(p<=u)
    {
        top=Q[p];
        for(it=w[top].begin();it!=w[top].end();++it)
            if(!f[*it])
        {
            Q[++u]=*it;
            f[*it]=1;
        }
        X=top/m+1;
        if(top%m==0)
            X--;
        Y=top%m;
        if(top%m==0)
            Y=m;
        for(i=0;i<=3;i++)
        {
            newX=X+dx[i];
            newY=Y+dy[i];
            if(newX!=0 && newY!=0 && newX!=n+1 && newY!=m+1)
                if(!f[(newX-1)*m+newY])
                    if(f[x[newX][newY]])
                    {
                        val=(newX-1)*m+newY;
                        Q[++u]=val;
                        f[val]=1;
                    }
                else
                {
                    val=(newX-1)*m+newY;
                    w[x[newX][newY]].pb(val);
                }
        }
    p++;
    }
    int sol=0;
    for(i=1;i<=n*m;i++)
        if(f[i])
            ++sol;
    printf("%d",sol);
    return 0;
}
