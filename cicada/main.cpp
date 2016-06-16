#include <fstream>

using namespace std;

int x[20];

int main() {
    ifstream fin("cicada.in");
    ofstream fout("cicada.out");

    int N, tmp;
    fin >> N; tmp = N;

    int d;
    for (d = 2; 1LL * d * d <= N; ++d) {
        bool prime = false;
        while (N % d == 0) {
            prime = true;
            N = N / d;
        }
        if (prime)
            x[++x[0]] = d;
    }
    if (N > 1)
        x[++x[0]] = N;
    N = tmp;

    int mask;
    long long sol = 0;
    for (mask = 1; mask < (1 << x[0]); ++mask) {
        int b, sgn = -1;
        long long num = 1;
        for (b = 0; b < x[0]; ++b)
            if (mask & (1 << b)) {
                num = num * x[b + 1];
                if (num > N)
                    break;
                sgn = -sgn;
            }

        long long gauss = 1LL * (N / num) * (N / num + 1) / 2;
        sol += num * sgn * gauss;
    }

    fout << sol - N;
    return 0;
}
