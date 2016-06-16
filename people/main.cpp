#include <stdio.h>
#include <algorithm>

using namespace std;

struct person {
    int x, y, idx;
} x[100100];

int n, nr = 1, v[100100], ord[100100], best[100100], L[100100], p[100100];

inline bool comp(person A, person B) {
    if (A.x == B.x)
        return A.y > B.y;
    return A.x < B.x;
}

void afis(int i) {
   if (p[i] > 0)  afis(p[i]);
   printf("%d ",ord[i]);
}

int caut(int x) {
   int p, u, m;
   p = 0; u = nr; m = (p+u)/2;
   while (p <= u) {
      if (v[L[m]] < x &&  v[L[m+1]] >= x) return m;
      else if (v[L[m+1]] < x) {p = m + 1; m = (p + u)/2;}
      else {u = m - 1; m = (p + u)/2;}
   }
   return nr;
}

int main() {
    freopen("people.in", "r", stdin);
    freopen("people.out", "w", stdout);

    int i, N, poz;
    scanf("%d", &N); n = N;
    for (i = 1; i <= N; ++i) {
        scanf("%d%d", &x[i].x, &x[i].y);
        x[i].idx = i;
    }

    sort(x + 1, x + N + 1, comp);
    for (i = 1; i <= N; ++i) {
        v[i] = x[i].y;
        ord[i] = x[i].idx;
    }

    best[1] = L[1] = 1;
    for (i = 2; i <= n; i++) {
        poz = caut(v[i]);
        p[i] = L[poz];
        best[i] = poz + 1;
        L[poz + 1] = i;
        if (nr < poz + 1)
            nr = poz + 1;
   }

    int maxim = 0;
    poz = 0;
    for (i = 1; i <= n; i++)
       if (maxim < best[i]) {
          maxim = best[i]; poz = i;
       }
    printf("%d\n",maxim);
    afis(poz);
    return 0;
}
