#include <stdio.h>
#include <algorithm>

using namespace std;

int A[250001], B[250001], pos[250001], offers[250001];

inline bool comp(int pos1, int pos2) {
    return B[pos1] < B[pos2];
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i, j, N;
    scanf("%d", &N);
    for (i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (i = 1; i <= N; ++i) {
        scanf("%d", &B[i]);
        pos[i] = i;
    }

    sort(pos + 1, pos + N + 1, comp);

    for (i = 1; i <= N; ++i) {
        long long sum = 0;
        for (j = pos[i]; j >= 1; --j) {
            sum += A[j];
            if (sum >= B[pos[i]])
                break;
        }
        if (j == 0)
            continue;
        offers[++offers[0]] = pos[i];
        sum = sum - B[pos[i]];
        int k;
        for (k = j; k <= pos[i]; ++k)
            if (A[k] <= sum)
                sum = sum - A[k];
            else {
                A[k] = sum;
                sum = 0;
            }
    }

    printf("%d\n", offers[0]);
    sort(offers + 1, offers + offers[0] + 1);
    for (i = 1; i <= offers[0]; ++i)
        printf("%d ", offers[i]);
    return 0;
}
