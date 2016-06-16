#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

char A[1000100], B[1000100];
vector <int> pos[30];
int idx[30], x[1000100], F[1000100];

inline int lsb(int X) {
    return X & -X;
}

int query(int pos) {
    int cnt = 0;
    for (; pos > 0; pos = pos - lsb(pos))
        cnt += F[pos];
    return cnt;
}

void update(int pos, int N) {
    int i;
    for (; pos <= N; pos = pos + lsb(pos))
        ++F[pos];
}

int main() {
    //freopen("letters.in", "r", stdin);
    //freopen("letters.out", "w", stdout);

    int N;
    scanf("%d\n", &N);
    gets(A + 1); gets(B + 1);

    int i;
    for (i = 1; i <= N; ++i)
        pos[B[i] - 'A' + 1].push_back(i);
    for (i = 1; i <= N; ++i)
        x[i] = pos[A[i] - 'A' + 1][idx[A[i] - 'A' + 1]++];

    long long inv = 0;
    for (i = 1; i <= N; ++i) {
        inv += query(N) - query(x[i]);
        update(x[i], N);
    }

    printf("%lld", inv);
    return 0;
}
