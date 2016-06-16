//imi este profunda rusine de fapta mea..

#include <cassert>

#include <fstream>
#include <iostream>
using namespace std;

#define FORIT(it, v) for (vector <int> :: iterator it = v.begin(); it != v.end(); ++it)

const int MAX_NK = 1000000;
const int MAX_COST = 1000;

ifstream fin("rps.in");
ofstream fout("rps.out");

struct TrieNode {
    TrieNode() {
        best = count = 0;
        for (int i = 0; i < 3; ++i)
            next[i] = NULL;
    }
    int best, count;
    TrieNode *next[3];
};

int N, K, W, D;
TrieNode root;

inline void check_max(int &a, int b) {
    a = (a > b ? a : b);
}

inline int find_cost(TrieNode &node, int idx_choose, int idx_beat) {
    int cost = (node.next[idx_beat] == NULL ? 0 : node.next[idx_beat]->count * W) +
               (node.next[idx_choose] == NULL ? 0 : node.next[idx_choose]->best);
    return cost;
}

void buildTrie(TrieNode &node, int idx, string& s) {
    if (idx == K) {
        ++node.count;
        node.best = D * node.count;
        return;
    }

    int son = -1;
    switch (s[idx]) {
        case 'R': son = 0; break;
        case 'P': son = 1; break;
        case 'S': son = 2; break;
        default: assert(true);
    }

    if (node.next[son] == NULL) {
        node.next[son] = new TrieNode;
    }

    buildTrie(*node.next[son], idx + 1, s);

    ++node.count;

    // choose R
    node.best = find_cost(node, 0, 2);
    // choose P
    check_max(node.best, find_cost(node, 1, 0));
    // choose S
    check_max(node.best, find_cost(node, 2, 1));
}

void buildSolution(TrieNode &node, int idx) {
    int best, move;

    // choose P
    move = 1;
    best = find_cost(node, 1, 0);

    // choose R
    int cost = find_cost(node, 0, 2);
    if (cost > best) {
        best = cost;
        move = 0;
    }

    // choose S
    cost = find_cost(node, 2, 1);
    if (cost > best) {
        best = cost;
        move = 2;
    }

    if (idx == K) return;

    switch (move) {
        case 0: fout << 'R'; break;
        case 1: fout << 'P'; break;
        case 2: fout << 'S'; break;
        default: assert(true);
    }

    if (node.next[move] != NULL)
        buildSolution(*node.next[move], idx + 1);
    else {
        while (idx + 1 < K) {
            fout << 'P';
            ++idx;
        }
        return;
    }

}

int main() {
    fin >> N >> K >> W >> D;
    // assert input data
    assert(1 <= N);
    assert(1 <= K);
    assert(N * K <= MAX_NK);
    assert(-MAX_COST <= W && W <= MAX_COST);
    assert(-MAX_COST <= D && D <= MAX_COST);

    for (int i = 1; i <= N; ++i) {
        string s; fin >> s;
        // assert input data
        buildTrie(root, 0, s);
        buildSolution(root, 0);
        fout << "\n";
    }
}
