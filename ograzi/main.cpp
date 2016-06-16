#include <stdio.h>
#include <algorithm>
#include <vector>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

const int MOD = 666013;

vector <point> myHash[MOD];

int hsh(point X) {
    return (X.x + 6971 * X.y) % MOD;
}

int H, W;

const int DIM = (1 << 12);
char buff[DIM];
int poz = 0;

void read(int &numar) {
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    while ('0' <= buff[poz] && buff[poz] <= '9') {
        numar = numar * 10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff, 1, DIM, stdin), poz = 0;
    }
}

bool is(point X, int where) {
    vector <point> :: iterator it;
    if (where < 0)
        return 0;
    for (it = myHash[where].begin(); it != myHash[where].end(); ++it)
        if ((*it).x <= X.x && X.x <= (*it).x + W &&
            (*it).y <= X.y && X.y <= (*it).y + H)
                return 1;
    return 0;
}

int main() {
    freopen("ograzi.in", "r", stdin);
    freopen("ograzi.out", "w", stdout);

    int N, M;
    read(N); read(M); read(W); read(H);
    for (int i = 1; i <= N; ++i) {
        point tmp;
        read(tmp.x); read(tmp.y);
        myHash[hsh(make_pair(tmp.x / W, tmp.y / H))].push_back(tmp);
    }

    int sol = 0;
    for (int i = 1; i <= M; ++i) {
        point tmp;
        read(tmp.x); read(tmp.y);
        bool ok = 0;
        for (int dx = -1; dx <= 0 && !ok; ++dx)
            for (int dy = -1; dy <= 0 && !ok; ++dy)
                ok = is(tmp, hsh(make_pair(tmp.x / W + dx, tmp.y / H + dy)));
        sol += ok;
    }

    printf("%d", sol);
    return 0;
}
