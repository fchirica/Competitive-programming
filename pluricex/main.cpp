#include<stdio.h>
#include<string.h>
int n,k,d,x[25][15],f[25],st[25];
int M[25];

void ver(int mask)
{
if (mask != ((1 << d) - 1))
    return ;
for(int i=1;i<=k;i++)
    printf("%d ",st[i]);
  printf("\n");

}
void combina(int niv, int mask)
{
int i;
for(i=st[niv-1]+1;i<=n-k+niv;i++)
  {
  st[niv]=i;
  if(niv==k)
    ver(mask | M[i]);
  else
    combina(niv+1, mask | M[i]);
  }
}
int main()
{
int i,j;
freopen("pluricex.in","r",stdin);
freopen("pluricex.out","w",stdout);
scanf("%d%d%d",&n,&k,&d);
for(i=1;i<=n;i++)
  {
  scanf("%d",&x[i][1]);
  for(j=1;j<=x[i][1];j++) {
    scanf("%d",&x[i][j+1]);
    M[i] |= (1 << (x[i][j + 1] - 1));
  }
  }
combina(1, 0);
return 0;
}

