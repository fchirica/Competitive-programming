#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#define x first
#define y second

using namespace std;

pair <int, int> S[250100];
int nn, isFat[250100];

const int md = 5000000;

struct myHash {
    int xx, yy, cnt;
};

myHash make(int xx, int yy) {
    myHash tmp; tmp.xx = xx; tmp.yy = yy; tmp.cnt = 1;
    return tmp;
}

vector <myHash> H[md];
vector <pair <int, int> > H2[md];

const double Knuth = ((double)sqrt(5) - 1) / 2;

int hash(pair <int, int> X) {
    double tmp = 1 / (double)(X.x + 0.0001) + (double)1 / ((double)X.y + 0.0001);
    if (tmp < 0) tmp = -tmp;
    double tmp2 = Knuth * tmp - floor(Knuth * tmp);
    return floor(md * tmp2);
}

void add(pair <int, int> X) {
    if (X.x > X.y)
        swap(X.x, X.y);
    vector <myHash> :: iterator it;
    int go = hash(X);
    for (it = H[go].begin(); it != H[go].end(); ++it)
        if (it -> xx == X.x && it -> yy == X.y) {
            ++it -> cnt;
            return ;
        }
    H[go].push_back(make(X.x, X.y));
}

void addPoint(pair <int, int> X) {
    int go = hash(X);
    H2[go].push_back(X);
}

bool is(pair <int, int> X) {
    int go = hash(X);
    vector <pair <int, int> > :: iterator it;
    for (it = H2[go].begin(); it != H2[go].end(); ++it)
        if (*it == X)
            return 1;
    return 0;
}

void loadThin(int xx, int yy) {
    for (int i = xx; i < yy; ++i)
        for (int j = i + 1; j <= yy; ++j)
            add(make_pair(S[i].y, S[j].y));
}

int mp[300000], mp2[300000];

long long computeFat(int xx, int N, int type) {
    long long res = 0;
    mp[0] = mp2[0] = 0;
    for (int i = 1; i <= N; ++i)
        if (S[i].x != xx) {
            if (!is(make_pair(xx, S[i].y)))
                continue;
            int d = S[i].x - xx;
            if (isFat[i] == type)
                mp[++mp[0]] = d;
            else
                mp2[++mp2[0]] = d;
        }
    long long l = 1;
    sort(mp + 1, mp + mp[0] + 1);
    mp[mp[0] + 1] = mp[mp[0]] - 1;
    for (int i = 1; i <= mp[0]; ++i)
        if (mp[i] == mp[i + 1])
            ++l;
        else {
            res += l * (l - 1) / 2;
            l = 1;
        }
    return res;
}

long long computeFat2() {
    long long l = 1, res = 0;
    sort(mp2 + 1, mp2 + mp2[0] + 1);
    mp2[mp2[0] + 1] = mp2[mp2[0]] - 1;
    for (int i = 1; i <= mp2[0]; ++i)
        if (mp2[i] == mp2[i + 1])
            ++l;
        else {
            res += l * (l - 1) / 2;
            l = 1;
        }
    return res;
}

long long computeThin() {
    vector <myHash> :: iterator it;
    long long res = 0;
    for (int i = 0; i < md; ++i)
        for (it = H[i].begin(); it != H[i].end(); ++it)
            res += ((long long)it -> cnt * (it -> cnt - 1)) / 2;
    return res;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        S[i].x = i / 500;
        S[i].y = i % 500;
        addPoint(S[i]);
    }

    sort(S + 1, S + N + 1);

    int l = 1, lim = 4 * sqrt(N);
    for (int i = 1; i <= N; ++i)
        if (S[i].x == S[i + 1].x)
            ++l;
        else {
            if (l >= lim) {
                ++isFat[i - l + 1];
                --isFat[i + 1];
            }
            l = 1;
        }
    for (int i = 1; i <= N; ++i)
        isFat[i] += isFat[i - 1];
    long long ff = 0, ft = 0, tt = 0;
    for (int i = 1; i <= N; ++i)
        if (S[i].x == S[i + 1].x)
            ++l;
        else {
            if (isFat[i]) {
                ff += computeFat(S[i].x, N, 1);
                ft += computeFat2();
            } else
                loadThin(i - l + 1, i);
            l = 1;
        }

    tt = computeThin();
    printf("%lld", ff / 2 + ft + tt);
    return 0;
}

