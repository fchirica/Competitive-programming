#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if (t == 0) {
        cout << 0;
        return 0;
    }
    int border = 1, middle = 1;
    int res = 1;
    --t;
    for (int i = 2; i <= n; ++i) {
        middle = border;
        border = border * 2;
        if (t < middle)
            break;
        if (t < border) {
            res += i - 2;
            break;
        }
        t -= border;
        res += i;
    }
    cout << res;
}
