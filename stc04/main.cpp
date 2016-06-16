#include <stdio.h>
#include <vector>

using namespace std;

char x[1000100];
vector <int> ap[30];
int tmp[1000100], SP[1000100];

int compute(int ch1, int ch2) {
    int n1 = ap[ch1].size() - 1, n2 = ap[ch2].size() - 1;
    tmp[0] = 0;
    int idx1 = 0, idx2 = 0;
    while (idx1 <= n1 || idx2 <= n2) {
        if (idx1 > n1) {
            tmp[++tmp[0]] = 1; ++idx2;
        }
        else
        if (idx2 > n2) {
            tmp[++tmp[0]] = -1; ++idx1;
        }
        else {
            int px = ap[ch1][idx1];
            int py = ap[ch2][idx2];
            if (px < py) {
                tmp[++tmp[0]] = -1;
                ++idx1;
            } else {
                tmp[++tmp[0]] = 1;
                ++idx2;
            }
        }
    }

    for (int i = 1; i <= tmp[0]; ++i)
        SP[i] = SP[i - 1] + tmp[i];
    int sum = 1 << 30, best = 0, j = 0;
    for (int i = 1; i <= tmp[0]; ++i) {
        if (tmp[i] == -1)
            for (; j < i; ++j)
                if (SP[j] < sum)
                    sum = SP[j];
        if (SP[i] - sum > best)
            best = SP[i] - sum;
    }
    return best;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int N;
    scanf("%d\n", &N);
    gets(x + 1);
    for (int i = 1; i <= N; ++i)
        ap[x[i] - 'a'].push_back(i);

    int best = 0;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j) {
            if (i == j)
                continue;
            int tmp = compute(i, j);
            if (tmp > best)
                best = tmp;
        }

    printf("%d", best);
    return 0;
}
