#include<stdio.h>
#include<algorithm>
#define LMAX 100100
#define max(a,b) (a>b ? a : b)

using namespace std;

struct pozdy
{
    int x,y;
} a[LMAX];

int c[LMAX];

inline bool cmp(pozdy x,pozdy y)
{
    return x.y<y.y;
}

int cauta(int st,int dr,int val)
{
    int m,last=-1;
    while(st<=dr)
    {
        m=(st+dr)/2;
        if(a[m].y<=val)
            last=m,st=m+1;
        else
            dr=m-1;
    }
return last;
}

int main()
{
    int i,n,poz;

    freopen("heavymetal.in","r",stdin);
    freopen("heavymetal.out","w",stdout);

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        poz=cauta(1,i-1,a[i].x);
        c[i]=c[i-1];
        if(poz==-1)
            c[i]=max(c[i],a[i].y-a[i].x);
        else
            c[i]=max(c[i],c[poz]+a[i].y-a[i].x);

    }
    printf("%d",c[n]);
}
