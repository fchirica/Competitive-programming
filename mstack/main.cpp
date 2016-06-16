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

char x[10];
int half[1000100], st2[1000100], st3[1000100], Q[2000100];

int p = 999999, u = 999998;

void balance2() {
    if (st2[0])
        return ;
    int move = st3[0] / 2, tot = st3[0];
    chmax(move, 1);
    FOR(i, tot - move) {
        printf("move 3 1\n");
        half[++half[0]] = st3[st3[0]--];
    }
    FOR(i, move) {
        printf("move 3 2\n");
        st2[++st2[0]] = st3[st3[0]--];
    }
    FOR(i, tot - move) {
        printf("move 1 3\n");
        st3[++st3[0]] = half[half[0]--];
    }
}

void balance3() {
    if (st3[0])
        return ;
    int move = st2[0] / 2, tot = st2[0];
    chmax(move, 1);
    FOR(i, tot - move) {
        printf("move 2 1\n");
        half[++half[0]] = st2[st2[0]--];
    }
    FOR(i, move) {
        printf("move 2 3\n");
        st3[++st3[0]] = st2[st2[0]--];
    }
    FOR(i, tot - move) {
        printf("move 1 2\n");
        st2[++st2[0]] = half[half[0]--];
    }
}

void popFront(bool flag) {
    ++p;
    balance2();
    --st2[0];
    if (flag)
        printf("pop 2\n");
}

void pushFront(int val, bool flag) {
    Q[--p] = val;
    st2[++st2[0]] = val;
    if (flag)
        printf("push 2\n");
}

int front(bool flag) {
    if (flag) {
        balance2();
        printf("top 2\n");
    }
    return Q[p];
}

void popBack(bool flag) {
    --u;
    balance3();
    --st3[0];
    if (flag)
        printf("pop 3\n");
}

int back(bool flag) {
    if (flag) {
        balance3();
        printf("top 3\n");
    }
    return Q[u];
}

void pushBack(int val, bool flag) {
    Q[++u] = val;
    st3[++st3[0]] = val;
    if (flag)
        printf("push 3\n");
}

int cur;

void MPush() {
    ++cur;
    pushBack(cur, 1);
    int tot = u - p + 1;
    if (half[0] < tot / 2) {
        balance2();
        half[++half[0]] = st2[st2[0]--];
        printf("move 2 1\n");
    }
}

void MPop() {
    popBack(1);
    int tot = u - p + 1;
    if (half[0] > tot / 2) {
        int val = half[half[0] --];
        st2[++st2[0]] = val;
        printf("move 1 2\n");
    }
}

void MTop() {
    balance3();
    back(1);
}

void MMiddle() {
    balance2();
    front(1);
}

int main() {
    freopen("mstack.in", "r", stdin);
    freopen("mstack.out", "w", stdout);

    read(op); scanf("\n");
    FOR(i, op) {
        gets(x + 1);
        if (x[1] == 'p' && x[2] == 'u')
            MPush();
        if (x[1] == 'p' && x[2] == 'o')
            MPop();
        if (x[1] == 't')
            MTop();
        if (x[1] == 'm')
            MMiddle();
    }

    return 0;
}
