#include <stdio.h>

int next[18][200010];
int dj[200010];

int father(int nod) {
    return dj[nod] = (nod == dj[nod] ? nod : father(dj[nod]));
}

void unite(int xx, int yy) {
    if (father(xx) != father(yy))
        dj[father(xx)] = father(yy);
}

inline int max(int A, int B) {
    return A > B ? A : B;
}

int main() {
    freopen("reborn.in", "r", stdin);
    freopen("reborn.out", "w", stdout);

    int N, M, Q;
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; ++i)
        next[0][i] = i;
    for (int i = 1; i <= M; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        next[0][xx] = max(next[0][xx], yy);
    }
    for (int i = 1; i <= N; ++i)
        next[0][i] = max(next[0][i], next[0][i - 1]);

    for (int i = 1; i <= N; ++i)
        dj[i] = i;
    for (int i = 1; i <= N; ++i)
        unite(i, next[0][i]);

    int maxPw;
    for (int pw = 1; (1 << pw) <= N; ++pw) {
        maxPw = pw;
        for (int i = 1; i <= N; ++i)
            next[pw][i] = next[pw - 1][next[pw - 1][i]];
    }

    for (int qry = 1; qry <= Q; ++qry) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        if (father(xx) != father(yy)) {
            printf("-1\n");
            continue;
        }
        if (xx == yy) {
            printf("0\n");
            continue;
        }
        if (xx > yy) {
            int tmp = xx;
            xx = yy;
            yy = tmp;
        }
        int pos = xx, res = 0;
        for (int pw = maxPw; pw >= 0; --pw) {
            int nextPos = next[pw][pos];
            if (nextPos < yy) {
                res += (1 << pw);
                pos = nextPos;
            }
        }
        printf("%d\n", res + 1);
    }

    return 0;
}
