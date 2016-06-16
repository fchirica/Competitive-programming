#include <bits/stdc++.h>

using namespace std;

char s[5];

int main() {
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    cin >> s;
    int minute = (s[3] - '0') * 10 + s[4] - '0';
    int ore = (s[0] - '0') * 10 + s[1] - '0';
    ore -= 5;
    minute += ore * 60;
    const int lastArrive = 1139;
    double atob_start = minute + 0.0001;

    return 0;
}
