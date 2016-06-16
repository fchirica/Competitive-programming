#include <stdio.h>
#include <algorithm>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

point x[15100];
int tree[60000 * 4 + 100], lazy[60000 * 4 + 100];

void update(int nod, int left, int right, int wleft, int wright, int am) {
    if (wleft <= left && right <= wright) {
        lazy[nod] += am;
        return ;
    }
    if (left == right) {
        tree[nod] = tree[nod] + lazy[nod] + am;
        return ;
    }
    lazy[2 * nod] += lazy[nod];
    lazy[2 * nod + 1] += lazy[nod];
    lazy[nod] = 0;
    int med = (left + right) / 2;
    if (wleft <= med)
        update(2 * nod, left, med, wleft, wright, am);
    if (med < wright)
        update(2 * nod + 1, med + 1, right, wleft, wright, am);
    tree[nod] = max(tree[2 * nod] + lazy[2 * nod], tree[2 * nod + 1] + lazy[2 * nod + 1]);
}

int main() {
    int s, w, n;
    scanf("%d%d%d", &s, &w, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].y += 30000;
    }
    sort(x + 1, x + n + 1);
    int idx = 1, res = 0;
    for (int i = 1; i <= n; ++i) {
        while (x[i].x - x[idx].x > s && idx <= i) {
            update(1, 0, 60000, x[idx].y - w, x[idx].y, -1);
            ++idx;
        }
        update(1, 0, 60000, x[i].y - w, x[i].y, 1);
        if (tree[1] > res)
            res = tree[1];
    }

    printf("%d", res);
    return 0;
}
