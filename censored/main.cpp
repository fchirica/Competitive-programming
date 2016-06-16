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

char al[55];
char w[15][15];
string W[15];

map <string, int> trie;
vector <int> G[105];
int oldPath[105][105], newPath[105][105], res[105], tmp[105];

void add(int A[], int B[]) {
    tmp[0] = max(A[0], B[0]);
    int tr = 0;
    for (int i = 1; i <= tmp[0]; ++i) {
        int digA = i <= A[0] ? A[i] : 0;
        int digB = i <= B[0] ? B[i] : 0;
        tmp[i] = digA + digB + tr;
        tr = tmp[i] / 10;
        tmp[i] = tmp[i] % 10;
    }
    if (tr)
        tmp[++tmp[0]] = tr;
}

int main() {
    int N, M, words;

    scanf("%d%d%d\n", &N, &M, &words);
    for (int i = 1; i <= N; ++i)
        scanf("%c", &al[i]);

    scanf("\n");
    for (int i = 1; i <= words; ++i) {
        gets(w[i] + 1);
        int len = strlen(w[i] + 1);
        for (int j = 1; j <= len; ++j)
            W[i] += w[i][j];
    }

    string cur = "";
    trie[cur] = 1;

    int trieCnt = 1;
    for (int i = 1; i <= words; ++i) {
        bool isUseful = true;
        for (int j = 1; j <= words; ++j)
            if (i != j) {
                int dif = strlen(w[i] + 1) - strlen(w[j] + 1) + 1;
                for (int k = 1; k <= dif; ++k)
                    if (W[i].substr(k - 1, W[j].sz()) == W[j])
                        isUseful = false;
            }
        if (isUseful) {
            cur = "";
            int len = strlen(w[i] + 1);
            for (int j = 1; j <= len; ++j) {
                cur += w[i][j]; ++trieCnt;
                trie[cur] = trieCnt;
            }
        }
    }

    map <string, int> :: iterator it, it2;
    for (it = trie.begin(); it != trie.end(); ++it) {
        for (int i = 1; i <= N; ++i) {
            cur = it -> first + al[i];
            bool canExtend = true;
            for (int j = 1; j <= words; ++j)
                if ((int)cur.sz() - (int)W[j].sz() >= 0)
                    if (cur.substr(cur.sz() - W[j].sz()) == W[j])
                        canExtend = false;
            if (canExtend) {
                int bestPref = 0, bestNod = 1;
                for (it2 = trie.begin(); it2 != trie.end(); ++it2) {
                    string pref = it2 -> first;
                    if (pref == "")
                        continue;
                    if (pref.sz() < bestPref)
                        continue;
                    if (pref.sz() > cur.sz())
                        continue;
                    if (cur.substr(cur.sz() - pref.sz()) == pref)
                        bestPref = pref.sz(), bestNod = it2 -> second;
                }
                G[it -> second].pb(bestNod);
            }
        }
    }

    oldPath[1][0] = oldPath[1][1] = 1;
    for (int times = 1; times <= M; ++times) {
        for (int i = 1; i <= trieCnt; ++i)
            newPath[i][0] = 1, newPath[i][1] = 0;
        for (int i = 1; i <= trieCnt; ++i) {
            if (oldPath[i][0] == 1 && oldPath[i][1] == 0)
                continue;
            vector <int> :: iterator it;
            for (it = G[i].begin(); it != G[i].end(); ++it) {
                add(newPath[*it], oldPath[i]);
                memcpy(newPath[*it], tmp, sizeof(newPath[*it]));
            }
        }
        for (int i = 1; i <= trieCnt; ++i)
            memcpy(oldPath[i], newPath[i], sizeof(oldPath[i]));
    }

    res[0] = 1; res[1] = 0;
    for (int i = 1; i <= trieCnt; ++i) {
        add(res, oldPath[i]);
        memcpy(res, tmp, sizeof(res));
    }
    for (int i = res[0]; i >= 1; --i)
        printf("%d", res[i]);
    return 0;
}
