#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector <int> C[1024];

struct rundadekkt //Am pierdut aproape 30 de minute numai sa inteleg problema. Cea mai de kkt runda!
{
    int x, cul;
};

struct cmpdekkt //La fel ca runda...
{
    bool operator()(rundadekkt A, rundadekkt B) const
    {
        return A.x > B.x;
    }
};

set <rundadekkt, cmpdekkt> H;

void baga(int cul)
{
    if (C[cul].size() == 0)
        return ;

    rundadekkt cacat2;
    cacat2.x = C[cul][C[cul].size() - 1];
    cacat2.cul = cul;
    C[cul].pop_back();

    H.insert(cacat2);
}

int main()
{
    int i, N, K;

    freopen("placute.in", "r", stdin);
    freopen("placute.out", "w", stdout);

    scanf("%d%d", &N, &K);
    for (i = 1; i <= N; i ++)
    {
        int g, color;
        scanf("%d%d", &g, &color);

        C[color].push_back(g);
    }

    int lastc = 1 << 30;
    long long pula = 0;

    for (i = 1; i <= K; i ++)
        sort(C[i].begin(), C[i].end());
    for (i = 1; i <= K; i ++)
        baga(i);

    while (!H.empty())
    {
        rundadekkt porno = *H.begin();
        H.erase(H.begin());
        pula += porno.x;
        if (lastc != 1 << 30)
            baga(lastc);
        lastc = porno.cul;
    }

    printf("%lld", pula);
    return 0;
}
