//Imi cer scuze pentru cuvintele urate din aceasta sursa. Daca citeste un copil mic si inocent asta il invit sa se holbeze la sursa altcuiva :o3

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int baza;

ifstream f("puteri2.in");
ofstream g("puteri2.out");

int pizda;

class huge
{
    public: int v[2100];
    int i,aux;
    huge()
    {
        for(i=0;i<=2000;i++)
            v[i]=0;
    }
    inline void operator = (huge a)
    {
        memcpy (v,a.v,sizeof (a.v));
    }
    inline void operator = (int a)
    {
        memset(v,0,sizeof(v));
        for ( ;a>0;a=a/10)
            v[++v[0]]=a%10;
    }
    inline huge operator + (huge &a) const
    {
        huge b;
        int i,t;
        t=0;
        for(i=1;i<=a.v[0]||i<=v[0]||t;i++,t=t/baza) {
            t=t+a.v[i]+v[i];
            b.v[i]=t%baza;
        }
        b.v[0]=i-1;
        return b;
    }
    inline huge operator - (int a)
    {
        huge b;
        int i,t;
        t=a;
        memcpy (b.v,v,sizeof (v));
        for (i=1;t;++i,t/=baza) {
            b.v[i]=b.v[i]-(t%baza);
            if(b.v[i]<0) {
                b.v[i+1]--;
                b.v[i]=b.v[i]+baza;
            }
        }
        for ( ;b.v[0]>1 && !b.v[b.v[0]]; b.v[0]--);
        return b;
    }
    inline huge operator * (huge &a) const
    {
        int i,j,t;
        huge c;
        t=0;
        c.v[0]=a.v[0]+v[0]-1;
        for(i=1;i<=a.v[0]+v[0];i++)
            c.v[i]=0;
        for(i=1;i<=a.v[0];i++)
            for(j=1;j<=v[0];j++)
                c.v[i+j-1]=c.v[i+j-1]+(1LL*a.v[i]*v[j]);
        for(i=1;i<=c.v[0];i++) {
            t=(c.v[i]+=t)/baza;
            c.v[i]%=baza;
        }
        if(t)
            c.v[++c.v[0]]=t;
        return c;
    }
    inline huge operator / (int b) const
    {
        huge a;
        memcpy (a.v, v, sizeof (v));
        int i,t;
        t=0;
        for (i=a.v[0]; i>0; --i, t%=b) {
            a.v[i]=(t=t*baza+a.v[i])/b;
        }
        for (; a.v[0]>1 and !a.v[a.v[0]]; --a.v[0]);
        return a;
    }
    inline bool operator < (huge &a)  const
    {
        int i;
        if(v[0]<a.v[0])
            return true;
        else if(a.v[0]<v[0])
            return false;
        for(i=v[0];i>=1;i--)
            if(v[i]<a.v[i])
                return true;
            else if(a.v[i]<v[i])
                return false;
        return false;
    }
    inline bool operator == (huge &a) const
    {
        int i;
        if(v[0]!=a.v[0])
            return false;
        for(i=1;i<=v[0];i++)
            if(v[i]!=a.v[i])
                return false;
        return true;
    }
    inline int numara() {
        int i, cnt = 0;
        for (i = 1; i <= v[0]; ++i) {
            int ret = v[i];
            do {
                ++cnt;
                ret = ret / 10;
            } while (ret);
        }
        return cnt;
    }
    inline int operator % (int b) const
    {
        int i, t = 0;
        for (i = v[0]; i > 0; i--)
              t = (t * 10 + v[i]) % b;
      return t;
    }
        friend ifstream& operator >> (ifstream &f, huge &A)
    {
        char Number[2001]; memset (Number, 0, sizeof (0));
        f >> Number; int L=strlen (Number);
        pizda = L;
        for (int i=L-1; i>=0; i-=4)
        {
            A.v[++A.v[0]]=Number[i]-'0';
            if (i>0) A.v[A.v[0]]+=((Number[i-1]-'0')*10);
            if (i>1) A.v[A.v[0]]+=((Number[i-2]-'0')*100);
            if (i>2) A.v[A.v[0]]+=((Number[i-3]-'0')*1000);
        }
        return f;
    }
    friend ofstream& operator << (ofstream &f, huge &A)
    {
        f<< A.v[A.v[0]];
        for (int i=A.v[0]-1; i>0; --i)
        {
            if (A.v[i]==0)
            {
                for (int X=1; X<baza; X*=10) f << "0";
                continue;
            }
            for (int X=A.v[i]*10; X<baza; X*=10) f << "0";
            f<< A.v[i];
        }
        return f;
    }
};
huge a,pp,mij,aux,d,x;
int i;
inline huge putere (huge A, int E)
{
    huge R;
    R=1;
    while (E>0)
    {
        if (E&1) R=R*A, --E;
        else {
            A=A*A;
            E>>=1;
        }
        if (pp<A) return A;
        if (pp<R) return R;
    }
    return R;
}
inline int cautarebinara(int b)
{
    huge p, q, zece;
    zece = 10;

    int iter = 0;
    p = 0;
    for (q = 1; putere(q, b) < pp; q = q * zece, ++iter);


    huge nr, s;
    nr=1;
    while((p<q)||(p==q)) {
        mij=p+q;
        mij=mij/2;
        s=putere(mij,b);
        if(s<pp)
            p=mij+nr;
        else if(s==pp)
            return 1;
        else q=mij-1;
    }
    return 0;
}
int main ()
{
    int c,b;
    ifstream f("numere2.in");
    ofstream g("numere2.out");
    f>>pp;
    f.close();
    baza=10000;
    for(b=100;b>=1;b--) {
        c=cautarebinara(b);
        if(c) {
            g<<mij<<'\n'<<b;
            break;
        }
    }
    g.close();
    return 0;
    return 0;
}
