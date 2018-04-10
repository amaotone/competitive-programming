// TEMPLATE
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>
#include <numeric>
#include <queue>

using namespace std;
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")


// LIBRARY
struct BipartiteMatching {
    // 2部グラフの最大マッチング
    vector<vector<int>> G;
    vector<int> match;
    vector<bool> used;
    BipartiteMatching(int n) {
        G.resize(n);
        used.assign(n, 0);
        match.assign(n, -1);
    }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bool dfs(int v) {
        used[v] = 1;
        REP(i, G[v].size()) {
            int u = G[v][i], w = match[u];
            if (w == -1 or (not used[w] and dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int res = 0;
        REP(i, G.size()) {
            used.assign(G.size(), 0);
            if (match[i] == -1 and dfs(i)) res++;
        }
        return res;
    }
};

// SOLVE
signed ARC092_C() {
    using P = pair<int, int>;
    int N; cin>>N;
    vector<P> red;
    vector<P> blue;
    REP(i, N) {
        int a, b; cin>>a>>b;
        red.push_back(P(a, b));
    }    
    REP(i, N) {
        int c, d; cin>>c>>d;
        blue.push_back(P(c, d));
    }
    BipartiteMatching bm(2*N);
    REP(r, N) {
        REP(b, N) {
            if (red[r].first < blue[b].first and red[r].second < blue[b].second) {
                bm.add_edge(r, b+N);
            }
        }
    }
    cout << bm.solve() << endl;
}

int main() {
    ARC092_C();
}