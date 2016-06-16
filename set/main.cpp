#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

struct comp {
    inline bool operator () (int A, int B) {
        return A > B;
    }
};

set <int, comp> S;

int main() {
    S.insert(1);
    S.insert(2);
    S.insert(3);
    S.erase(S.find(3));

    for (set <int> :: iterator it = S.begin(); it != S.end(); ++it) {
        cout << *it;
    }

    return 0;
}
