#include <fstream>

using namespace std;

long long pula[2222], pizda[2222];
long long x[1000100];

long long amin[4 * 1000100], amax[4 * 1000100];

long long min(long long A, long long B) {
    return A < B ? A : B;
}

long long max(long long A, long long B) {
    return A > B ? A : B;
}

void build(int nod, int st, int dr) {
    if (st == dr) {
        amin[nod] = amax[nod] = x[st];
        return ;
    }

    int m = (st + dr) / 2;

    build(2 * nod, st, m);
    build(2 * nod + 1, m + 1, dr);

    amin[nod] = min(amin[2 * nod], amin[2 * nod + 1]);
    amax[nod] = max(amax[2 * nod], amax[2 * nod + 1]);
}

long long myMin, myMax;

void mlc() {
    myMin = 1LL << 60;
    myMax = -1;
}

void query(int nod, int st, int dr, int qst, int qdr) {
    if (qst <= st && dr <= qdr) {
        myMin = min(myMin, amin[nod]);
        myMax = max(myMax, amax[nod]);
        return ;
    }
    int m = (st + dr) / 2;
    if (qst <= m)
        query(2 * nod, st, m, qst, qdr);
    if (m < qdr)
        query(2 * nod + 1, m + 1, dr, qst, qdr);
}

bool can(int n, int k, long long val) {
    int left = 1, cnt = 0;
    while (left <= n) {
        ++cnt;
        if (cnt > k)
            return 0;

        int st = left, dr = n, ret = -1;
        while (st <= dr) {
            int m = (st + dr) / 2;
            mlc();
            query(1, 1, n, left, m);
            if (myMax - myMin <= val) {
                ret = m;
                st = m + 1;
            } else
                dr = m - 1;
        }
        if (ret == -1)
            return 0;
        left = ret + 1;
    }
    return 1;
}

int main() {
    ifstream fin("ksecv.in");
    ofstream fout("ksecv.out");

    int n, k, m;
    fin >> n >> k >> m;
    for (int i = 0; i < m; ++i)
        fin >> pula[i];
    for (int i = 0; i < m; ++i)
        fin >> pizda[i];

    for (int i = 0; i < n; ++i)
        x[i + 1] = pula[i % m] xor pizda[i / m];

    build(1, 1, n);

    long long _min = x[1], _max = x[1];
    for (int i = 1; i <= n; ++i) {
        _min = min(_min, x[i]);
        _max = max(_max, x[i]);
    }

    long long st = 0, dr = _max - _min, ret;
    while (st <= dr) {
        long long med = (st + dr) / 2;
        if (can(n, k, med)) {
            ret = med;
            dr = med - 1;
        } else
            st = med + 1;
    }

    fout << (ret + 1) / 2;
    return 0;
}
