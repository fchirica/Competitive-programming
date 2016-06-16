#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct trie {
    int go[2], fail, res;
    vector <int> v;

    trie() {
        go[0] = go[1] = fail = res = 0;
    }
} T[1000100];

int cnt = 1;
char x[100100], w[1024];
int Q[1000100];

void baga(int nod, int pos, int len, int idx) {
    if (pos == len + 1) {
        T[nod].v.push_back(idx);
        return ;
    }
    int nextNod = T[nod].go[w[pos] - '0'];
    if (nextNod == 0)
        nextNod = T[nod].go[w[pos] - '0'] = ++cnt;
    baga(nextNod, pos + 1, len, idx);
}

int p = 1, u = 0;

void failure() {
    for (int i = 0; i <= 1; ++i)
        if (T[1].go[i]) {
            Q[++u] = T[1].go[i];
            T[T[1].go[i]].fail = 1;
        }
    while (p <= u) {
        int nod = Q[p];
        for (int i = 0; i <= 1; ++i) {
            int curFail = T[nod].fail;
            if (T[nod].go[i] == 0)
                continue;
            while (1) {
                if (T[curFail].go[i]) {
                    curFail = T[curFail].go[i];
                    break;
                }
                if (curFail == 1)
                    break;
                else
                    curFail = T[curFail].fail;
            }
            Q[++u] = T[nod].go[i];
            T[T[nod].go[i]].fail = curFail;
        }
        ++p;
    }
}

int sol[1024];

int main() {
    freopen("virus.in", "r", stdin);
    freopen("virus.out", "w", stdout);

    int N, K;
    scanf("%d%d\n", &N, &K);
    gets(x + 1);

    for (int i = 1; i <= K; ++i) {
        int len;
        scanf("%d\n", &len);
        gets(w + 1);
        baga(1, 1, len, i);
    }

    failure();

    int nod = 1;
    for (int i = 1; i <= N; ++i) {
        int next = x[i] - '0';
        while (1) {
            if (T[nod].go[next]) {
                nod = T[nod].go[next];
                break;
            }
            if (nod == 1)
                break;
            nod = T[nod].fail;
        }
        ++T[nod].res;
    }

    for (int i = u; i >= 1; --i) {
        vector <int> :: iterator it;
        int nod = Q[i];
        for (it = T[nod].v.begin(); it != T[nod].v.end(); ++it)
            sol[*it] += T[nod].res;
        T[T[nod].fail].res += T[nod].res;
    }
    for (int i = 1; i <= K; ++i)
        printf("%d\n", sol[i]);
    return 0;
}
