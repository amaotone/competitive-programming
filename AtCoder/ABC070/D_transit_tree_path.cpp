// Kを始点とした深さ優先探索
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i=0;(i)<(n);(i)++)
#define repi(i, n) for (int i=0;(i)<=(n);(i)++)
#define repr(i, n) for (int i=n;(i)>=0;(i)--)
#define print(x) (cout<<(x)<<"\n")

const int limit = 100010;
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d) {
    depth[v] = d;
    for (auto &e: tree[v]) {
        if (e.to==p) continue;
        dfs(e.to, v, d+e.cost);
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin>>n;
    rep(i, n-1) {
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    int q, k; cin>>q>>k;
    k--;
    dfs(k, -1, 0);
    rep(i, q) {
        int x, y; cin>>x>>y;
        x--; y--;
        print(depth[x]+depth[y]);
    }
}