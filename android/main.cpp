#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;
const int MAX_N = 25005;
const int MAX_K = 230;

int k, n, sums[MAX_N];
bool solution;
int a[MAX_K];

inline void get_solution(int index) {
    if((sums[1] + sums[2] - sums[index]) & 1) {
        solution = false;
        return;
    }
    a[1] = (sums[1] + sums[2] - sums[index]) / 2;
    for(int i = 2; i <= index; ++ i) {
        a[i] = sums[i - 1] - a[1];
    }
    multiset<int> left(sums + 1, sums + n + 1);
    for(int i = 1; i <= index; ++ i) {
        for(int j = i + 1; j <= index; ++ j) {
            if(!left.count(a[i] + a[j])) {
                solution = false;
                return;
            }
            left.erase(left.lower_bound(a[i] + a[j]));
        }
    }
    for(int i = index + 1; i <= k; ++ i) {
        a[i] = (*left.begin()) - a[1];
        for(int j = 1; j < i; ++ j) {
            if(!left.count(a[i] + a[j])) {
                solution = false;
                return;
            }
            left.erase(left.lower_bound(a[i] + a[j]));
        }
    }
    solution = true;
}

int main() {
    ifstream fin("sume.in");
    ofstream fout("sume.out");
    fin >> n;
    for(k = 1; k * (k - 1) / 2 < n; ++ k);
    if(k * (k - 1) / 2 != n) {
        fout << "-1\n";
        return 0;
    }
    for(int i = 1; i <= n; ++ i) {
        fin >> sums[i];
    }
    sort(sums + 1, sums + n + 1);
    for(int i = 3; i <= k; ++ i) {
        get_solution(i);
        if(solution) {
            fout << k << "\n";
            for(int j = 1; j <= k; ++ j) {
                fout << a[j] << (j == k ? '\n' : ' ');
            }
            return 0;
        }
    }
    fout << "-1\n";
    return 0;
}
