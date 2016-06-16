#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define x first
#define y second
#define pii pair <int, int>

using namespace std;

pii S[250100];
int cnt, Y[250100];
vector <int> c[250100];
vector <pii> tt;
bool is[250100];

void load(int col, bool val) {
    vector <int> :: iterator it;
    for (it = c[col].begin(); it != c[col].end(); ++it)
        is[*it] = val;
}

long long sum(long long val) {
    return val * (val - 1) / 2;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &S[i].x, &S[i].y);
        Y[++Y[0]] = S[i].y;
    }
    sort(S + 1, S + N + 1);

    sort(Y + 1, Y + N + 1);
    for (int i = 1; i <= N; ++i) {
        int st = 1, dr = N, ret, med;
        while (st <= dr) {
            med = (st + dr) / 2;
            if (Y[med] == S[i].y) {
                ret = med;
                dr = med - 1;
            }
            if (Y[med] < S[i].y)
                st = med + 1;
            if (Y[med] > S[i].y)
                dr = med - 1;
        }
        S[i].y = ret;
    }

    for (int i = 1; i <= N; ++i)
        if (i == 1 || S[i].x != S[i - 1].x)
            c[++cnt].push_back(S[i].y);
        else
            c[cnt].push_back(S[i].y);

    long long res = 0;
    int lim = sqrt(N) / 6;
    //Fat Fat
    for (int c1 = 1; c1 < cnt; ++c1)
        if (c[c1].size() >= lim) {
            load(c1, 1);
            for (int c2 = c1 + 1; c2 <= cnt; ++c2) {
                int tmp = 0;
                if (c[c2].size() >= lim) {
                    vector <int> :: iterator it;
                    for (it = c[c2].begin(); it != c[c2].end(); ++it)
                        if (is[*it])
                            ++tmp;
                }
                res += sum(tmp);
            }
            load(c1, 0);
        }

    //Thin thin
    for (int c1 = 1; c1 <= cnt; ++c1)
        if (c[c1].size() < lim) {
            int i, j;
            for (int i = 0; i < c[c1].size(); ++i)
                for (int j = i + 1; j < c[c1].size(); ++j)
                    tt.push_back(make_pair(c[c1][i], c[c1][j]));
        }
    if (tt.size()) {
        sort(tt.begin(), tt.end());
        int ret = (int)tt.size() - 2;
        int l = 1;
        for (int i = 0; i <= ret; ++i)
            if (tt[i] == tt[i + 1])
                ++l;
            else {
                res += sum(l);
                l = 1;
           }
         res += sum(l);
    }
    //Fat thin
    for (int c1 = 1; c1 <= cnt; ++c1)
        if (c[c1].size() >= lim) {
            load(c1, 1);
            for (int c2 = 1; c2 <= cnt; ++c2)
                if (c[c2].size() < lim)  {
                    int tmp = 0;
                    vector <int> :: iterator it;
                    for (it = c[c2].begin(); it != c[c2].end(); ++it)
                        if (is[*it])
                            ++tmp;
                    res += sum(tmp);
                }
            load(c1, 0);
        }

    printf("%lld", res);
    return 0;
}

