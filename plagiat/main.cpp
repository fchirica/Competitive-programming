#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

struct point {
    int x, y;
} x[444];

inline bool comp(point A, point B) {
    if (A.x == B.x)
        return A.y < B.y;
    return A.x < B.x;
}

bool exist(int st, int dr, point X) {
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (x[med].x == X.x && x[med].y == X.y)
            return 1;
        if (comp(x[med], X))
            st = med + 1;
        else
            dr = med - 1;
    }
    return 0;
}

void bulaneste(int N) {
    map <pair <int, int>, bool> M;
    int cnt = 0;
    for (int i = 1; i <= N && cnt <= 3; ++i)
        for (int j = 1; j <= N && cnt <= 3; ++j)
            if (i != j) {
                pair <int, int> tmp;
                tmp.first = x[i].x - x[j].x;
                tmp.second = x[i].y - x[j].y;
                if (M[tmp] == 0)
                    M[tmp] = 1;
                else
                    ++cnt;
            }
    printf("%s\n", cnt >= 3 ? "DA" : "NU");
}

int main() {
    freopen("plagiat.in", "r", stdin);
    freopen("plagiat.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d%d", &x[i].x, &x[i].y);
        if (N > 100) {
            bulaneste(N);
            continue;
        }
        sort(x + 1, x + N + 1, comp);
        bool solution = false;
        for (int i = 1; i <= N && !solution; ++i)
            for (int j = i + 1; j <= N && !solution; ++j) {
                int dx = x[i].x - x[j].x;
                int dy = x[i].y - x[j].y;
                int cnt = 0;
                for (int k = j + 1; k <= N && cnt <= 2; ++k) {
                    point tmp;
                    tmp.x = x[k].x + dx;
                    tmp.y = x[k].y + dy;
                    if (exist(1, N, tmp))
                        ++cnt;
                }
                if (cnt >= 2)
                    solution = true;
            }
        printf("%s\n", solution ? "DA" : "NU");
    }

    return 0;
}
