#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int myPow(int A, int B) {
    int res = 1;
    for (int i = 1; i <= B; ++i)
        res = res * A;
    return res;
}

int exp(int s,int x){ int n=0; while(s>=pow(x,n))n++;
int pizda = (int) myPow(x,(n-1));
return pizda;

}
int main()
{
    int s,x; cin>>s>>x;
    while(s){
        cout<<s/exp(s,x)<<"bacnote cu valoarea"<<exp(s,x)<<endl;
        s=s%exp(s,x);

    }
    return 0;
}
