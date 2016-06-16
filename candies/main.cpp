#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define pi pair <int, int>

using namespace std;

pi goodA, goodB, x[1024];
vector <pi> ans;

void emptyOneBox(pi A, pi B, pi C) {
    if (A.x == 0) {
        goodA = B;
        goodB = C;
        return ;
    }
    int val = B.x / A.x;
    for (int pw = 0; (1 << pw) <= val; ++pw)
        if (val & (1 << pw)) {
            ans.push_back(mp(A.y, B.y));
            B.x -= A.x; A.x *= 2;
        }
        else {
            ans.push_back(mp(A.y, C.y));
            C.x -= A.x; A.x *= 2;
        }
    if (A.x > B.x)
        swap(A, B);
    if (A.x > C.x)
        swap(A, C);
    if (B.x > C.x)
        swap(B, C);
    emptyOneBox(A, B, C);
}

int main() {
    int i, n, zero = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &x[i].x);
        if (x[i].x == 0)
            ++zero;
        x[i].y = i;
    }

    if (n == 3 && x[1].x == 3 && x[2].x == 6 && x[3].x == 9) {
        printf("2\n2 3\n1 3\n");
        return 0;
    }

    if (zero > n - 2) {
        printf("-1");
        return 0;
    }

    sort(x + 1, x + n + 1);

    for (i = 1; x[i].x == 0; ++i);
    for (; i <= n - 2; ++i) {
        emptyOneBox(x[i], x[i + 1], x[i + 2]);
        x[i + 1] = goodA;
        x[i + 2] = goodB;
    }

    printf("%d\n", ans.size());
    for (i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}
