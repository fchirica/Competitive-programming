    #include <stdio.h>

    inline int _min(int X, int Y)
    {
        return X < Y ? X : Y;
    }

    bool can(int low, int upp, int pw2, int pw3, int pw5, int pw7)
    {
        int mNeeded = 0;

        mNeeded += pw2 / 3; pw2 = pw2 % 3;
        if (pw2 % 2 && pw3 % 2)
            pw2 --, pw3 --, mNeeded++;
        mNeeded += pw2 / 2; pw2 = pw2 % 2;
        mNeeded += pw3 / 2; pw3 = pw3 % 2;
        mNeeded += pw2 + pw3 + pw5 + pw7;

        return 1 <= mNeeded && mNeeded <= upp;
    }

    int main()
    {
        int A, B, sol = 0, pw2, pw3, pw5, pw7;

        freopen("cifre3.in", "r", stdin);
        freopen("cifre3.out", "w", stdout);

        scanf("%d%d", &A, &B); A ++;

        for (pw2 = 0; pw2 <= 60; pw2 ++)
            for (pw3 = 0; pw3 <= 40; pw3 ++)
                for (pw5 = 0; pw5 <= 20; pw5 ++)
                    for (pw7 = 0; pw7 <= 20; pw7 ++)
                        if (can(A, B, pw2, pw3, pw5, pw7))
                            sol ++;
        if (B > 1)
            sol ++;
        printf("%d", sol + 1);
        return 0;
    }
