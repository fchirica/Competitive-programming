#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string cr2, pt2;

int main() {
    ifstream fin("craciun.out");

    int cr1, pt1;
    char ch;
    fin >> cr1 >> ch >> cr2;
    fin.close();

    ifstream fin2("petcu.out");
    fin2 >> pt1 >> ch >> pt2;

    if (cr1 == pt1 && cr2 == pt2)
        cout << "Match";
    else
    if (cr1 == -1 && cr1 == pt1)
        cout << "Match";
    else {
        if (cr1 == pt1)
            cout << "A doua linie diferita";
        else
            cout << "Prima linie diferita";
    }

    return 0;
}
