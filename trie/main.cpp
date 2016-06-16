#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)
#define FOREACH(it, G) for(__typeof(G.begin()) it = G.begin() ; it != G.end() ; ++ it)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

struct nod {
    int pref, words;
    int let[27];

    nod() {
        pref = words = 0;
        FOR(i, 26)
            let[i] = 0;
    }
};

vector <nod> trie;

nod emptyNod;
char word[25];

void add(int pos, int nod, int len) {
    ++trie[nod].pref;
    if (pos == len) {
        ++trie[nod].words;
        return ;
    }

    int nextNod = trie[nod].let[word[pos] - 'a' + 1];
    if (nextNod == 0) {
        trie[nod].let[word[pos] - 'a' + 1] = trie.size();
        nextNod = trie.size();
        trie.pb(emptyNod);
    }
    add(pos + 1, nextNod, len);
}

void del(int pos, int nod, int len) {
    --trie[nod].pref;
    if (pos == len) {
        --trie[nod].words;
        return ;
    }
    int nextNod = trie[nod].let[word[pos] - 'a' + 1];
    del(pos + 1, nextNod, len);
}

void countWords(int pos, int nod, int len) {
    if (pos == len) {
        printf("%d\n", trie[nod].words);
        return ;
    }
    int nextNod = trie[nod].let[word[pos] - 'a' + 1];
    if (nextNod == 0) {
        printf("0\n");
        return ;
    }
    countWords(pos + 1, nextNod, len);
}

void prefix(int pos, int nod, int len, int curPref) {
    if (pos == len) {
        printf("%d\n", curPref);
        return ;
    }
    int nextNod = trie[nod].let[word[pos] - 'a' + 1];
    if (nextNod == 0 || trie[nextNod].pref == 0) {
        printf("%d\n", curPref);
        return ;
    }
    else
        prefix(pos + 1, nextNod, len, curPref + 1);
}

int main() {
    freopen("trie.in", "r", stdin);
    freopen("trie.out", "w", stdout);

    trie.pb(emptyNod);

    int op;
    while (scanf("%d %s\n", &op, &word) != EOF) {
        int n = strlen(word);
        switch (op) {
            case 0: {   add(0, 0, n);   break; }
            case 1: {   del(0, 0, n);   break; }
            case 2: {   countWords(0, 0, n); break; }
            case 3: {   prefix(0, 0, n, 0); break; }
            default: return 0;
        }
    }

    return 0;
}
