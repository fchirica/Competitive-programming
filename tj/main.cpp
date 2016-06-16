#include <bits/stdc++.h>

using namespace std;

const int kNMax = 300;

int n, g[kNMax][kNMax], common[kNMax][kNMax], degree[kNMax];
bool killed[kNMax];

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

int cand[kNMax];

bool solve() {
    int steps = n;
    while (steps > 1) {
        int dominated;
        for (dominated = 1; dominated <= n; ++dominated) {
            if (killed[dominated])
                continue;
            int wanted_degree = degree[dominated] - 1;
            bool ok = 0;
            for (int i = 1; i <= n && !ok; ++i)
                if (g[i][dominated] && common[i][dominated] == wanted_degree)
                    ok = 1;
            if (ok)
                break;
        }
        if (dominated == n + 1)
            return false;

        int cand_len = 0;
        for (int i = 1; i <= n; ++i)
            if (!killed[i] && g[i][dominated])
                cand[++cand_len] = i;

        for (int i = 1; i <= cand_len; ++i)
            for (int j = i + 1; j <= cand_len; ++j) {
                --common[cand[i]][cand[j]];
                --common[cand[j]][cand[i]];
        }
        for (int i = 1; i <= n; ++i)
            if (g[i][dominated])
                --degree[i];
        for (int i = 1; i <= n; ++i) {
            g[dominated][i] = 0;
            g[i][dominated] = 0;
        }
        killed[dominated] = true;
        --steps;
    }
    return true;
}

int main() {
    freopen("tj.in", "r", stdin);
    freopen("tj.out", "w", stdout);

    fastReader myScanner;

    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        myScanner.readInt(n);
        myScanner.readInt(m);
        for (int i = 1; i <= m; ++i) {
            int xx, yy;
            myScanner.readInt(xx);
            myScanner.readInt(yy);
            ++degree[xx];
            ++degree[yy];
            g[xx][yy] = g[yy][xx] = 1;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (g[i][j] && i != j)
                    for (int k = 1; k <= n; ++k)
                        if (k != i && k != j)
                            if (g[i][k] && g[j][k]) {
                                ++common[j][i];
                                ++common[i][j];
                            }
        printf("%s\n", solve() ? "DA" : "NU");

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                g[i][j] = 0;
                common[i][j] = 0;
            }
        for (int i = 1; i <= n; ++i) {
            killed[i] = 0;
            degree[i] = 0;
        }
    }

    return 0;
}
