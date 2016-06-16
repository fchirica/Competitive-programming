#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int kMod = 31333;

char x[300300];
int dp[300300];
char w[111];

struct trie {
    int cnt, go[26];

    trie() {
        cnt = 0;
    }
} emptyNode;

vector <trie> T;

void baga(int nod, int pos, int len) {
    if (pos == len + 1) {
        return ;
    }

    int nextNod;
    if (T[nod].go[w[pos] - 'a'])
        nextNod = T[nod].go[w[pos] - 'a'];
    else {
        T.push_back(emptyNode);
        nextNod = ((int)T.size()) - 1;
        T[nod].go[w[pos] - 'a'] = nextNod;
    }

    ++T[nextNod].cnt;
    baga(nextNod, pos + 1, len);
}

int main() {
    freopen("enigma.in", "r", stdin);
    freopen("enigma.out", "w", stdout);

    int n, m;
    scanf("%d%d\n", &n, &m);
    gets(x + 1);

    T.push_back(emptyNode);

    for (int i = 1; i <= m; ++i) {
        gets(w + 1);
        int wordLen = strlen(w + 1);
        baga(0, 1, wordLen);
    }

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int nod = 0;
        for (int j = i + 1; j <= n; ++j)
            if (T[nod].go[x[j] - 'a']) {
                nod = T[nod].go[x[j] - 'a'];
                dp[j] += dp[i] * T[nod].cnt;
                dp[j] %= kMod;
            } else
                break;
    }

    printf("%d", dp[n]);
    return 0;
}
