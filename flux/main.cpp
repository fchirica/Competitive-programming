//Problema asta e perfecta daca vrei sa ai chef sa-ti tai venele in timp ce borasti ce-ai mancat in ultima luna
//Si da, e furata sursa. Vreo problema?
//MLC

#include <cmath>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const double eps = 1e-9;

int N, M;
int C[102][102];
int edges[102][102];
bool is[102][102];
double A[102][102];
double X[102];
bool impossible;

bool S[102];
void Dfs(int x)
{
    S[x] = true;
    for (int i = 1; i <= N; ++i)
        if (is[x][i] != 0 && !S[i])
            Dfs(i);
}

int main()
{
    ifstream fin("flux.in");
    ofstream fout("flux.out");

    fin >> N >> M;
    for (int i = 1, nod1, nod2, cap; i <= M; ++i)
    {
        fin >> nod1 >> nod2 >> cap;
        is[nod1][nod2] = is[nod2][nod1] = true;

        if (edges[nod1][nod2] == 0)
        {
            C[nod1][nod2] = cap;
            C[nod2][nod1] = cap;
        }
        else
        {
            C[nod1][nod2] = min(C[nod1][nod2], cap);
            C[nod2][nod1] = min(C[nod2][nod1], cap);
        }

        ++edges[nod1][nod2];
        ++edges[nod2][nod1];
    }

    Dfs(1);
    if (!S[N])
    {
        fout << "0.000" << '\n';
        fin.close();
        fout.close();

        return 0;
    }

    for (int i = 2; i <= N; ++i) // 1 => i + 1
    {
        for (int j = 1; j <= N; ++j)
            if (i != j && edges[i][j] != 0)
            {
                A[i - 1][i - 1] += edges[i][j];
                if (j != 1) A[i - 1][j - 1] -= edges[i][j];
            }
        if (i == N)
            ++A[i - 1][N]; // suma celor care intra e egala cu 1
    }

    for (int i = 1, j = 1; i <= N - 1 && j <= N - 1; )
    {
        int fnow = -1;
        for (int k = i; k <= N - 1; ++k)
            if (fabs(A[k][j]) > eps)
            {
                fnow = k;
                break;
            }
        if (fnow == -1)
        {
            ++j;
            continue;
        }

        for (int k = 1; k <= N; ++k)
            swap(A[i][k], A[fnow][k]);
        for (int k = j + 1; k <= N; ++k)
            A[i][k] /= A[i][j];
        A[i][j] = 1;
        for (int k = i + 1; k <= N - 1; ++k)
            if (A[k][j] != 0)
            {
                for (int l = j + 1; l <= N; ++l)
                    A[k][l] -= A[i][l] * A[k][j];
                A[k][j] = 0;
            }

        ++i;
        ++j;
    }

    for (int i = N - 1; i >= 1; --i)
        for (int j = 1; j <= N; ++j)
            if (fabs(A[i][j]) >= eps)
            {
                if (j == N)
                    impossible = true;

                X[j] = A[i][N];
                for (int k = i - 1; k >= 1; --k)
                {
                    A[k][N] -= X[j] * A[k][j];
                    A[k][j] = 0;
                }

                break;
            }

    if (impossible)
    {
        fout << "0.000" << '\n';
        fin.close();
        fout.close();

        return 0;
    }

    double result = 1000000000.0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (is[i][j] == true)
                result = min(result, C[i][j] / fabs(X[j - 1] - X[i - 1]));

    fout << fixed << setprecision(8) << result << '\n';

    fin.close();
    fout.close();
}
