#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int x[100100], xorsum[100100];
int b[22];

struct nod {
    int go[2];

    nod() {
        go[0] = go[1] = -1;
    }
} emptyNod;

vector <nod> trie;

void make(int val) {
    for (int i = 1; i <= 21; ++i)
        b[i] = 0;
    int pos = 21;
    while (val) {
        b[pos] = val % 2;
        val = val / 2;
        --pos;
    }
}

void add(int nod, int pos) {
    if (pos == 22)
        return ;
    int nextNod = trie[nod].go[b[pos]];
    if (nextNod == -1) {
        int ret = trie.size();
        trie.push_back(emptyNod);
        nextNod = trie[nod].go[b[pos]] = ret;
    }
    add(nextNod, pos + 1);
}

int query(int nod, int pos) {
    if (pos == 22)
        return 0;
    int wanted = 1 - b[pos];
    for (int i = 0; i < 2; ++i) {
        if (trie[nod].go[wanted] != -1)
            return (1 << (21 - pos)) * wanted + query(trie[nod].go[wanted], pos + 1);
        wanted = 1 - wanted;
    }
}

int main() {
    freopen("xormax.in", "r", stdin);
    freopen("xormax.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &x[i]);
        xorsum[i] = xorsum[i - 1] ^ x[i];
    }

    trie.push_back(emptyNod);

    add(0, 1);
    int sol = -1, idx;
    for (int i = 1; i <= N; ++i) {
        make(xorsum[i]);
        int cur = query(0, 1);
        cur ^= xorsum[i];
        if (cur > sol) {
            sol = cur;
            idx = i;
        }
        add(0, 1);
    }

    printf("%d ", sol);
    for (int i = idx; i >= 1; --i)
        if ((xorsum[idx] ^ xorsum[i - 1]) == sol) {
            printf("%d %d", i, idx);
            return 0;
        }
    return 0;
}

