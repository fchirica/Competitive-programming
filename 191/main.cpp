#include <stdio.h>
#include <algorithm>
#define point pair <double, double>
#define x first
#define y second

using namespace std;

int area(int x1, int y1, int x2, int y2, int x3, int y3){
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

bool intersect(point _x0, point _y0, point _x1, point _y1) {
    int x1 = _x0.x, y1 = _x0.y;
    int x2 = _y0.x, y2 = _y0.y;
    int x3 = _x1.x, y3 = _x1.y;
    int x4 = _y1.x, y4 = _y1.y;
    double a1,a2,a3,a4;

    a1=area(x1,y1,x3,y3,x2,y2);
    a2=area(x1,y1,x4,y4,x2,y2);
    a3=area(x3,y3,x1,y1,x4,y4);
    a4=area(x3,y3,x2,y2,x4,y4);

    if(a1*a2<0 && a3*a4<0) return true;
    if(a1==0 && (x3-x1)*(x3-x2)<=0 && (y3-y1)*(y3-y2)<=0) return true;
    if(a2==0 && (x4-x1)*(x4-x2)<=0 && (y4-y1)*(y4-y2)<=0) return true;
    if(a3==0 && (x1-x3)*(x1-x4)<=0 && (y1-y3)*(y1-y4)<=0) return true;
    if(a4==0 && (x2-x3)*(x2-x4)<=0 && (y2-y3)*(y2-y4)<=0) return true;

    return false;
}

bool greater(double A, double B) {
    return A - B > 0.000000001;
}

bool included(double X, double A, double B) {
    return greater(X, A) && greater(B, X);
}

bool pointInside(point X, point A, point B) {
    return included(X.x, A.x, B.x) && included(X.y, A.y, B.y);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test) {
        point X, Y, x0, x1, x2, x3;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &X.x, &X.y, &Y.x, &Y.y, &x0.x, &x0.y, &x2.x, &x2.y);
        if (x0.x > x2.x)
            swap(x0.x, x2.x);
        if (x0.y > x2.y)
            swap(x0.y, x2.y);
        x1 = make_pair(x2.x, x0.y);
        x3 = make_pair(x0.x, x2.y);
        bool cross = false;
        if (pointInside(X, x3, x1))
            cross = true;
        if (pointInside(Y, x3, x1))
            cross = true;
        if (intersect(X, Y, x0, x1))
            cross = true;
        if (intersect(X, Y, x1, x2))
            cross = true;
        if (intersect(X, Y, x2, x3))
            cross = true;
        if (intersect(X, Y, x3, x0))
            cross = true;
        printf("%c\n", cross == true ? 'T' : 'F');
    }

    return 0;
}
