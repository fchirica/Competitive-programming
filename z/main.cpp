#include<stdio.h>
int f(int r,int c)
{
    return r+c?c&1|r*2&2|4*f(r/2,c/2):0;
}
int main()
{
	int N,K,x,y;
	freopen("z.in","r", stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d",&N,&K);
	while(K--)
	{
		scanf("%d%d",&x,&y);x--;y--;
		printf("%d\n",f(x,y)+1);
	}
	return 0;
}
