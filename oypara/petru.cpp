#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define mp make_pair
#define LL long long
using namespace std;

typedef pair<LL,LL> per;

int n;
vector<per> sus,jos,ls,lj;

LL id(per a,per b, per c) {
  LL sum=b.x*c.y+c.x*a.y+a.x*b.y;
  LL dif=a.x*c.y+c.x*b.y+b.x*a.y;
  return sum-dif<=0LL;
}

vector<per> ic(vector<per> p,int s) {
  sort(p.begin(),p.end());
  if(s)reverse(p.begin(),p.end());
  vector<per> st;
  st.push_back(p[0]); st.push_back(p[1]);
  for(int i=2; i<p.size(); ++i) {
    for(;st.size()>1 && id(st[st.size()-2],st[st.size()-1],p[i]);st.pop_back());
    st.push_back(p[i]);
  }
  //if(s) reverse(st.begin(),st.end());
  return st;
}

per p1;

int main()
{
    ifstream f("oypara.in");
    ofstream g("oypara.out");
    f>>n;
    for(int i=1; i<=n; ++i) {
      int x,y1,y2;
      f>>x>>y1>>y2;
      jos.push_back(mp(x,y1));
      sus.push_back(mp(x,y2));
    }
    lj=ic(jos,1);

    ls=ic(sus,0);
    for(int i=0,j=0;i+1<ls.size();++i) {
      for(;id(ls[i],ls[i+1],lj[j]) && j<lj.size();++j);
      if(j==lj.size()) {
        p1=ls[i];
        break;
      }
    }

    for (int i = 0; i < ls.size(); ++i)
        cerr << ls[i].x << " " << ls[i].y << "\n";
    for (int i = 0; i < lj.size(); ++i)
        cerr << lj[i].x << " " << lj[i].y << "\n";


    for(int i=0;i+1<lj.size();++i) {
      if(id(lj[i],lj[i+1],p1)) {
        g<<p1.x<<' '<<p1.y<<' '<<lj[i].x<<' '<<lj[i].y;
        return 0;
      }
    }
    return 0;
}


