#include <stdio.h>
#include <math.h>
#define INF ((1LL << 31) - 1)
#define eps 0.0000001

double dp[5][5][301][301];
int x[5][301], y[5][301];

inline double dist(int i1, int j1, int i2, int j2) {
    return sqrt((x[i1][j1] - x[i2][j2]) * (x[i1][j1] - x[i2][j2]) + (y[i1][j1] - y[i2][j2]) * (y[i1][j1] - y[i2][j2]));
}

int main() {
    freopen("afaceri2.in", "r", stdin);
    freopen("afaceri2.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 4; ++j)
            scanf("%d%d", &x[j][i], &y[j][i]);

    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            dp[i][j][1][2] = dist(i, 1, j, 2);

    for (int j = 3; j <= n; ++j) {
        for (int i = 1; i < j - 1; ++i)
            for (int choosei = 1; choosei <= 4; ++choosei)
                for (int choosej = 1; choosej <= 4; ++choosej) {
                    double best = INF;
                    for (int chooseprev = 1; chooseprev <= 4; ++chooseprev) {
                        double ret = dp[choosei][chooseprev][i][j - 1] + dist(chooseprev, j - 1, choosej, j);
                        if (ret < best)
                            best = ret;
                    }
                    dp[choosei][choosej][i][j] = best;
                }

        int i = j - 1;
        for (int choosei = 1; choosei <= 4; ++choosei)
            for (int choosej = 1; choosej <= 4; ++choosej) {
                double best = INF;
                for (int prev = 1; prev < i; ++prev)
                    for (int chooseprev = 1; chooseprev <= 4; ++chooseprev) {
                        double ret = dp[chooseprev][choosei][prev][i] + dist(chooseprev, prev, choosej, j);
                        if (ret < best)
                            best = ret;
                    }
                dp[choosei][choosej][i][j] = best;
            }
    }

    double best = INF;
    for (int choosei = 1; choosei <= 4; ++choosei)
        for (int choosen = 1; choosen <= 4; ++choosen)
            for (int i = 1; i < n; ++i) {
                double ret = dp[choosei][choosen][i][n] + dist(choosei, i, choosen, n);
                if (ret < best)
                    best = ret;
            }

    printf("%lf", best);
    return 0;
}
