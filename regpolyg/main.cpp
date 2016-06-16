#include <stdio.h>
#include <math.h>
#include <string.h>

struct point {
    double x, y;
};

double det(double A, double B, double C, double D) {
    return A * D - B * C;
}

point findCircumference(point A, point B, point C) {
    //Equation of a line given a point (x0, y0) and slope:
    //y - y0 = slope * (x - x0)
    point mid1, mid2;
    mid1.x = (A.x + B.x) * 0.5; mid1.y = (A.y + B.y) * 0.5;
    mid2.x = (B.x + C.x) * 0.5; mid2.y = (B.y + C.y) * 0.5;
    double slope1 = (B.y - A.y) / (B.x - A.x);
    double slope2 = (C.y - B.y) / (C.x - B.x);
    slope1 = -1 / slope1; slope2 = -1 / slope2;
    double A1, B1, C1, A2, B2, C2;
    A1 = -slope1; B1 = 1; C1 = mid1.y - slope1 * mid1.x;
    A2 = -slope2; B2 = 1; C2 = mid2.y - slope2 * mid2.x;
    //Krammer's rule
    double mainDet = det(A1, B1, A2, B2);
    double detX = det(C1, B1, C2, B2);
    double detY = det(A1, C1, A2, C2);
    point center;
    center.x = detX / mainDet;
    center.y = detY / mainDet;
    return center;
}

double degrees(point X) {
    double radians = atan2(X.y, X.x);
    return 180 * radians / (2 * acos(0));
}

double getAngle(point A, point O, point B) {
    A.x = A.x - O.x; A.y = A.y - O.y;
    B.x = B.x - O.x; B.y = B.y - O.y;
    return degrees(A) - degrees(B);
}

void solveTest(point A, point B, point C) {
    point O = findCircumference(A, B, C);
    int alfa, beta;
    alfa = getAngle(A, O, B);
    beta = getAngle(A, O, C);
    int sol;
    for (sol = 3; ; ++sol) {
        double expectedAngle = (double)360 / sol;
        if (fabs(alfa / expectedAngle - round(alfa / expectedAngle)) <= 0.000001)
            if (fabs(beta / expectedAngle - round(beta / expectedAngle)) <= 0.000001) {
                printf("%d\n", sol);
                return ;
            }
    }
}

double parse(char x[]) {
    int i = 0;
    int sign = 1, what = 0;
    double num = 0, div = 1;
    if (x[0] == '-')
        sign = -1, ++i;
    for (; i < strlen(x); ++i) {
        if (x[i] == '.') {
            ++what;
            continue;
        }
        num = num * 10 + x[i] - '0';
        if (what == 1)
            div = div / 10;
    }
    return num * div * sign;
}

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);

    point A, B, C;
    char endMessage[300];
    while (1) {
        scanf("%s", &endMessage);
        if (endMessage[0] == 'E' && endMessage[1] == 'N' && endMessage[2] == 'D')
            return 0;
        A.x = parse(endMessage);
        scanf("%lf %lf %lf %lf %lf\n", &A.y, &B.x, &B.y, &C.x, &C.y);
        solveTest(A, B, C);
    }

    return 0;
}
