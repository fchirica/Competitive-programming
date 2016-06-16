#include <fstream>

using namespace std;

int cnt[10100];

int main() {
    ifstream fin("matrix.in");
    ofstream fout("matrix.out");

    int i, N, M;
    fin >> N >> M;
    for (i = 1; i <= M; ++i) {
        int x, y;
        fin >> x >> y;
        ++cnt[x]; ++cnt[y];
    }
    long long res = 0;
    for (i = 1; i <= N; ++i)
        res += cnt[i] * cnt[i];
    fout << res;
    return 0;
}

