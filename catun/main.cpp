#include<stdio.h>
#include<vector>
#define INF 1<<30
#define NMAX 40000
#define MMAX 75000


struct heap
{
    int cst,nod;
} H[NMAX];

struct pair2
{
    int son,cst;
};

using namespace std;

int num,sol[NMAX], ret[NMAX];
bool used[NMAX];

vector<pair2> L[NMAX];

void pop()
{
    int son,nod = 1;
    heap aux;
    H[1] = H[num--];
    do
    {
        son = 0;
        if( 2 * nod <= num )
            {
                son = 2 * nod;
                if(2 * nod + 1 <=num && H[2 * nod + 1].cst < H[2 * nod].cst)
                    son = 2 * nod + 1;
            }
        if(H[nod].cst < H[son].cst)
            son=0;
        if(son)
            {
                aux = H[nod];
                H[nod] = H[son];
                H[son] = aux;
                nod = son;
            }
    }
    while(son);
}

void push(int node)
{
    int nod;
    heap aux;
    aux.nod = node; aux.cst = sol[node];
    H[++num] = aux; nod = num;
    while(nod / 2 > 0 && H[nod].cst < H[nod/2].cst)
    {
        aux = H[nod];
        H[nod] = H[nod / 2];
        H[nod/2] = aux;
        nod = nod / 2;
    }
}

int main()
{
    int N,M,K, x,now,i;
    pair2 aux;
    heap aux2;
    vector<pair2> :: iterator it;

    freopen("catun.in","r",stdin);
    freopen("catun.out","w",stdout);

    scanf("%d%d%d",&N,&M, &K);
    for(i=1;i<=N;i++)
        sol[i] = INF, ret[i] = 1 << 30;
    for (i = 1; i <= K; ++i) {
        int tmp;
        scanf("%d", &tmp);
        aux2.cst = 0; aux2.nod = i;
        sol[tmp] = 0; ret[tmp] = tmp;
        push(tmp);
    }
    for(i=1;i<=M;i++)
        {
            scanf("%d%d%d",&x,&aux.son,&aux.cst);
            L[x].push_back(aux);
            int tmp = aux.son;
            aux.son = x;
            L[tmp].push_back(aux);
        }

    while(num)
    {
        now = H[1].nod;
        pop ();
        if( used[now])
            continue;
        used[now] = 1;
        for ( it = L[now].begin() ; it != L[now].end(); it++)
        {
            aux = *it;
            if(sol[now] + aux.cst == sol[aux.son] && ret[now] < ret[aux.son])
                ret[aux.son] = ret[now];
            if(sol[now] + aux.cst < sol[aux.son])
                {
                    sol[aux.son] = sol[now] + aux.cst;
                    ret[aux.son] = ret[now];
                    push(aux.son);
                }
        }
    }

    for(i=1;i<=N;i++)
        printf("%d ", (ret[i] != 1 << 30 && sol[i]) ? ret[i] : 0);
    return 0;
}
