#include <iostream>
#include <string.h>

using namespace std;

long long prev[100010], cur[100010];

int main() {
    long long n, k;
    cin >> n >> k;

    for (int steps = 1; steps <= k; ++steps) {
        cur[0] = 0;
        for (int i = 1; i <= prev[0]; ++i)
            for (int d = 1; (long long)d * d <= )

        bool same = true;
        for (int i = 0; i <= cur[0]; ++i) {
            if (prev[i] != cur[i])
                same = false;
            prev[i] = cur[i];
        }
        if (same)
            break;
    }

    for (int i = 1; i <= prev[0]; ++i)
        printf("%d ", prev[i]);
    return 0;
}
