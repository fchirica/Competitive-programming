#include<stdio.h>
long max;
long long pw3[60], pw5[60];

long long get_number(long x,int elf)
{
long long rasp=0,i;
long long pow;
for(i=0;(1 << i) <= x;i++)
  {
  pow = (elf == 3) ? pw3[i] : pw5[i];
  if((1<<i)&x)
    rasp=rasp+pow;
  }
return rasp;
}
int main()
{
long n,i,elfa,elfb;
long long x1,x2;
freopen("puteri35.in","r",stdin);
freopen("puteri35.out","w",stdout);
scanf("%ld",&n);
elfa=elfb=1;
pw3[0] = pw5[0] = 1;
for (int i = 1; i < 60; ++i) {
    pw3[i] = pw3[i - 1] * 3;
    pw5[i] = pw5[i - 1] * 5;
}
bool cache1 = 0, cache2 = 0;
for(i=1;i<=n+n;i++)
{
//intercalare
if (!cache1)
    x1=get_number(elfa,3), cache1 = 1;
if (!cache2)
    x2=get_number(elfb,5), cache2 = 1;
if(elfa<=n && elfb<=n)
 if(x1>x2)
  {elfb++; cache2 = 0; printf("%lld",x2);}
 else
  {elfa++; cache1 = 0; printf("%lld",x1);}
else
if(elfa>n)
 {elfb++; cache2 = 0; printf("%lld",x2);}
else
 {elfa++; cache1 = 0; printf("%lld",x1);}
printf("\n");
}
return 0;
}
