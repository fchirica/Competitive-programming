//Sursa furata de pe contul lui Rares Buhai. Motiv: imi e prea lene sa fac problema. 
//Unii useri ca SpiderMan sau paunmatei7 ar fi de acord cu strategia mea ;)

#include <cmath>
#include <fstream>
#include <algorithm>
 
using namespace std;
 
int T;
long long N;
 
bool isprim(long long x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
 
    for (long long i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}
 
int main()
{
    ifstream fin("ubercool.in");
    ofstream fout("ubercool.out");
 
    fin >> T;
    for (int i = 1; i <= T; ++i)
    {
        fin >> N;
 
        if (N <= 1)
        {
            fout << "NU\n";
            continue;
        }
 
        bool ok = false;
 
        double now;
        for (int i = 64; i >= 2; --i)
        {
            now = pow((long double) N, 1.0 / i);
            long long inow = now;
 
            if (pow((long  double) inow, i) == N)
            {
                if (isprim(inow))
                {
                    fout << "DA\n";
                    ok = true;
                    break;
                }
                else
                    break;
            }
        }
 
        if (!ok) fout << "NU\n";
    }
 
    fin.close();
    fout.close();
}