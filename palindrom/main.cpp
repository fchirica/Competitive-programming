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

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz size
#define DBG(X) cerr << X << "\n";

using namespace std;

char S[20001], x[20001];
int pref[20001];

int main() {
    gets(S + 1);
    int n = strlen(S + 1), N = 0;

    for (int i = n; i >= 1; --i)
        x[++N] = S[i];
    x[++N] = '#';
    for (int i = 1; i <= n; ++i) {
        x[++N] = S[i];
        printf("%c", x[N]);
    }

    for (int i = 2; i <= N; ++i) {
        int pf = pref[i - 1];
        while (1) {
            if (x[pf + 1] == x[i]) {
                pref[i] = pf + 1;
                break;
            }
            if (pf == 0)
                break;
            else
                pf = pref[pf];
        }
    }

    int endingPal = pref[N];
    if (endingPal == n)
        endingPal = pref[endingPal];
    for (int i = n - endingPal; i >= 1; --i)
        printf("%c", S[i]);
    return 0;
}
