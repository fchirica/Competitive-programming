#include <stdio.h>
#include <map>

using namespace std;

int N, K, T;
const long long INF = 1LL << 55;
map <int, long long> M;

int encode(int x[], int last) {
    int pw = 1, res = 0;
    for (int i = 0; i <= K; ++i) {
        res += pw * x[i];
        pw *= 21;
    }
    res += pw * last;
    return res;
}

void decode(int x[], int code, int &last) {
    for (int i = 0; i <= K; ++i) {
        x[i] = code % 21;
        code /= 21;
    }
    last = code;
}

long long solve(int code) {
    if (M.find(code) != M.end())
        return M[code];
    int last, x[6];
    decode(x, code, last);
    if (x[0] == N)
        return 1;

    long long res = 0;
    for (int i = 1; i <= K; ++i)
        if (x[i]) {
            ++x[i - 1]; --x[i];
            int newCode = encode(x, i - 1);
            if (i == last)
                res += x[i] * solve(newCode);
            else
                res += (x[i] + 1) * solve(newCode);
            if (res >= INF)
                return M[code] = INF;
            --x[i - 1]; ++x[i];
        }

    return M[code] = res;
}

int use[22], tmp[6];

int main() {
    freopen("nkperm.in", "r", stdin);
    freopen("nkperm.out", "w", stdout);

    scanf("%d%d%d", &N, &K, &T);
    while (T--) {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'A') {
            for (int i = 1; i <= N; ++i)
                use[i] = K;
            long long res = 1;
            int last = 0;
            for (int i = 1; i <= N * K; ++i) {
                int val;
                scanf("%d", &val);
                for (int j = 1; j < val; ++j)
                    if (j != last && use[j]) {
                        --use[j];
                        for (int k = 0; k <= K; ++k)
                            tmp[k] = 0;
                        for (int k = 1; k <= N; ++k)
                            ++tmp[use[k]];
                        res += solve(encode(tmp, use[j]));
                        ++use[j];
                    }
                --use[val];
                last = val;
            }
            printf("%lld\n", res);
        } else {
            long long pos;
            int last = 0;
            scanf("%lld", &pos);
            for (int i = 1; i <= N; ++i)
                use[i] = K;
            for (int i = 1; i <= N * K; ++i)
                for (int j = 1; j <= N; ++j) {
                    if (!use[j] || j == last)
                        continue;
                    --use[j];
                    for (int k = 0; k <= K; ++k)
                        tmp[k] = 0;
                    for (int k = 1; k <= N; ++k)
                        ++tmp[use[k]];
                    long long prefixCnt = solve(encode(tmp, use[j]));
                    if (prefixCnt < pos) {
                        pos -= prefixCnt;
                        ++use[j];
                    } else {
                        printf("%d ", j);
                        last = j;
                        break;
                    }
                }
            printf("\n");
        }
    }

    return 0;
}
