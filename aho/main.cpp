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

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

struct nod {
    int fail, res, ap[30];
    vector <int> idx;

    nod() {
        fail = res = 0;
        for (int i = 1; i <= 26; ++i)
            ap[i] = 0;
    }
};

vector <nod> trie;
nod emptyNod;

char A[1000100], word[10100];

int get(char ch) {
   return ch - 'a' + 1;
}

void add(int nod, int pos, int len, int index) {
    if (pos == len) {
        trie[nod].idx.pb(index);
        return ;
    }
    if (trie[nod].ap[get(word[pos])] == 0) {
        trie.pb(emptyNod);
        trie[nod].ap[get(word[pos])] = trie.sz() - 1;
    }
    int nextNod = trie[nod].ap[get(word[pos])];
    add(nextNod, pos + 1, len, index);
}

int p = 1, u = 0, Q[1000100], sol[1000100];

void failure() {
    for (int i = 1; i <= 26; ++i)
        if (trie[0].ap[i])
            Q[++u] = trie[0].ap[i];
    while (p <= u) {
        int nod = Q[p];
        for (int i = 1; i <= 26; ++i)
            if (trie[nod].ap[i]) {
                int son = trie[nod].ap[i];
                int curFail = trie[nod].fail;
                while (1) {
                    if (trie[curFail].ap[i]) {
                        curFail = trie[curFail].ap[i];
                        break;
                    }
                    if (curFail == 0)
                        break;
                    else
                        curFail = trie[curFail].fail;
                }
                Q[++u] = son;
                trie[son].fail = curFail;
            }
        ++p;
    }
}

void updateSol(int nod, int amount) {
    vector <int> :: iterator it;
    for (it = trie[nod].idx.begin(); it != trie[nod].idx.end(); ++it)
        sol[*it] += amount;
}

int main() {
    freopen("ahocorasick.in", "r", stdin);
    freopen("ahocorasick.out", "w", stdout);

    gets(A + 1);
    int n = strlen(A + 1), m;
    scanf("%d\n", &m);
    trie.pb(emptyNod);

    for (int curWord = 1; curWord <= m; ++curWord) {
        gets(word);
        int len = strlen(word);
        add(0, 0, len, curWord);
    }

    failure();

    int nod = 0;
    for (int i = 1; i <= n; ++i) {
        while (1) {
            if (trie[nod].ap[get(A[i])]) {
                nod = trie[nod].ap[get(A[i])];
                break;
            }
            if (nod == 0)
                break;
            else
                nod = trie[nod].fail;
        }
        ++trie[nod].res;
    }

    for (int i = u; i >= 1; --i) {
        int nod = Q[i];
        updateSol(nod, trie[nod].res);
        int failedNod = trie[nod].fail;
        trie[failedNod].res += trie[nod].res;
    }
    for (int i = 1; i <= m; ++i)
        printf("%d\n", sol[i]);
    return 0;
}
