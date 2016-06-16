#include <stdio.h>
#include <vector>

using namespace std;

bool can[3][7][16001];
vector <int> G[16001];
bool vis[16001];

int getBit(int X, int b) {
    if (X & (1 << b))
        return 1;
    return 0;
}

int split(int mask1, int mask2, int supply) {
    int tmp[4];
    for (int i = 0; i < 3; ++i)
        tmp[i] = getBit(mask1, i) + getBit(mask2, i);
    ++tmp[supply];
    bool flag = true;
    while (flag) {
        for (int i = 0; i < 3; ++i)
            if (tmp[i] == 0)
                flag = 0;
        if (flag)
            for (int i = 0; i < 3; ++i)
                --tmp[i];
        }
    int mask = 0;
    for (int i = 2; i >= 0; --i) {
        if (!(0 <= tmp[i] && tmp[i] <= 1))
            return -1;
        mask = mask * 2 + tmp[i];
    }
    return mask;
}

void solve(int nod) {
    int sons[3];
    sons[0] = 0;
    vis[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis[*it])
            sons[++sons[0]] = *it;
    if (sons[0] == 0) {
        can[0][1 << 0][nod] = 1;
        can[1][1 << 1][nod] = 1;
        can[2][1 << 2][nod] = 1;
    }
    if (sons[0] == 1) {
        solve(sons[1]);
        for (int sonc = 0; sonc <= 2; ++sonc)
            for (int sonmask = 0; sonmask < 7; ++sonmask)
                for (int c = 0; c <= 2; ++c)
                    if (c != sonc && (sonmask & (1 << c)) == 0) {
                        int newMask = sonmask ^ (1 << c);
                        if (newMask == 7)
                            newMask = 0;
                        if (can[sonc][sonmask][sons[1]])
                            can[c][newMask][nod] = 1;
                    }
    }
    if (sons[0] == 2) {
        solve(sons[1]);
        solve(sons[2]);
        for (int c1 = 0; c1 <= 2; ++c1)
            for (int c2 = 0; c2 <= 2; ++c2)
                if (c1 != c2)
                    for (int mask1 = 0; mask1 < 7; ++mask1)
                        if (can[c1][mask1][sons[1]])
                            for (int mask2 = 0; mask2 < 7; ++mask2)
                                if (can[c2][mask2][sons[2]]) {
                                    int newMask = split(mask1, mask2, c1 ^ c2 ^ 3);
                                    if (newMask != -1)
                                        can[c1 ^ c2 ^ 3][newMask][nod] = 1;
                                }
    }
}

int res[16001];
bool vis2[16001];

void afis(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d ", res[i]);
}

void recon(int c, int mask, int nod) {
    int sons[3];
    sons[0] = 0;
    vis2[nod] = 1;
    vector <int> :: iterator it;
    for (it = G[nod].begin(); it != G[nod].end(); ++it)
        if (!vis2[*it])
            sons[++sons[0]] = *it;
    res[nod] = c + 1;
    if (sons[0] == 1) {
        int want = mask;
        if (!want)
            want = 7;
        want ^= (1 << c);
        for (int prevc = 0; prevc <= 2; ++prevc)
            if (can[prevc][want][sons[1]]) {
                recon(prevc, want, sons[1]);
                return ;
            }
    }
    if (sons[0] == 2) {
        for (int c1 = 0; c1 <= 2; ++c1)
            if (c1 != c)
                for (int mask1 = 0; mask1 < 7; ++mask1)
                    if (can[c1][mask1][sons[1]])
                        for (int c2 = 0; c2 <= 2; ++c2)
                            if (c2 != c && c2 != c1)
                                for (int mask2 = 0; mask2 < 7; ++mask2)
                                    if (can[c2][mask2][sons[2]]) {
                                        int newMask = split(mask1, mask2, c);
                                        if (newMask == mask) {
                                            recon(c1, mask1, sons[1]);
                                            recon(c2, mask2, sons[2]);
                                            return ;
                                        }
                                    }
    }
}

int main() {
    freopen("comp.in", "r", stdin);
    freopen("comp.out", "w", stdout);

    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        //G[xx].push_back(yy);
        G[yy].push_back(xx);
    }

    solve(1);
    if (N % 3 == 0) {
    for (int c = 0; c <= 2; ++c)
        if (can[c][0][1]) {
            recon(c, 0, 1);
            afis(N);
            return 0;
        }
    }
    for (int c = 0; c <= 2; ++c)
        for (int mask = 1; mask < 7; ++mask)
            if (can[c][mask][1]) {
                recon(c, mask, 1);
                afis(N);
                return 0;
            }

    return 0;
}
