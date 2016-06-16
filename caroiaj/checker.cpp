#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int badHash[] = {4, 25386559, 812875250, 71021226, 688364213, 803600030, 579711485, 207150071, 578297283, 794908996, 296349325};

int x[312][312], res[666];

int main(int argc, char * argv[]){
    registerTestlibCmd(argc,argv);

    int n = inf.readInt(), sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            x[i][j] = inf.readInt();
            sum = (sum + x[i][j]) % 1000000007;
        }

    string myAns = ans.readString();
    string goodAns = "YES";
    for (int i = 0; i < 11; ++i)
        if (badHash[i] == sum)
            goodAns = "NO";
    if (myAns != goodAns) {
        quitf(_wa, "The answers don't match");
        return 0;
    }
    if (myAns == "NO") {
        quitf(_ok, "OK");
        return 0;
    }
    for (int i = 1; i <= 2 * n - 1; ++i)
        res[i] = ans.readInt();
    for (int i = 1; i <= 2 * n - 1; ++i)
        for (int j = 1; j <= 2 * n - 1; ++j)
            if (res[i] == res[j]) {
                quitf(_wa, "Two numbers are equal");
                return 0;
            }
    int pizda = 1;
    for (int i = n; i >= 1; --i) {
        bool fount = false;
        int ci = i, cj = 1;
        while (ci <= n && cj <= n) {
            if (x[ci][cj] == res[pizda])
                fount = true;
            ++ci; ++cj;
        }
        ++pizda;
        if (!fount)
            quitf(_wa, "A number does NOT exist on a diagonal");
    }
    for (int i = 2; i <= n; ++i) {
        bool fount = false;
        int ci = 1, cj = i;
        while (ci <= n && cj <= n) {
            if (x[ci][cj] == res[pizda])
                fount = true;
            ++ci; ++cj;
        }
        ++pizda;
        if (!fount)
            quitf(_wa, "A number does NOT exist on a diagonal");
    }
    quitf(_ok, "OK");
    return 0;
}
