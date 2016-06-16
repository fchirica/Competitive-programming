#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct event {
    int type, x, idx;
} E[500500 * 2];

set <int> active;

inline bool comp(event A, event B) {
    return A.x < B.x;
}

struct result {
    int first, second, sum;
} res[500500 * 2];


inline bool comp2(result A, result B) {
    if (A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

int singleRange[500500];

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        E[++cnt].type = 0; E[cnt].x = xx; E[cnt].idx = i;
        E[++cnt].type = 1; E[cnt].x = yy; E[cnt].idx = i;
    }

    sort(E + 1, E + cnt + 1, comp);

    int solCnt = 0;
    for (int i = 1; i <= cnt; ++i) {
        int j;
        if (active.size() == 1) {
            res[++solCnt].first = *active.begin();
            res[solCnt].second = -1;
            res[solCnt].sum = E[i].x - E[i - 1].x;
        } else if (active.size() == 2) {
            set <int> :: iterator it;
            ++solCnt;
            for (it = active.begin(); it != active.end(); ++it)
                if (res[solCnt].first == 0)
                    res[solCnt].first = *it;
                else
                    res[solCnt].second = *it;
            res[solCnt].sum = E[i].x - E[i - 1].x;
        }
        //cerr << res[solCnt].first << " " << res[solCnt].second << " " << res[solCnt].sum << "\n";
        for (j = i; E[j].x == E[i].x; ++j)
            if (E[j].type == 0)
                active.insert(E[j].idx);
            else
                active.erase(active.find(E[j].idx));
        i = j - 1;
    }

    for (int i = 1; i <= solCnt; ++i)
        if (res[i].second == -1)
            singleRange[res[i].first] += res[i].sum;

    sort(res + 1, res + solCnt + 1, comp2);
    int sum = res[1].sum, best = 0;
    for (int i = 1; i <= solCnt; ++i)
        if (res[i].second != -1 && res[i].first == res[i + 1].first && res[i].second == res[i + 1].second)
            sum += res[i + 1].sum;
        else {
            if (res[i].second == -1) {
                sum = res[i + 1].sum;
                continue;
            }
            sum += singleRange[res[i].first] + singleRange[res[i].second];
            if (best < sum)
                best = sum;
            sum = res[i + 1].sum;
        }

    int singleSum = 0;
    for (int i = 1; i <= 2; ++i) {
        int mx = -1, idx = -1;
        for (int j = 1; j <= n; ++j)
            if (singleRange[j] > mx) {
                mx = singleRange[j];
                idx = j;
            }
        if (mx == -1)
            break;
        singleSum += mx;
        singleRange[idx] = 0;
    }

    if (best < singleSum)
        best = singleSum;

    printf("%d", best);
    return 0;
}
