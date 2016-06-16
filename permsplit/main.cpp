#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("permsplit.in");
ofstream out ("permsplit.out");

const int MAXN = 1000010;

int V[MAXN], Sol[MAXN];

struct PII
{
    int first, second, dr, p;
} S[MAXN];

PII Unite (PII A, PII B)
{
    if (A.first > B.second)
        swap (A, B);

    if (B.first - A.second == 1){
        B.first = A.first;
        int dr = B.dr;
        B.dr = max (A.dr, B.dr);
        B.p = min (A.dr, dr);
        return B;
    }

    return {0, 0};
}

int main()
{
    int M, N, i, lv = 0;
    PII now;

    in >> N;
    for (i = 1; i <= N; i ++)
        in >> V[i];

    S[++ lv] = {V[1], V[1], 1, 1};

    for (i = 2; i <= N; i ++){
        now = {V[i], V[i], i, i};
        S[++ lv] = now;
        while (lv > 1){
            now = Unite (S[lv], S[lv - 1]);
            if (now.first == 0)
                break;

            Sol[++ Sol[0]] = now.p;
            S[-- lv] = now;
        }
    }

    if (!Sol[0] || lv != 1){
        out << -1;
        return 0;
    }

    for (i = Sol[0]; i; i --)
        out << Sol[i] << " ";

    return 0;
}

