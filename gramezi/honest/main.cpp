#include <stdio.h>
#include <vector>

using namespace std;

struct muchie
{
    int x, val;
};

vector <muchie> G[1024];

int main()
{
    int N, M;

    freopen("honest.in", "r", stdin);
    freopen("honest.out", "w", stdout);

    scanf("%d%d", &N, &M);
