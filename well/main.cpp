#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int x[1000100], y[1000100];
long long SP[1000100], left[1000100], right[1000100];

int N, ret;

long long getSum(int p, int q, int z) {
    return SP[q] - SP[p - 1] - 1LL * z * (q - p + 1) * (q - p + 2) / 2;
}

const int DIM = 8192;

char buff[DIM];
int poz = 0;
void read (long long &numar)
{
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar = numar*10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    }
}

void rev() {
    int st = 1, dr = N;
    while (st <= dr) {
        int aux = y[st];
        y[st] = y[dr];
        y[dr] = aux;
        ++st; --dr;
    }
}

int firstAvailable(int pos, int z) {
    //y[pos] <= (k - pos) * z
    int res = y[pos] / z;
    if (y[pos] % z)
        ++res;
    return res + pos;
}

void solve(long long who[], int z) {
    multiset <pair <int, int> > H;
    int pos = 0, i;
    for (i = 1; i <= N; ++i)
        SP[i] = SP[i - 1] + y[i];
    for (i = 1; i <= N; ++i) {
        while (!H.empty() && H.begin() -> first == i) {
            if (H.begin() -> second > pos)
                pos = H.begin() -> second;
            H.erase(H.begin());
        }
        H.insert(make_pair(firstAvailable(i, z), i));
        who[i] = 0;
        if (pos + 1 <= i - 1)
            who[i] = getSum(pos + 1, i - 1, z);
    }
}

bool can(int sol, long long M) {
    int i;
    for (i = 1; i <= N; ++i)
        y[i] = x[i];
    for (i = 1; i < N; ++i)
        if (y[i] + sol < y[i + 1]) {
            M = M - (y[i + 1] - y[i] - sol);
            y[i + 1] = y[i] + sol;
        }
    for (i = N; i > 1; --i)
        if (y[i] + sol < y[i - 1]) {
            M = M - (y[i - 1] - y[i] - sol);
            y[i - 1] = y[i] + sol;
        }
    if (M < 0)
        return 0;
    if (sol == 0) {
        for(i = 1; i <= N; ++i) {
            M = M - y[i];
            if (M < 0)
                return 0;
        }
        ret = 1;
        return 1;
    }
    solve(left, sol);
    rev();
    solve(right, sol);
    for (i = 1; i <= N; ++i)
        if (left[i] + right[N - i + 1] + x[i] <= M) {
            ret = i;
            return true;
        }
    return false;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    long long M, shit;
    read(shit); read(M); N = shit;
    int i;
    for (i = 1; i <= N; ++i)
        read(shit), x[i] = shit;
    int left = 0, right = 0;
    for (i = 1; i <= N; ++i)
        if (x[i] > right)
            right = x[i];
    int sol, sol2;
    while (left <= right) {
        int med = (1LL * left + right) / 2;
        if (can(med, M)) {
            sol = med;
            sol2 = ret;
            right = med - 1;
        }
        else
            left = med + 1;
    }

    printf("%d %d", sol2, sol);
    return 0;
}
