#include<string.h>
#include<stdio.h>

char mat[104][104],viz[104],viz2[104],dom[104][104];
int n;
void dfs(int u)
{
        int i;
        viz[u]=1;
        for(i=1;i<=n;i++)
                if(mat[u][i]==1&&viz[i]==0)
                                        dfs(i);
}
void dfs2(int u, int anas)
{
        int i;
        viz2[u]=1;
        for(i=1;i<=n;i++)
                if(mat[u][i]==1&&viz2[i]==0 && i != anas)
                                dfs2(i, anas);
}

int main()
{
        //freopen("uva.in","r",stdin);
        //freopen("uva.out","w",stdout);
        int t,i,j,num=1,a[104],b[104],i1;
        scanf("%d",&t);
        while(num<=t)
        {
                scanf("%d",&n);
                for(i=1;i<=n;i++)
                        {
                        scanf("\n");
                        for(j=1;j<=n;j++)
                                scanf("%d",&mat[i][j]);
                        }
                dfs(1);
                for(i=1;i<=n;i++)
                        if(viz[i]==1)
                                dom[1][i]=1;   
                for(i=2;i<=n;i++)
                {
                        //for(j=1;j<=n;j++)
                        //         {a[j]=mat[i][j];b[j]=mat[j][i];mat[i][j]=mat[j][i]=0;}
                        dfs2(1, i);
                        for(j=1;j<=n;j++)
                                if(viz[j]==1&&viz2[j]==0)
                                        dom[i][j]=1;
                       // for(j=1;j<=n;j++)
                       //         {mat[i][j]=a[j];mat[j][i]=b[j];}
                       // memset(a,0,sizeof(a));
                        //memset(b,0,sizeof(b));
                        memset(viz2,0,sizeof(viz));
                       
                }
                printf("Case %d:\n",num);
               
                for(i1=1;i1<=n;i1++)
                {
					 printf("+");
					for(i=1;i<=n*2-1;i++)
                        printf("-");
					printf("+\n");
                        printf("|");
                        for(j=1;j<=n;j++)
                        {
                                if(dom[i1][j]==1)
                                        printf("Y|");
                                else
                                        printf("N|");
                        }
                        printf("\n");
                }
                printf("+");
                for(i=1;i<=n*2-1;i++)
                        printf("-");
                printf("+");
                printf("\n");
                num++;
                memset(mat,0,sizeof(mat));
                memset(viz,0,sizeof(viz));
                memset(viz2,0,sizeof(viz2));
                memset(dom,0,sizeof(dom));
        }
        return 0;
}
