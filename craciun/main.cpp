//Ma pregatesc pt lot :D

#include<stdio.h>
long a[2];
long ce_l(long st,long dr,long val)
{
long m;
while(st<=dr)
 {
 m=(st+dr)>>1;
 if(val<=a[m])
   dr=m-1;
 else
   st=m+1;
 }
return st;
}
long ce_r(long st,long dr,long val)
{
long m,last;
while(st<=dr)
 {
 m=(st+dr)>>1;
 if(val>=a[m])
  {
  last=m;
  st=m+1;
  }
 else
  dr=m-1;
 }
return last;
}
int main()
{
long pozdy,n,i,m,x,y;
freopen("cautbin.in","r",stdin);
freopen("cautbin.out","w",stdout);
scanf("%ld",&n);
for(i=1;i<=n;i++)
 scanf("%ld",&a[i]);
scanf("%ld",&m);
for(i=1;i<=m;i++)
 {
 scanf("%ld%ld",&x,&y);
 if(x==0)
  {
  pozdy=ce_r(1,n,y);
  if(a[pozdy]==y)
    printf("%ld",pozdy);
  else
    printf("-1");
  }
 if(x==1)
  {
  pozdy=ce_l(1,n,y);
  if(a[pozdy]==y)
   printf("%ld",ce_r(1,n,y));
  else
   printf("%ld",pozdy-1);
  }
 if(x==2)
  {
  pozdy=ce_l(1,n,y);
  printf("%ld",pozdy);
  }
 printf("\n");
 }
return 0;
}

