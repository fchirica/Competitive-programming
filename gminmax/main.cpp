#include <stdio.h>
#include <vector>

using namespace std;

int cnt = 0, grad_max = 0, left;
int grad[100100], del[100100], top[100100];

vector <int> G[100100], L[100100];

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


void fa_nebunie(int i) {
    if (top[i] == L[i].size())
        return ;

    for (int j = top[i]; j < (int) L[i].size(); ++j, ++top[i])
        if (!del[L[i][j]]) {
            if (i > grad_max) {
                grad_max = i;
                cnt = left;
            }
            --left;
            del[L[i][j]] = 1;
            vector <int> :: iterator it2;
            for (int k = 0; k < (int) G[L[i][j]].size(); ++k)
                if (!del[G[L[i][j]][k]]) {
                    --grad[G[L[i][j]][k]];
                    L[grad[G[L[i][j]][k]]].push_back(G[L[i][j]][k]);
                }
            fa_nebunie(i - 1);
        }
}

int main() {
    freopen("gminmax.in", "r", stdin);
    freopen("gminmax.out", "w", stdout);

    int n, m;
    read(n); read(m);
    left = n;
    for (int i = 1; i <= m; ++i) {
        int xx, yy;
        read(xx); read(yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
        ++grad[xx];
        ++grad[yy];
    }

    for (int i = 1; i <= n; ++i)
        L[grad[i]].push_back(i);

    for (int i = 1; i <= n; ++i)
        fa_nebunie(i);

    printf("%d %d", grad_max, cnt);
    return 0;
}
