#include <cstdio>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

const int MaxN = 305;
const double oo = 1e11;

pii Points[MaxN];
int N, K, Inside[MaxN][MaxN];
double DP[2][MaxN], Sol;

inline double Area(pii p1, pii p2, pii p3) {
    return 0.5*abs(p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p3.x*p2.y - p2.x*p1.y - p1.x*p3.y);
}

inline int Sign(pii p1, pii p2, pii p3) {
    int sign = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y - p3.x*p2.y - p2.x*p1.y - p1.x*p3.y;
    if (sign == 0)
        return 0;
    return sign < 0 ? -1 : 1;
}

inline int InsideTriangle(int i, int j, int k) {
    pii T[3] = {make_pair(Points[i].y, i), make_pair(Points[j].y, j), make_pair(Points[k].y, k)};
    sort (T, T+3); i = T[0].y, j = T[1].y, k = T[2].y;
    int sign = Sign(Points[i], Points[j], Points[k]);
    return  sign*Inside[i][j] + sign*Inside[j][k] - sign*Inside[i][k] - (sign == -1);
}

void Preprocess() {
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; ++j)
            for (int k = i; k <= N && Points[k].y <= Points[j].y; ++k)
                Inside[i][j] += (Sign(Points[i], Points[k], Points[j]) == -1);
}

inline void InitDP() {
    for (int i = 0; i <= N; ++i)
        DP[0][i] = DP[1][i] = oo;
}

void BuildDP(int p1, int p2) {
    InitDP();
    for (int i = 1; i <= N; ++i) {
        if (i == p1 || i == p2)
            continue;
        int side = Sign(Points[p1], Points[i], Points[p2]) == -1 ? 0 : 1;
        int inside = InsideTriangle(p1, p2, i);
        DP[side][inside] = min(DP[side][inside], Area(Points[p1], Points[p2], Points[i]));
    }
    for (int inside = N-1; inside >= 0; --inside)
        DP[0][inside] = min(DP[0][inside], DP[0][inside+1]), DP[1][inside] = min(DP[1][inside], DP[1][inside+1]);
}

inline bool Compare(pii p1, pii p2) {
    return p1.y < p2.y;
}

void Solve() {
    sort(Points+1, Points+N+1, Compare);
    Preprocess();
    Sol = oo;
    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            BuildDP(i, j);
            for (int inside = 0; inside <= K; ++inside)
                Sol = min(Sol, DP[0][inside]+DP[1][K-inside]);
        }
    }
}

void Read() {
    freopen("popandai.in", "r", stdin);
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &Points[i].x, &Points[i].y);
}

void Print() {
    freopen("popandai.out", "w", stdout);
    printf("%.1lf\n", Sol);
}

int main() {
    Read();
    Solve();
    Print();
    return 0;
}

