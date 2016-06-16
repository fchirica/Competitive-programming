#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mx_N = 1e4 + 10;
const int mx_K = 100 + 10;
const long long INF = (1LL << 60) - 1;

int n, m;

struct edge {
    int to;
    int cost;
};

vector<edge> G[mx_N];

int h, k;

int v[mx_K];

long long best[mx_N];
bool inQ[mx_N];

queue<int> Q;

void add(const int nod) {
    if(inQ[nod])
        return;
    inQ[nod] = 1;
    Q.push(nod);
}

int pop() {
    int x = Q.front();
    Q.pop();
    inQ[x] = 0;
    return x;
}

void BFS(const int nod) {
    for(int i = 1; i <= n; ++i){
        best[i] = INF;
        inQ[i] = 0;
    }
    add(nod);
    while(!Q.empty()) {
        vector <edge> :: iterator e;
        int x = pop();
        for(e = G[x].begin(); e != G[x].end(); ++e) {
            if(best[x] + e->cost < best[e->to]) {
                best[e->to] = best[x] + e->cost;
                add(e->to);
            }
        }
    }
}

long long dist[mx_K][mx_K];

void precalc(const int idx) {
    BFS(v[idx]);
    for(int i = 1; i <= k; ++i) {
        dist[idx][i] = best[v[i]];
    }
}

long long* DP[mx_K][mx_K];

template<typename T>
T mx(T a, T b) {
    if(a > b)
        return a;
    else
        return b;
}

template<typename T, typename... Args>
T mx(T a, Args... args) {
    T b = mx(args...);
    return mx(a, b);
}

int f(int a, int b, int c) {
    return mx(a, b, c);
}

template<typename T>
T mn(T a, T b) {
    if(a < b)
        return a;
    else
        return b;
}

template<typename T, typename... Args>
T mn(T a, Args... args) {
    T b = mn(args...);
    return mn(a, b);
}

int t(int a, int b, int c) {
    return mn(a, b, c);
}

int s(int a, int b, int c) {
    return a + b + c - f(a, b, c) - t(a, b, c);
}

void check(int a, int b, int c, int d, int ii, int jj, int kk) {
    int i = f(ii, jj, kk),
        j = s(ii, jj, kk),
        k = t(ii, jj, kk);

    if(DP[a][b][c] + d < DP[i][j][k])
        DP[i][j][k] = DP[a][b][c] + d;
}

int main() {



    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        G[a].push_back((edge){b, d});
        G[b].push_back((edge){a, d});
    }
    cin >> h >> k;
    v[1] = h;
    k++;
   for(int i = 2; i <= k; ++i)
        cin >> v[i];
    v[++k] = h;

    for(int i = 1; i <= k; ++i)
        precalc(i);


    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= k; ++j) {
            DP[i][j] = new long long[mx_K];
        }
    }

    for(int a = 1; a <= k; ++a) {
        for(int b = 1; b <= k; ++b) {
            for(int c = 1; c <= k; ++c) {
                DP[a][b][c] = INF;
            }
        }
    }

    DP[1][1][1] = 0;

    for(int a = 1; a <= k; ++a) {
        for(int b = 1; b <= a; ++b) {
            for(int c = 1; c <= b; ++c) {
                int nx = a + 1;
                int d1 = dist[a][nx],
                    d2 = dist[b][nx],
                    d3 = dist[c][nx];

                check(a, b, c, d1, nx, b, c);
                check(a, b, c, d2, a, nx, c);
                check(a, b, c, d3, a, b, nx);
            }
        }
    }


    cout << DP[k][k][k] << "\n";
    return 0;
}
