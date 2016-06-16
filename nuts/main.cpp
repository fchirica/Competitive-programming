#include <stdio.h>
#include <map>
#define nuts pair <int, int>
#define x first
#define y second

using namespace std;


map <nuts, bool> M;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int right(int dir) {
    return (dir + 1) % 4;
}

int left(int dir) {
    return (dir - 1 + 4) % 4;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        nuts tmp;
        tmp.x = xx; tmp.y = yy;
        M[tmp] = 1;
    }

    nuts A;
    A.x = A.y = 0;
    int d = 0;

    int iter;
    scanf("%d", &iter);
    for (int i = 1; i < iter; ++i) {
        if (M[A]) {
            M[A] = 0;
            d = right(d);
        } else {
            M[A] = 1;
            d = left(d);
        }
        A.x += dx[d]; A.y += dy[d];
    }

    printf("%d", (int)M.size());
    return 0;
}
