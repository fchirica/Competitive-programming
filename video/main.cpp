#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

string path[20 * 15 + 1];

int trie[3][20 * 15 + 1];
int fail[20 * 15 + 1];
int w[20 * 15 + 1], win[20 * 15 + 1], dp[20 * 15 + 1][1024];

char word[15];
int cnt = 1;

void addTrie(int nod, int len, int lim, char x[]) {
    if (len == lim) {
        ++w[nod];
        return ;
    }
    int nextNod = trie[x[len] - 'A'][nod];
    if (nextNod == 0)
        nextNod = ++cnt;
    trie[x[len] - 'A'][nod] = nextNod;
    path[nextNod] = path[nod];
    path[nextNod] += x[len];
    addTrie(nextNod, len + 1, lim, x);
}

bool canFail(int xx, int j) {
    for (int i = 0; i < path[xx].size(); ++i)
        if (path[xx].size() - i == path[j].size()) {
            string ret;
            for (int k = i; k < path[xx].size(); ++k)
                ret += path[xx][k];
            if (ret == path[j])
                return 1;
            return 0;
        }
    return 0;
}

void buildFail() {
    for (int i = 1; i <= cnt; ++i) {
        fail[i] = 1;
        for (int j = 1; j <= cnt; ++j)
            if (i != j)
                if (path[j].size() > path[fail[i]].size() && canFail(i, j))
                    fail[i] = j;
    }
}

int go(int i) {
    if (i == 1)
        return 0;
    if (win[i] != -1)
        return win[i];
    return win[i] = w[i] + go(fail[i]);
}

inline void chmax(int &A, int B) {
    if (A < B)
        A = B;
}

int main() {
    //freopen("video.in", "r", stdin);
    //freopen("video.out", "w", stdout);

    int N, K;
    scanf("%d%d\n", &N, &K);
    path[1] = "";
    for (int i = 1; i <= N; ++i) {
        gets(word);
        addTrie(1, 0, strlen(word), word);
    }

    buildFail();
    memset(win, -1, sizeof(win));
    win[1] = 0;
    for (int i = 2; i <= cnt; ++i)
        if (win[i] == -1)
            go(i);

    for (int i = 0; i <= K; ++i)
        for (int nod = 1; nod <= cnt; ++nod)
            dp[nod][i] = -1000000000;
    dp[1][0] = 0;
    for (int i = 0; i < K; ++i)
        for (int nod = 1; nod <= cnt; ++nod)
            for (int c = 0; c < 3; ++c) {
                int nextNod = nod;
                while (1) {
                    if (trie[c][nextNod]) {
                        nextNod = trie[c][nextNod];
                        break;
                    }
                    if (nextNod != 1)
                        nextNod = fail[nextNod];
                    else
                        break;
                }
                chmax(dp[nextNod][i + 1], dp[nod][i] + win[nextNod]);
            }

    int res = 0;
    for (int i = 1; i <= cnt; ++i)
        chmax(res, dp[i][K]);
    printf("%d", res);

    return 0;
}
