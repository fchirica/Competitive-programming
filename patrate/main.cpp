#include <bits/stdc++.h>
#define point pair <int, int>
#define x first
#define y second

using namespace std;

const int kNMax = 50100;
const int kInf = 100000;

struct sq {
    point low, up;

    sq() {

    }

    sq (point X, point Y) {
        low = X;
        up = Y;
    }
};

class points_set {
  public:
    point box_low, box_up;
    void addPoint(point X) {
        m_points.push_back(X);
        active[m_points.size() - 1] = 1;
    }
    void killPoints(sq X) {
        for (int i = 0; i < m_points.size(); ++i)
            if (pointInSquare(m_points[i], X))
                active[i] = 0;
    }
    bool coveredByTwoSquares(sq A, sq B) {
        for (int i = 0; i < m_points.size(); ++i)
            if (active[i] && !pointInSquare(m_points[i], A) && !pointInSquare(m_points[i], B))
                return 0;
        return 1;
    }
    void reset() {
        for (int i = 0; i < m_points.size(); ++i)
            active[i] = 1;
    }
    void getBoundingBox() {
        box_low = make_pair(kInf, kInf);
        box_up = make_pair(-kInf, -kInf);
        for (int i = 0; i < m_points.size(); ++i)
            if (active[i]) {
                box_low.x = min(m_points[i].x, box_low.x);
                box_low.y = min(m_points[i].y, box_low.y);
                box_up.x = max(m_points[i].x, box_up.x);
                box_up.y = max(m_points[i].y, box_up.y);
            }
    }
  private:
    vector <point> m_points;
    bool active[kNMax];
    bool pointInSquare(point P, sq X) {
        if (X.low.x <= P.x && P.x <= X.up.x && X.low.y <= P.y && P.y <= X.up.y)
            return 1;
        return 0;
    }
} mySet;

bool can(int L) {
    mySet.getBoundingBox();
    int cand_x[] = {mySet.box_low.x, mySet.box_up.x - L};
    int cand_y[] = {mySet.box_low.y, mySet.box_up.y - L};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            sq first_square(make_pair(cand_x[i], cand_y[j]), make_pair(cand_x[i] + L, cand_y[j] + L));
            mySet.killPoints(first_square);
            mySet.getBoundingBox();
            sq second_square1(make_pair(mySet.box_low.x, mySet.box_low.y), make_pair(mySet.box_low.x + L, mySet.box_low.y + L));
            sq third_square1 (make_pair(mySet.box_up.x - L, mySet.box_up.y - L), make_pair(mySet.box_up.x, mySet.box_up.y));
            sq second_square2(make_pair(mySet.box_low.x, mySet.box_up.y - L), make_pair(mySet.box_low.x + L, mySet.box_up.y));
            sq third_square2(make_pair(mySet.box_up.x - L, mySet.box_low.y), make_pair(mySet.box_up.x, mySet.box_low.y + L));
            if (mySet.coveredByTwoSquares(second_square1, third_square1))
                return 1;
            if (mySet.coveredByTwoSquares(second_square2, third_square2))
                return 1;
            mySet.reset();
        }
    return 0;
}

int main() {
    freopen("patrate.in", "r", stdin);
    freopen("patrate.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        point foo;
        scanf("%d%d", &foo.x, &foo.y);
        mySet.addPoint(foo);
    }

    mySet.getBoundingBox();
    int st = 0, dr = max(mySet.box_up.x - mySet.box_low.x, mySet.box_up.y - mySet.box_low.y), res;
    while (st <= dr) {
        int med = (st + dr) / 2;
        if (can(med)) {
            res = med;
            dr = med - 1;
        } else
            st = med + 1;
        mySet.reset();
    }
    printf("%d", res);
    return 0;
}
