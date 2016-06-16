#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

string x[10100];
vector <int> where[10100];
char tmp[2048];

struct trie {
    int go[26];

    trie () {
        for (int i = 0; i < 26; ++i)
            go[i] = 0;
    }
} root;

vector <trie> T;

void baga(int nod, int pos, int idx) {
    if (pos == x[idx].size())
        return ;
    int nextNod = T[nod].go[x[idx][pos] - 'a'];
    if (nextNod == 0) {
        nextNod = T[nod].go[x[idx][pos] - 'a'] = T.size();
        T.push_back(root);
    }
    where[idx].push_back(nextNod);
    baga(nextNod, pos + 1, idx);
}

int q[11];

bool can(int med) {
    int need = where[q[1]][med];
    for (int i = 2; i <= q[0]; ++i)
        if (where[q[i]][med] != need)
            return 0;
    return 1;
}

int solveQuery() {
    int st = 0, dr = x[q[1]].size(), sol = 0;
    for (int i = 2; i <= q[0]; ++i)
        if (x[q[i]].size() < dr)
            dr = x[q[i]].size();
    --dr;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(med))
            sol = med + 1, st = med + 1;
        else
            dr = med - 1;
    }
    return sol;
}

int main() {
    freopen("ratina.in", "r", stdin);
    freopen("ratina.out", "w", stdout);

    int N, M;
    scanf("%d%d\n", &N, &M);
    T.push_back(root);
    for (int i = 1; i <= N; ++i) {
        gets(tmp);
        x[i] = string(tmp);
        baga(0, 0, i);
    }

    for (int i = 1; i <= M; ++i) {
        scanf("%d", &q[0]);
        for (int j = 1; j <= q[0]; ++j)
            scanf("%d", &q[j]);
        printf("%d\n", solveQuery());
    }

    return 0;
}
