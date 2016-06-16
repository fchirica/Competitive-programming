#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int pos[1000100], B[1000100];
long long used[1000100];

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int i, M;
    scanf("%d", &M);
    for (i = 1; i <= M; ++i)
        scanf("%d", &B[i]);
    int j, N;
    long long ord = 0;
    scanf("%d", &N);
    used[0] = true;
    for (i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        for (j = 1; j <= tmp; ++j) {
            while (pos[tmp] <= 1000000 && used[pos[tmp]])
                pos[tmp] += tmp;
            if (pos[tmp] > 1000000) {
                ord += tmp - j + 1;
                break;
            }
            used[pos[tmp]] = ++ord;
        }
    }

    vector <long long> shit;
    int solCnt = 0;
    for (i = 1; i <= M; ++i)
        solCnt += used[B[i]] > 0 ? 1 : 0;
    printf("%d\n", solCnt);
    for (i = 1; i <= M; ++i)
        if (used[B[i]])
            shit.push_back(used[B[i]]);
    sort(shit.begin(), shit.end());
    vector <long long> :: iterator it;
    for (it = shit.begin(); it != shit.end(); ++it)
        printf("%lld\n", *it);
    return 0;
}
