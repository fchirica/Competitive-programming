#include<stdio.h>
int n,k,x[16100];
void read()
{
int i;
freopen("transport.in","r",stdin);
freopen("transport.out","w",stdout);
scanf("%d%d",&n,&k);
for(i=1;i<=n;i++)
  scanf("%d",&x[i]);
}
int okay(int t)
{
int i,j=0,s;
for(i=1;i<=k;i++)
  {
  s=0;
  while(s<=t && j<=n)
    {
    j++;
    s+=x[j];
    }
  j--;
  s-=x[j];
  }
return (j==n);
}
void solve()
{
int i,max,s; max=s=0;
for(i=1;i<=n;i++)
  {
  if(x[i]>max)
    max=x[i];
  s=s+x[i];
  }
int last=-1,st=max,dr=s,m;
while(st<=dr)
  {
  m=(st+dr)>>1;
  if(okay(m))
    {
    last=m;
    dr=m-1;
    }
  else
    st=m+1;
  }
printf("%d",last);
}

int main()
{
read();
solve();
return 0;
}
