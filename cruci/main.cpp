#include <fstream>
using namespace std;
 
#define MAXN 110
 
int N, M;
char c[MAXN][MAXN];
int pl[MAXN][MAXN], pc[MAXN][MAXN];
 
int main()
{
        int i, j, k, nrcruci = 0;
		
        ifstream f ("cruce.in");
        ofstream g ("cruce.out");
		
        f >> N >> M; f.get();
        for (i = 1; i <= N; ++i)
                f.getline (c[i] + 1, MAXN);
               
        for (i = 1; i <= N; ++i)
                for (j = 1; j <= M; ++j)
                {
                        for (k = 0; j + k <= M && j - k > 0; ++k)
                                if (c[i][j - k] != c[i][j + k])
                                        break;
                        pl[i][j] = k - 1;
                }
               
        for (i = 1; i <= N; ++i)
                for (j = 1; j <= M; ++j)
                {
                        for (k = 0; i + k <= N && i - k > 0; ++k)
                                if (c[i - k][j] != c[i + k][j])
                                        break;
                        pc[i][j] = k - 1;
                }
       
        for (i = 1; i <= N; ++i)
                for (j = 1; j <= M; ++j)
                        if (pc[i][j] >= 1 && pl[i][j] >= 1)
                                ++nrcruci;
                               
        g << nrcruci;
        return 0;
}