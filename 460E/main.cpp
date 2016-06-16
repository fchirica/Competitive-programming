#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

const int offset = 300;

int dp[9][2 * offset][2 * offset];
int bestY[33];
pair <int, int> prev[9][2 * offset][2 * offset];

int main() {
    int n, r;
    scanf("%d%d", &n, &r);

    memset(dp, -1, sizeof(dp));
    bestY[0] = r;
    for (int x = 1; x <= r; ++x) {
        bestY[x] = bestY[x - 1];
        while (x * x + bestY[x] * bestY[x] > r * r)
            --bestY[x];
    }

    dp[0][offset][offset] = 0;
    for (int i = 0; i < n; ++i)
        for (int sumX = -offset; sumX < offset; ++sumX)
            for (int sumY = -offset; sumY < offset; ++sumY)
                if (dp[i][sumX + offset][sumY + offset] != -1)
                    for (int nextX = -r; nextX <= r; ++nextX)
                        for (int nextY = -bestY[abs(nextX)]; nextY <= bestY[abs(nextX)]; nextY += 2 * bestY[abs(nextX)]) {
                            int nextValue = dp[i][sumX + offset][sumY + offset] + (n - 1) * nextX * nextX + (n - 1) * nextY * nextY - 2 * sumX * nextX - 2 * sumY * nextY;
                            int nextSumX = sumX + offset + nextX;
                            int nextSumY = sumY + offset + nextY;
                            if (dp[i + 1][nextSumX][nextSumY] < nextValue) {
                                dp[i + 1][nextSumX][nextSumY] = nextValue;
                                prev[i + 1][nextSumX][nextSumY] = make_pair(nextX, nextY);
                            }
                            if (nextY == 0)
                                break;
                        }

    int resx = 0, resy = 0;
    for (int x = -offset; x < offset; ++x)
        for (int y = -offset; y < offset; ++y)
            if (dp[n][x + offset][y + offset] > dp[n][resx][resy]) {
                resx = x + offset;
                resy = y + offset;
            }

    printf("%d\n", dp[n][resx][resy]);
    for (int step = n; step >= 1; --step) {
        int ret = resx;
        printf("%d %d\n", prev[step][resx][resy].first, prev[step][resx][resy].second);
        resx -= prev[step][resx][resy].first;
        resy -= prev[step][ret][resy].second;
    }

    return 0;
}
