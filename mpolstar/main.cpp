#include <stdio.h>
#include <algorithm>
#define point pair <double, double>
#define x first
#define y second

using namespace std;

inline double ccw(point A, point B, point C) {
    return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    return 0;
}
