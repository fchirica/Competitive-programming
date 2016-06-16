#include <bits/stdc++.h>

using namespace std;

char nums[3][16666];
int len[3];
vector <pair <int, int> > G[16666 * 6];
int dst[16666 * 6];
set <pair <int, int> > H;

int lensum;

inline int getVertex(int val) {
    return val + lensum;
}

bool vis[16666 * 6];
int limi, lims;

void draw_edges(int nod) {
    if (vis[nod] || nod == 0)
        return ;

    vis[nod] = 1;
    limi = min(limi, nod);
    lims = max(lims, nod);
    for (int sgn = -1; sgn <= 1; sgn += 2)
        for (int i = 0; i < 3; ++i) {
            int newNode = nod + sgn * len[i];
            if (newNode >= 0 && newNode <= 2 * lensum) {
                G[nod].push_back(make_pair(newNode, len[i]));
                draw_edges(newNode);
            }
        }
}

int main() {
    freopen("base3.in", "r", stdin);
    freopen("base3.out", "w", stdout);

    gets(nums[0] + 1);
    gets(nums[1] + 1);
    gets(nums[2] + 1);
    len[0] = strlen(nums[0] + 1);
    len[1] = strlen(nums[1] + 1);
    len[2] = strlen(nums[2] + 1);
    lensum = len[0] + len[1] + len[2];

    int source = -lensum - 1;
    ++lensum;
    limi = lims = getVertex(source);

    int sink = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= len[i]; ++j)
            if (nums[i][j] == '1') {
                G[getVertex(source)].push_back(make_pair(getVertex(j - 1 - (len[i] - j)), len[i]));
                draw_edges(getVertex(j - 1 - (len[i] - j)));
            }

    memset(vis, 0, sizeof(vis));
    for (int i = limi; i <= lims; ++i)
        dst[i] = 1 << 29;
    dst[getVertex(source)] = 0;
    H.insert(make_pair(0, getVertex(source)));
    while (!H.empty()) {
        int nod = (*H.begin()).second;
        H.erase(H.begin());
        if (vis[nod])
            continue;
        vis[nod] = 1;

        vector <pair <int, int> > :: iterator it;
        for (it = G[nod].begin(); it != G[nod].end(); ++it)
            if (dst[it -> first] > dst[nod] + it -> second) {
                dst[it -> first] = dst[nod] + it -> second;
                H.insert(make_pair(dst[it -> first], it -> first));
            }
    }

    printf("%d", dst[getVertex(sink)] != (1 << 29) ? dst[getVertex(sink)] : 0);
    return 0;
}
