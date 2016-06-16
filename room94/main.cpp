#include <stdio.h>

int sol[9][9][9][9][9][9];
bool blocked[9][9];

struct position {
    int Ri, Rj, Ni, Nj, Ci, Cj;
} Q[8 * 8 * 8 * 8 * 8 * 8 + 100];

position mp(int Ri, int Rj, int Ni, int Nj, int Ci, int Cj) {
    position tmp;
    tmp.Ci = Ci; tmp.Cj = Cj;
    tmp.Ni = Ni; tmp.Nj = Nj;
    tmp.Ri = Ri; tmp.Rj = Rj;
    return tmp;
}

bool isValid(int x0, int y0) {
    if (x0 <= 0 || y0 <= 0 || x0 > 8 || y0 > 8)
        return false;
    if (blocked[x0][y0])
        return false;
    return true;
}

int remainedMoves;

int xKing, yKing;
void move(position cur, int stepx, int stepy, int who, int moves, int &u) {
    int x0, y0;
    if (remainedMoves <= 0)
        remainedMoves = 1;
    if (who == 1)
        x0 = cur.Ri, y0 = cur.Rj;
    if (who == 2)
        x0 = cur.Ni, y0 = cur.Nj;
    if (who == 3)
        x0 = cur.Ci, y0 = cur.Cj;
    while (isValid(x0, y0) && remainedMoves >= 0) {
        if (who != 1 && x0 == cur.Ri && y0 == cur.Rj)
            break;
        if (who != 2 && x0 == cur.Ni && y0 == cur.Nj)
            break;
        if (who != 3 && x0 == cur.Ci && y0 == cur.Cj)
            break;
        if (x0 == xKing && y0 == yKing)
            break;

        if (sol[cur.Ri][cur.Rj][cur.Ni][cur.Nj][cur.Ci][cur.Cj] == -1) {
                sol[cur.Ri][cur.Rj][cur.Ni][cur.Nj][cur.Ci][cur.Cj] = moves + 1;
                Q[++u] = cur;
            }
        --remainedMoves;
        x0 += stepx; y0 += stepy;
        if (who == 1)
            cur.Ri = x0, cur.Rj = y0;
        if (who == 2)
            cur.Ni = x0, cur.Nj = y0;
        if (who == 3)
            cur.Ci = x0, cur.Cj = y0;
    }
}

inline int ab(int X) {
    return X > 0 ? X : -X;
}

bool isAttacked(position cur, int x0, int y0) {
    if (x0 == cur.Ri || y0 == cur.Rj)
        if (x0 != cur.Ri || y0 != cur.Rj)
            return true;
    int deltax = ab(cur.Ri - x0);
    int deltay = ab(cur.Rj - y0);
    if (deltax == deltay && deltax)
        return true;
    deltax = ab(cur.Ni - x0);
    deltay = ab(cur.Nj - y0);
    if (deltax == deltay && deltax)
        return true;
    deltax = ab(cur.Ci - x0);
    deltay = ab(cur.Cj - y0);
    if (deltax == 1 && deltay == 2)
        return true;
    if (deltax == 2 && deltay == 1)
        return true;
    return false;
}

int main() {
    freopen("room94.in", "r", stdin);
    freopen("room94.out", "w", stdout);

    int i, j;
    int Ri, Rj, Ni, Nj, Ci, Cj, Ki, Kj;
    char ch;
    for (i = 1; i <= 8; ++i, scanf("\n"))
        for (j = 1; j <= 8; ++j) {
            scanf("%c", &ch);
            if (ch == 'Q')
                Ri = i, Rj = j;
            if (ch == 'B')
                Ni = i, Nj = j;
            if (ch == 'K')
                Ci = i, Cj = j;
            if (ch == 'G')
                Ki = i, Kj = j;
            if (ch == 'P')
                blocked[i][j] = true;
        }

    int p = 1, u = 0;
    Q[++u] = mp(Ri, Rj, Ni, Nj, Ci, Cj);
    for (Ri = 0; Ri < 9; ++Ri)
        for (Rj = 0; Rj < 9; ++Rj)
            for (Ni = 0; Ni < 9; ++Ni)
                for (Nj = 0; Nj < 9; ++Nj)
                    for (Ci = 0; Ci < 9; ++Ci)
                        for (Cj = 0; Cj < 9; ++Cj)
                            sol[Ri][Rj][Ni][Nj][Ci][Cj] = -1;
    sol[Q[1].Ri][Q[1].Rj][Q[1].Ni][Q[1].Nj][Q[1].Ci][Q[1].Cj] = 0;
    xKing = Ki; yKing = Kj;

    while (p <= u) {
        position current = Q[p]; ++p;
        int moves = sol[current.Ri][current.Rj][current.Ni][current.Nj][current.Ci][current.Cj];
        //Verific daca l-am facut mat
        int checkMate = 1;
        for (i = Ki - 1; i <= Ki + 1; ++i)
            for (j = Kj - 1; j <= Kj + 1; ++j)
                if (isValid(i, j))
                    checkMate = checkMate * isAttacked(current, i, j);
        if (checkMate == 1) {
            printf("%d", moves);
            return 0;
        }
        //Mut regina
        remainedMoves = 1 << 30;
        move(current, -1, -1, 1, moves, u);
        move(current, -1, +1, 1, moves, u);
        move(current, +1, -1, 1, moves, u);
        move(current, +1, +1, 1, moves, u);
        move(current, -1, 0, 1, moves, u);
        move(current, 0, 1, 1, moves, u);
        move(current, 1, 0, 1, moves, u);
        move(current, 0, -1, 1, moves, u);
        //Mut nebunu
        move(current, -1, -1, 2, moves, u);
        move(current, -1, +1, 2, moves, u);
        move(current, +1, -1, 2, moves, u);
        move(current, +1, +1, 2, moves, u);
        //Mut calu
        remainedMoves = 0;
        move(current, -1, -2, 3, moves, u);
        move(current, -2, -1, 3, moves, u);
        move(current, -2, +1, 3, moves, u);
        move(current, -1, +2, 3, moves, u);
        move(current, +1, -2, 3, moves, u);
        move(current, +2, -1, 3, moves, u);
        move(current, +2, +1, 3, moves, u);
        move(current, +1, +2, 3, moves, u);
    }

    printf("-1");
    return 0;
}
