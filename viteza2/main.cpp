#include <bits/stdc++.h>

using namespace std;

const int kNMax = 1010;
const int kMMax = 5555;

int n, m;

class fastReader {
    public:
        fastReader() {
            bufferSize = 4096;
            pos = 4096;
        }

        void readInt(int &res) {
            int sign = 1;
            char ch;
            res = 0;
            do {
                ch = getChar();
                if (ch == '-')
                    sign = -1;
            } while (!isdigit(ch));
            do {
                res = res * 10 + ch - '0';
                ch = getChar();
            } while (isdigit(ch));
            res = res * sign;
        }

    private:
        int bufferSize, pos;
        char buffer[4096];

        char getChar() {
            if (pos == bufferSize) {
                fread(buffer, 1, bufferSize, stdin);
                pos = 0;
            }
            return buffer[pos++];
        }
};

struct edge {
    int xx, yy, cc;
} M[kMMax];

long long res[kNMax][kNMax];

inline bool comp(edge A, edge B) {
    return A.cc < B.cc;
}

void calc(int cur, int prev, int cost) {
    for (int i = 1; i <= n; ++i)
        if (res[i][prev] + cost < res[i][cur])
            res[i][cur] = res[i][prev] + cost;
}

int main() {
    freopen("viteza2.in", "r", stdin);
    freopen("viteza2.out", "w", stdout);

    fastReader fr; fr.readInt(n); fr.readInt(m);
    for (int i = 1; i <= m; ++i) {
        fr.readInt(M[i].xx);
        fr.readInt(M[i].yy);
        fr.readInt(M[i].cc);
    }

    sort(M + 1, M + m + 1, comp);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            res[i][j] = 1LL << 35;
            if (i == j)
                res[i][i] = 0;
        }

    for (int i = 1; i <= m; ++i) {
        int xx = M[i].xx;
        int yy = M[i].yy;
        int cc = M[i].cc;
        calc(xx, yy, cc);
        calc(yy, xx, cc);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (res[i][j] == 1LL << 35)
                res[i][j] = -1;
            printf("%lld ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
