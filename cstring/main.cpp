//distanta Cumming ;)

#include <stdio.h>

char A[1000100], B[1000100], C[1000100], res[1000100];
int dif[1000100], same12[1000100], same13[1000100], same23[1000100];

int main() {
    freopen("cstring.in", "r", stdin);
    freopen("cstring.out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    gets(A + 1);
    gets(B + 1);
    gets(C + 1);

    for (int i = 1; i <= n; ++i) {
        if (A[i] == B[i] && B[i] == C[i])
            res[i] = A[i];
        else if (A[i] == B[i])
            same12[++same12[0]] = i;
        else if (A[i] == C[i])
            same13[++same13[0]] = i;
        else if (B[i] == C[i])
            same23[++same23[0]] = i;
        else
            dif[++dif[0]] = i;
    }

    int minBucket = same12[0];
    if (same13[0] < minBucket)
        minBucket = same13[0];
    if (same23[0] < minBucket)
        minBucket = same23[0];

    for (int i = 1; i <= minBucket; ++i) {
        int index = same12[same12[0]];
        res[index] = A[index];
        index = same13[same13[0]];
        res[index] = A[index];
        index = same23[same23[0]];
        res[index] = B[index];
        --same12[0]; --same13[0]; --same23[0];
    }

    if (same12[0]) {
        while (same12[0] && dif[0]) {
            int index = same12[same12[0]];
            res[index] = A[index];
            index = dif[dif[0]];
            res[index] = C[index];
            --same12[0]; --dif[0];
        }
    }

    if (same13[0]) {
        while (same13[0] && dif[0]) {
            int index = same13[same13[0]];
            res[index] = A[index];
            index = dif[dif[0]];
            res[index] = B[index];
            --same13[0]; --dif[0];
        }
    }

    if (same23[0]) {
        while (same23[0] && dif[0]) {
            int index = same23[same23[0]];
            res[index] = B[index];
            index = dif[dif[0]];
            res[index] = A[index];
            --same23[0]; --dif[0];
        }
    }

    int turn = 0;
    while (same12[0]) {
        int index = same12[same12[0]];
        if (turn == 0)
            res[index] = A[index];
        else
            res[index] = C[index];
        turn = 1 - turn;
        --same12[0];
    }

    turn = 0;
    while (same13[0]) {
        int index = same13[same13[0]];
        if (turn == 0)
            res[index] = A[index];
        else
            res[index] = B[index];
        turn = 1 - turn;
        --same13[0];
    }

    turn = 0;
    while (same23[0]) {
        int index = same23[same23[0]];
        if (turn == 0)
            res[index] = B[index];
        else
            res[index] = A[index];
        turn = 1 - turn;
        --same23[0];
    }

    int humA = 0, humB = 0, humC = 0;
    for (int i = 1; i <= n; ++i)
        if (res[i]) {
            if (res[i] != A[i])
                ++humA;
            if (res[i] != B[i])
                ++humB;
            if (res[i] != C[i])
                ++humC;
        }

    for (int i = 1; i <= n; ++i)
        if (!res[i]) {
            if (humA >= humB && humA >= humC)
                res[i] = A[i];
            else if (humB >= humA && humB >= humC)
                res[i] = B[i];
            else
                res[i] = C[i];

            if (res[i] != A[i])
                ++humA;
            if (res[i] != B[i])
                ++humB;
            if (res[i] != C[i])
                ++humC;
        }

    for (int i = 1; i <= n; ++i)
        printf("%c", res[i]);
    return 0;
}
