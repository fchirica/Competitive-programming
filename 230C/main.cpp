#include <iostream>
#include <string.h>

using namespace std;

struct matrix {
    long long a[90][90];

    matrix() {
        memset(a, 0, sizeof(a));
    }
};

int cnt, C[45][45];
const int mod = 1000000007;

matrix inm(matrix A, matrix B) {
    matrix C;
    for (int i = 1; i <= cnt; ++i)
        for (int j = 1; j <= cnt; ++j)
            for (int k = 1; k <= cnt; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j];
                C.a[i][j] %= mod;
            }
    return C;
}

matrix pw(matrix A, long long times) {
    if (times == 1)
        return A;
    if (times % 2)
        return inm(A, pw(A, times - 1));
    return pw(inm(A, A), times / 2);
}

int line[100];
int two[100];


int nline[100];
void debug(matrix A, int times) {
    for (int i = 1; i <= times; ++i) {
        for (int j = 1; j <= cnt; ++j)
            cerr << line[j] << " ";
        cerr << "\n";
        for (int j = 1; j <= cnt; ++j)
            for (int k = 1; k <= cnt; ++k) {
                nline[j] += A.a[j][k] * line[k];
                nline[j] %= mod;
            }
        for (int j = 1; j <= cnt; ++j)
            line[j] = nline[j];
    }
}

int main() {
    long long N;
    int K;

    cin >> N >> K;
    if (N == 1) {
        cout << "1";
        return 0;
    }

    for (int i = 0; i <= K; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }

    two[0] = 1;
    for (int i = 1; i <= K; ++i)
        two[i] = two[i - 1] * 2 % mod;

    matrix A;

    cnt = 2 * K + 3;

    for (int i = 1; i <= K + 1; ++i)
        for (int j = 1; j <= i; ++j) {
            A.a[i][j] = C[i - 1][j - 1];
            A.a[i][j + K + 1] = 1LL * C[i - 1][j - 1] * two[i - j] % mod;
        }

    for (int i = K + 2; i <= 2 * K + 2; ++i)
        A.a[i][i - K - 1] = 1;
    A.a[cnt][cnt] = 1;
    A.a[cnt][K + 1] = 1;

    /*for (int i = 1; i <= cnt; ++i, cerr << "\n")
        for (int j = 1; j <= cnt; ++j)
            cerr << A.a[i][j] << " ";
    7*/

    matrix B = pw(A, N - 1);

    for (int i = 1; i <= K + 1; ++i)
        line[i] = 2 * two[i - 1] % mod;
    for (int i = K + 2; i <= 2 * K + 3; ++i)
        line[i] = 1;

    //debug(A, N - 1);

    int res = 0;
    for (int i = 1; i <= 2 * K + 3; ++i) {
        res += (B.a[2 * K + 3][i] * line[i]) % mod;
        res = res % mod;
    }

    cout << res;
    return 0;
}
