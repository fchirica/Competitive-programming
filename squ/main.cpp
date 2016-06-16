#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

multiset <int> S, Sini;
int tmp[300 * 300], x[311];
int sol[1024][311];

bool can(int x23, int N) {
    S = Sini;
    int x12 = *S.begin();
    S.erase(*S.begin());
    int x13 = *S.begin();
    if ((x12 + x13 + x23) % 2)
        return 0;
    int x123 = (x12 + x13 + x23) / 2;
    int small = x123 - x23;
    int x2 = x123 - x13;
    x[1] = small; x[2] = x2;
    for (int i = 3; i <= N; ++i) {
        x[i] = *S.begin() - small;
        S.erase(*S.begin());
        if (x[i] <= x[i - 1])
            return 0;
        for (int j = 2; j < i; ++j) {
            if (S.find(x[i] + x[j]) == S.end())
                return 0;
            S.erase(S.find(x[i] + x[j]));
        }
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N * (N - 1) / 2; ++i) {
        scanf("%d", &tmp[i]);
        Sini.insert(tmp[i]);
    }

    int cnt = 0, processed = 0;

    sort(tmp + 1, tmp + N * (N - 1) / 2 + 1);
    for (int i = 3; i <= N && processed <= 10; ++i) {
        if ((i == 1 || tmp[i] != tmp[i - 1]) && can(tmp[i], N)) {
            ++cnt;
            for (int j = 1; j <= N; ++j)
                sol[cnt][j] = x[j];
        }
        if (i == 1 || tmp[i] != tmp[i - 1])
            ++processed;
    }

    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i) {
        for (int j = 1; j <= N; ++j)
            printf("%d ", sol[i][j]);
        printf("\n");
    }

    return 0;
}
