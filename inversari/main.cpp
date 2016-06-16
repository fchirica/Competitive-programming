#include <stdio.h>
#include <vector>

using namespace std;

int x[5555];  //ca domnisoara babenco

struct query {
    int x, y, idx;
};

vector <query> Q[5555];
int D[2][5555], I[2][5555];
int res[100100];

const int DIM = (1 << 12);
int poz = 0;
char buff[DIM + 100];

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

int main() {
    freopen("inversari.in", "r", stdin);
    freopen("inversari.out", "w", stdout);

    int n, q;
    read(n); read(q);
    for (int i = 1; i <= n; ++i)
        read(x[i]);

    for (int i = 1; i <= q; ++i) {
        int xx, yy;
        read(xx); read(yy);
        query now;
        now.x = xx; now.y = yy; now.idx = i;
        Q[yy - xx + 1].push_back(now);
    }

    for (int len = 2; len <= n; ++len) {
        int act = len % 2;
        int prev = 1 - len % 2;
        for (int i = len; i <= n; ++i) {
            I[act][i] = I[prev][i];
            if (x[i - len + 1] > x[i])
                ++I[act][i];
            D[act][i] = D[prev][i - 1] + I[act][i];
        }
        vector <query> :: iterator it;
        for (it = Q[len].begin(); it != Q[len].end(); ++it)
            res[it -> idx] = D[act][it -> y];
    }

    for (int i = 1; i <= q; ++i)
        printf("%d\n", res[i]);
    return 0;
}
