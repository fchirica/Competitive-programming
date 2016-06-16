#include <fstream>

using namespace std;

int main() {
    ifstream fin("avarcolaci.in");
    ofstream fout("avarcolaci.out");

    int n, x;
    fin >> n;

    int best, freq = 1;
    fin >> x;
    best = x;
    for (int i = 2; i <= n; ++i) {
        fin >> x;
        if (x == best)
            ++freq;
        else {
            --freq;
            if (freq == 0) {
                best = x;
                freq = 1;
            }
        }
    }

    fin.close();
    ifstream fin2("avarcolaci.in");

    fin2 >> n;

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        fin2 >> x;
        if (x == best)
            ++cnt;
    }
    if (cnt >= n / 2 + 1)
        fout << best << " " << cnt;
    else
        fout << "-1";

    fin2.close();
    fout.close();

    return 0;
}
