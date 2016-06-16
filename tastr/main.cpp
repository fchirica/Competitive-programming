#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, a, b) for(int i = a; i >= b; --i)
#define FOR(i, n) REP(i, 1, n)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define read(n) int (n); scanf("%d", &(n))
#define read2(n, m) int (n), (m); scanf("%d %d", &(n), &(m))
#define read3(n, m, k) int (n), (m), (k); scanf("%d %d %d", &(n), &(m), &(k))
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

char x[2 * 200200];
int ord[200200], SA[20][2 * 200200];
int pw;

ll K[200200];
struct compll { bool operator()(int i, int j) const { return K[i]<K[j]; }};

void suffixArrays(int n)
{
    FOR(i,n) ord[i] = i;
    FOR(i,2*n) SA[0][i]=0;
    FOR(i,n) SA[0][i]=x[i]+1;
    for (pw = 1; (1 << pw) < 2*n; ++pw)
    {
        FOR(i,2*n) SA[pw][i]=0;
        int power=(1<<(pw-1));
        FOR(i,n) K[i]=(ll)SA[pw-1][i]*max(n+1,300)+SA[pw-1][i+power];
        sort(ord+1,ord+n+1,compll());
        int k=1;
        FOR(i,n)
        {
            if (i==1 || K[ord[i]]==K[ord[i-1]]) SA[pw][ord[i]]=k;
            else SA[pw][ord[i]]=++k;
        }
    }
    pw--;

}

inline bool comp2(int A, int B)
{
    return SA[pw][A] < SA[pw][B];
}

int nxt[200200];

ll suffixSums(int n)
{
    ll sum = 0;
    FOR(i, n) ord[SA[pw][i]]=i;
    ord[n + 1] = -1;
    FOR(i, n)
        nxt[ord[i]] = ord[i + 1];
    int curPref = 0;
    FOR(i, n)
    {
        if (nxt[i] == -1)
            continue;
        while (1)
            if (curPref > 0 && x[curPref + i - 1] != x[curPref + nxt[i] - 1]) {
                --curPref;
                break;
            } else
                ++curPref;
        sum += curPref;
        --curPref;
        chmax(curPref, 0);
    }
    return sum;
}

char A[200200], B[200200];

int main() {
    gets(A + 1); gets(B + 1);
    int N = strlen(A + 1); int M = strlen(B + 1);

    memcpy(x, A, sizeof(A));
    suffixArrays(N);
    ll distinctA = 1LL * N * (N + 1) / 2 - suffixSums(N);

    memcpy(x, B, sizeof(B));
    suffixArrays(M);
    ll distinctB = 1LL * M * (M + 1) / 2 - suffixSums(M);

    memcpy(x, A, sizeof(A));
    x[N + 1] = ' ';
    for (int i = 1; i <= M; ++i)
        x[N + i + 1] = B[i];
    ll reunion = 1LL * (N + M + 1) * (N + M + 2) / 2 - (1LL * N + 1) * (M + 1);
    suffixArrays(N + M + 1);
    reunion -= suffixSums(N + M + 1);

    printf("%lld", 2 * reunion - distinctA - distinctB);
    return 0;
}

