#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
char s[105][105],sir[105];
int i,v[105];
 
int invers ( int x ) {
        int inv=0;
        while ( x ) {
                inv=inv*10+x%10;
                x=x/10;
        }
        return inv;
}
       
 
void transformare_de_boss () {
        int n=strlen(s[i]),j;
        for(j=0;j<n;j++)
                v[i]=v[i]*10+s[i][j]-'0';
        v[i]=invers(v[i]);     
}      
 
int main(){
       
        freopen("astre.in", "r" , stdin);
        freopen("astre.out" , "w" , stdout );
       
        int n=0;
       
        while ( gets (sir ) ){
                strcpy(s[n++], sir );
        }
 
        for(i=0;i<n;i++)
                transformare_de_boss();
       
        for(i=0;i<n;i++)
                printf("%d " , v[i]);
       
        return 0;
}
