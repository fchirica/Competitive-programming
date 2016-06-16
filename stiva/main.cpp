#include<cstdio>
int k,p;
void caz_particular();
int main()
{
	//freopen("pitagora.in","r",stdin);
	//freopen("pitagora.out","w",stdout);
	scanf("%d",&k);if(k<7){caz_particular();return 0;}
	p=(k-2)/2;
	printf("%d\n",5*p+1);
	k&1?printf("4\n1 %d\n1 %d\n",3*p,4*p):printf("3\n1 %d\n",5*p);
	printf("%d 3\n%d 1\n",p,p+1);
	return 0;
}
void caz_particular()
{
	if(k==1){printf("1\n1\n1 1\n");return;}
	if(k==2){printf("5\n2\n1 3\n1 4\n");return;}
	if(k==3){printf("7\n3\n1 6\n1 3\n1 2\n");return;}
	if(k==4){printf("4\n1\n4 2\n");return;}
	if(k==5){printf("5\n2\n1 3\n4 2");return;}
	if(k==6){printf("7\n3\n1 6\n1 3\n4 1\n");return;}
}

