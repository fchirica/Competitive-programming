#include <stdio.h>
#include <algorithm>

using namespace std;

int vmax;
const int INF = (1 << 30);

struct interval {
    int x0, y0, x1, y1, sum;
} tree[4 * 100100 + 100];

int eval(int x, interval X) {
    if (x <= X.x0)
        return X.y0;
    if (x >= X.x1)
        return X.y1;
    return x + X.sum;
}

interval combine(interval A, interval B) {
    interval C;
    C.sum = A.sum + B.sum;
    C.y0 = eval(A.y0, B);
    C.y1 = eval(A.y1, B);

    if (B.x0 <= A.y0)
        C.x0 = A.x0;
    else if (B.x0 >= A.y1)
        C.x0 = vmax;
    else
        C.x0 = B.x0 - A.sum;

    if (B.x1 >= A.y1)
        C.x1 = A.x1;
    else if (B.x1 <= A.y0)
        C.x1 = 0;
    else
        C.x1 = B.x1 - A.sum;

    return C;
}

void update(int node, int left, int right, int leaf, int type) {
    if (left == right) {
        if (type == 1) {
            tree[node].x0 = 0;
            tree[node].y0 = 1;
            tree[node].x1 = vmax - 1;
            tree[node].y1 = vmax;
            tree[node].sum = 1;
        } else {
            tree[node].x0 = 1;
            tree[node].y0 = 0;
            tree[node].x1 = vmax;
            tree[node].y1 = vmax - 1;
            tree[node].sum = -1;
        }
        return ;
    }
    int med = (left + right) / 2;
    if (leaf <= med)
        update(2 * node, left, med, leaf, type);
    else
        update(2 * node + 1, med + 1, right, leaf, type);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

struct command {
    int v, idx, tt;
} com[100100];

inline bool comp(command A, command B) {
    return A.tt < B.tt;
}

int main() {
    int n, wantedv;
    scanf("%d %d %d\n", &n, &vmax, &wantedv);

    for (int i = 1; i <= 4 * n + 2; ++i)
        tree[i].x1 = tree[i].y1 = vmax;

    int last, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        char ch;
        int tt;
        scanf("%c %d\n", &ch, &tt);
        if (i == 1) {
            last = tt;
            continue;
        }
        com[++cnt].v = (ch == '+') ? 1 : -1;
        com[cnt].idx = i;
        com[cnt].tt = tt - last;
        last = tt;
    }

    n = cnt;
    sort(com + 1, com + n + 1, comp);
    com[n + 1].tt = INF;

    int bestTime = com[1].tt - 1, bestVolume = wantedv, i = 1;

    while (i <= n) {
        int firstTime = i;
        for (; com[i].tt == com[firstTime].tt; ++i)
            update(1, 1, n + 1, com[i].idx, com[i].v);
        if (tree[1].y0 <= wantedv && wantedv <= tree[1].y1) {
            bestTime = com[i].tt - 1;
            if (wantedv == tree[1].y0)
                bestVolume = tree[1].x0;
            else if (wantedv == tree[1].y1)
                bestVolume = vmax;
            else
                bestVolume = wantedv - tree[1].sum;
        }
    }

    if (bestTime == INF - 1)
        printf("infinity");
    else
        printf("%d %d", bestTime, bestVolume);

    return 0;
}
