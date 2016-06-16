#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <complex>
#include <vector>
#define x first
#define y second

const int mod = 666013;

using namespace std;

pair <int, int> S[100010];
vector < pair <int, int> > H[mod];

inline bool comp(pair <int, int> A, pair <int, int> B) {
    return A.x + A.y < B.x + B.y;
}

int f(pair <int, int> X) {
    unsigned int val = ((unsigned)X.x * 71 + (unsigned)X.y * 73);
    return val % mod;
}

bool is(pair <int, int> X) {
    vector <pair <int, int> > :: iterator it;
    int go = f(X);
    for (it = H[go].begin(); it != H[go].end(); ++it)
        if (X == *it)
            return 1;
    return 0;
}

void add(pair <int, int> X) {
    int go = f(X);
    H[go].push_back(X);
}

int computeHalf(int N) {
    for (int i = 1; i <= N; ++i)
        add(S[i]);
    sort(S + 1, S + N + 1, comp);
    int le = 1, lim = sqrt(N);
    int res = 0;
    for (int i = 1; i <= N; ++i)
        if (S[i].x + S[i].y == S[i + 1].x + S[i + 1].y)
            ++le;
        else {
            if (le >= lim) { //fat
                int sum = S[i].x + S[i].y;
                for (int j = 1; j <= N; ++j) {
                    int d = sum - S[j].x - S[j].y;
                    if (is(make_pair(S[j].x + d, S[j].y)) && is(make_pair(S[j].x, S[j].y + d)))
                        res += (d != 0);
                }
            } else { //thin
                int last = i - le + 1;
                for (int j = last; j < i; ++j)
                    for (int k = j + 1; k <= i; ++k) {
                        pair <int, int> xx, yy;
                        xx = S[j]; yy = S[k];
                        if (xx.x > yy.x)
                            swap(xx, yy);
                        if (is(make_pair(xx.x, yy.y)))
                            ++res;
                        if (is(make_pair(yy.x, xx.y)))
                            ++res;
                    }
            }
            le = 1;
        }
    for (int i = 0; i < mod; ++i)
        H[i].clear();
    return res;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &S[i].x, &S[i].y);
    int res = computeHalf(N);
    for (int i = 1; i <= N; ++i) {
        complex <int> px(S[i].x, S[i].y), py(0, 1), pz = px * py;
        S[i] = make_pair(pz.real(), pz.imag());
    }
    res += computeHalf(N);
    printf("%d", res);
    return 0;
}
