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

char x[555][555];

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int testCases;
    scanf("%d", &testCases);
    for (int test = 1; test <= testCases; ++test) {
        int N, M;
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++i)
            gets(x[i] + 1);


    }
    return 0;
}
