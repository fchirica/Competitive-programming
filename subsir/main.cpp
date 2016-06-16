#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int kNMax = 555;
const int kMod = 666013;

char a[kNMax], b[kNMax];
int cmlsc[kNMax][kNMax];
int ways[kNMax][kNMax];
int prevA[26][kNMax], prevB[26][kNMax];

int main() {
    freopen("subsir.in", "r", stdin);
    freopen("subsir.out", "w", stdout);

    gets(a + 1);
    gets(b + 1);
    int n = strlen(a + 1);
    int m = strlen(b + 1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                cmlsc[i][j] = 1 + cmlsc[i - 1][j - 1];
            else
                cmlsc[i][j] = max(cmlsc[i - 1][j], cmlsc[i][j - 1]);

    for (int i = 0; i < 26; ++i) {
        prevA[i][0] = -1;
        prevB[i][0] = -1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 26; ++j)
            if (a[i] == (char) j + 'a')
                prevA[j][i] = i;
            else
                prevA[j][i] = prevA[j][i - 1];
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < 26; ++j)
            if (b[i] == (char) j + 'a')
                prevB[j][i] = i;
            else
                prevB[j][i] = prevB[j][i - 1];

    for (int i = 0; i <= n; ++i)
        ways[i][0] = 1;
    for (int i = 0; i <= m; ++i)
        ways[0][i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 26; ++k) {
                int prev_i = prevA[k][i];
                int prev_j = prevB[k][j];
                if (prev_i == -1 || prev_j == -1)
                    continue;
                if (cmlsc[prev_i - 1][prev_j - 1] + 1 == cmlsc[i][j]) {
                    ways[i][j] += ways[prev_i - 1][prev_j - 1];
                    if (ways[i][j] >= kMod)
                        ways[i][j] -= kMod;
                }
            }
            if (cmlsc[i][j] == 0)
                ways[i][j] = 1;
        }
    printf("%d", ways[n][m]);
    return 0;
}
