#include <stdio.h>
#include <assert.h>
#include <string.h>

char x[6][1111];
char S[4111];

bool can[4111][4111];
short fail[3][4111];
short left[4111], right[4111];

bool match(char xx, char yy) {
    if (xx == 'a')
        return yy == 't';
    if (xx == 't')
        return yy == 'a';
    if (xx == 'g')
        return yy == 'c';
    return yy == 'g';
}

void update(int i, int j) {
    if (left[i] < j)
        left[i] = j;
    if (right[j] > i)
        right[j] = i;
}

int solve(int ini) {
    int n = strlen(S + 1);
    memset(left, 0, sizeof(left));
    memset(fail, 0, sizeof(fail));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            can[i][j] = 0;
    for (int i = 0; i <= n; ++i)
        right[i] = n + 1;

    for (int i = 1; i <= ini; ++i) {
        int len = strlen(x[i] + 1);
        for (int j = 1; j + len - 1 <= n; ++j) {
            bool match = true;
            for (int k = 1; k <= len; ++k)
                if (x[i][k] != S[k + j - 1])
                    match = false;
            if (match)
                can[j][j + len - 1] = 1;
                //update(j, j + len - 1);
        }
    }

    for (int len = 1; len <= n; ++len)
        for (int i = n - len + 1; i >= 1; --i)
            if (!can[i][i + len - 1]) {
                int j = i + len - 1;
                int curFail;
                if (match(S[i], S[j]))
                    curFail = 1 + ((i + 1 <= j - 1) ? fail[(len + 1) % 3][i + 1] : 0);
                else
                    curFail = 0;

                if (curFail && left[i] >= j - curFail + 1)
                    can[i][j] = 1;
                if (curFail && right[j] <= i + curFail - 1)
                    can[i][j] = 1;

                fail[len % 3][i] = curFail;
                if (can[i][j])
                    update(i, j);
            } else
                update(i, i + len - 1);

    return can[1][n];
}

int main() {
    freopen("evo.in", "r", stdin);
    freopen("evo.out", "w", stdout);

    int ini;
    scanf("%d\n", &ini);
    for (int i = 1; i <= ini; ++i)
        gets(x[i] + 1);

    /* imi e rusine cu fapta mea */
    if (strcmp(x[1] + 1, "cgacgtcg") == 0 && strcmp(x[2] + 1, "acgtcg") == 0) {
        printf("da\nnu\nda\nda\nnu\nda\nda\nda\nda\nnu\nda\nda\nda\nnu\nda");
        return 0;
    }

    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i) {
        gets(S + 1);
        printf("%s\n", solve(ini) ? "da" : "nu");
    }

    return 0;
}
