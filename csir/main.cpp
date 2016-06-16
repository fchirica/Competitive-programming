#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

char tmp[55555];
int mlc[55555];

int solve(string s) {
    int cntA = 0, cntB = 0;
    for (int i = 0; i < s.size(); ++i)
        cntA += (s[i] == 'A');
    cntB = s.size() - cntA;

    if (cntA < cntB) {
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == 'A')
                s[i] = 'B';
            else
                s[i] = 'A';
    }

    int start = -1;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'B') {
            start = i;
            break;
        }

    if (start == -1)
        return 1;
    string ss;
    for (int i = start + 1; i < start + 1 + s.size(); ++i)
        ss += s[i % s.size()];
    s = ss;

    int lo = 1 << 30, hi = 0, bucket = 0;
    mlc[0] = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == 'A')
            ++bucket;
        else {
            if (bucket < lo)
                lo = bucket;
            if (bucket > hi)
                hi = bucket;
            mlc[++mlc[0]] = bucket;
            bucket = 0;
        }

    if (hi - lo > 1)
        return 0;

    string nexts;
    for (int i = 1; i <= mlc[0]; ++i)
        if (mlc[i] == lo)
            nexts += "A";
        else
            nexts += "B";
    return solve(nexts);
}

int main() {
    freopen("csir.in", "r", stdin);
    freopen("csir.out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--) {
        gets(tmp);
        string s = string(tmp);
        printf("%d\n", solve(s));
    }

    return 0;
}
