#include <iostream>

using namespace std;

long long F[100];

inline int min(int A, int B) {
    return A < B ? A : B;
}

int sol;

void solve(long long x, int steps) {
    int i;
    if (steps >= sol)
        return ;
    if (x == 0) {
        if (steps < sol)
            sol = steps;
        return ;
    }
    for (i = 1; i <= 100; ++i)
        if (x <= F[i])
            break;
    if (x == F[i]) {
        if (steps + 1 < sol)
            sol = steps + 1;
        return ;
    }
    solve(x - F[i - 1], steps + 1);
    solve(F[i] - x, steps + 1);
}

int main() {
    int i, T;
    long long lim = 400000000000000000LL;
    F[0] = 0; F[1] = 1;
    for (i = 2; ; ++i) {
        F[i] = F[i - 1] + F[i - 2];
        if (F[i] > lim)
            break;
    }
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        sol = 1 << 30;
        solve(N, 0);
        cout << sol << "\n";
    }
    return 0;
}
