#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream in("pariuri.in");
ofstream out("pariuri.out");
const int Mod = 666013;
vector<int> S;
int N,M;
struct map{
    struct item{
        int ind,val;
    };
    vector<item> C[Mod+5];
    void insert(int i,int x){
        int wh=i%Mod;
        item s;
        s.ind=i;
        s.val=x;
        C[wh].push_back(s);
        S.push_back(i);
    }
    void add(int i,int x){
        int wh=i%Mod;
        for(vector<item>::iterator it=C[wh].begin();it!=C[wh].end();++it){
            if( it->ind == i ){
                it->val += x;
                return;
            }
        }
        insert(i,x);
    }
    int operator [] (int i){
        int wh=i%Mod;
        for(vector<item>::iterator it=C[wh].begin();it!=C[wh].end();++it){
            if( it->ind == i ) return it->val;
        }
        return 0;
    }
} Map;
int main(){
    in>>N;
    for(int i=1;i<=N;i++){
        in>>M;
        for(int j=1;j<=M;j++){
            int a,b;
            in>>a>>b;
            Map.add(a,b);
        }
    }
    sort(S.begin(),S.end());
    out<<S.size()<<'\n';
    for(vector<int>::iterator it=S.begin();it!=S.end();++it){
        out<<*it<<' '<<Map[*it]<<' ';
    }
    return 0;
}
