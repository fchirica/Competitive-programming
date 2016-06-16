/* geometrie jegoasa si imputita
   #MLC */

#include <bits/stdc++.h>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

const int kNMax = 810;
const double kEps = 0.0000001;

point x[kNMax];
vector <int> bucket[kNMax];
int sorted_x[kNMax], bucket_x[kNMax];

struct line {
    int A, B;
    long long C;
};

line L[kNMax];

double middleX;

inline bool comp(int A, int B) {
    double y1 = ((double) -L[A].C - L[A].A * middleX) / (double) L[A].B;
    double y2 = ((double) -L[B].C - L[B].A * middleX) / (double) L[B].B;
    return y1 < y2 - kEps;
}

bool tryIt(int myBucket, int qx, int qy) {
    int st = 0, dr = bucket[myBucket].size() - 1;
    int ans = 0;
    while (st <= dr) {
        int med = (st + dr) / 2, val;
        int myLine = bucket[myBucket][med];
        double y1 = ((double) -L[myLine].C - L[myLine].A * qx) / (double) L[myLine].B;
        if (fabs(y1 - qy) <= kEps)
            val = 0;
        else if (y1 < qy - kEps)
            val = -1;
        else val = 1;
        if (val == 0) {
            ans = 1;
            break;
        }
        if (val < 0)
            st = med + 1;
        else {
            dr = med - 1;
            ans = med;
        }
    }
    return ans % 2;
}

int main() {
    freopen("poligon.in", "r", stdin);
    freopen("poligon.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i].x, &x[i].y);
    x[n + 1] = x[1];

    for (int i = 1; i <= n; ++i)
        sorted_x[i] = x[i].x;
    sort(sorted_x + 1, sorted_x + n + 1);
    int cntBucket = 0;
    bucket_x[++cntBucket] = sorted_x[1];
    for (int i = 2; i <= n; ++i)
        if (sorted_x[i] != sorted_x[i - 1])
            bucket_x[++cntBucket] = sorted_x[i];
    for (int i = 1; i <= n; ++i) {
        L[i].A = x[i].y - x[i + 1].y;
        L[i].B = x[i + 1].x - x[i].x;
        L[i].C = (long long)x[i].x * x[i + 1].y - (long long) x[i].y * x[i + 1].x;
    }

    for (int i = 1; i <= cntBucket; ++i)
        for (int j = 1; j <= n; ++j)
            if (min(x[j].x, x[j + 1].x) <= bucket_x[i] && max(x[j].x, x[j + 1].x) > bucket_x[i])
                bucket[i].push_back(j);

    for (int i = 1; i <= cntBucket; ++i) {
        middleX = (bucket_x[i] + bucket_x[i + 1]) * 0.5;
        sort(bucket[i].begin(), bucket[i].end(), comp);
    }

    int res = 0;
    while (m--) {
        int qx, qy;
        scanf("%d%d", &qx, &qy);
        int st = 1, dr = cntBucket, myBucket = -1;
        while (st <= dr) {
            int med = (st + dr) / 2;
            if (bucket_x[med] <= qx) {
                myBucket = med;
                st = med + 1;
            } else
                dr = med - 1;
        }
        if (myBucket == -1)
            continue;

        int foo = tryIt(myBucket, qx, qy);
        res += foo;
        if (foo == 1)
            continue;
        if (bucket_x[myBucket] == qx && myBucket > 1)
            res += tryIt(myBucket - 1, qx, qy);
    }

    printf("%d", res);
    return 0;
}
