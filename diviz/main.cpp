//asa sunt facute majoritatea problemelor mele. recomand cu caldura metoda copy paste ;)

#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

const int MOD = 30103;

int K, A, B;
char N[202];
int P[2][202][102], result;
int last[10];

int main()
{
    ifstream fin("diviz.in");
    ofstream fout("diviz.out");

    fin >> K >> A >> B >> N;
    int M = strlen(N);

    int act = 0;
    for (int i = 1; i <= M; ++i) // cu i cifre
    {
        act = !act;
        memset(P[act], 0, sizeof(P[act]));
        for (int j = 1; j <= M; ++j) // se termina pana in j
        {
            if (i == 1 && N[j - 1] - '0' != 0) P[act][j][(N[j - 1] - '0') % K] = 1;
            for (int k = 0; k < K; ++k) // cel dinainte avea restul k
            {
                P[act][j][(k * 10 + N[j - 1] - '0') % K] += P[!act][j - 1][k];
                if (P[act][j][(k * 10 + N[j - 1] - '0') % K] >= MOD) P[act][j][(k * 10 + N[j - 1] - '0') % K] -= MOD;
            }
        }
        for (int k = 0; k < K; ++k)
        {
            memset(last, 0, sizeof(last));
            for (int j = 1; j <= M; ++j)
            {
                P[act][j][k] -= last[N[j - 1] - '0'];
                last[N[j - 1] - '0'] = P[act][j][k] + last[N[j  - 1] - '0'];
                P[act][j][k] += P[act][j - 1][k];
                while (P[act][j][k] >= MOD) P[act][j][k] -= MOD;
                while (P[act][j][k] < 0)    P[act][j][k] += MOD;
            }
        }

        if (i >= A && i <= B)
        {
            result += P[act][M][0];
            if (result >= MOD) result -= MOD;
        }
    }

    fout << result << '\n';

    fin.close();
    fout.close();
}
