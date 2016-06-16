#include <bits/stdc++.h>

using namespace std;

int x[1000100], rez[1000100], val[1000100];

int main() {
    ifstream fin("xspe.in");
    ofstream fout("xspe.out");

    int n;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> x[i];

    int len = 0;
    for (int i = n; i >= 1; --i) {
        while (len > 0 && x[i] <= val[len])
            --len;
        rez[i] = x[i];
        if (len > 0)
            rez[i] += val[len];
        ++len;
        val[len] = x[i];
    }
    for (int i = 1; i <= n; ++i)
        fout << rez[i] << " ";
    return 0;
}
