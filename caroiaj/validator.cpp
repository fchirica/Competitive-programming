#include"testlib.h"

int main(){
    registerValidation();

    int n = inf.readInt(2, 100000);
    inf.readSpace();
    int q = inf.readInt(1, 100000);
    inf.readEoln();

    for (int i = 1; i <= n; ++i) {
        inf.readInt(1, 100000);
        if (i == n)
            inf.readEoln();
        else
            inf.readSpace();
    }

    while (q--) {
        inf.readInt(1, 1000000000);
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}

