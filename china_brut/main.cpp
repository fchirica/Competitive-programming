#include <stdio.h>
#include <string.h>

char _x[2012];
int x[2012];

void rev() {
    int st = 1, dr = x[0];
    while (st <= dr) {
        int tmp = x[st];
        x[st] = x[dr];
        x[dr] = tmp;
        ++st; --dr;
    }
}

int y[2012];

void move() {
    for (int i = 0; i <= y[0]; ++i)
        x[i] = y[i];
}

void dec() {
    rev();
    for (int i = 1; i <= x[0]; ++i) {
        --x[i];
        if (x[i] >= 0)
            break;
        else
            x[i] = 9;
    }
    while (x[0] > 0 && x[x[0]] == 0)
        --x[0];
    rev();
}

void div() {
    y[0] = 0;
    int i = 1, num = x[1];
    if (num == 1)
        num = num * 10 + x[2], ++i;
    for (; i <= x[0]; ++i) {
        y[++y[0]] = num / 2;
        num = (num % 2) * 10 + x[i + 1];
    }
    move();
}

void show() {
    for (int i = 1; i <= x[0]; ++i)
        printf("%d", x[i]);
}

int main() {
    freopen("china.in", "r", stdin);
    freopen("china.out", "w", stdout);

    gets(_x + 1);
    int N = strlen(_x + 1), i;
    for (i = 1; i <= N; ++i)
        x[i] = _x[i] - '0';
    x[0] = N;

    if (x[x[0]] % 2) {
        dec();
        div();
        show();
        return 0;
    }

    int div4;
    if (x[0] == 1)
        div4 = x[1];
    else
        div4 = x[x[0]] + x[x[0] - 1] * 10;
    div();
    dec();
    if (div4 % 4)
        dec();
    show();
    return 0;
}
