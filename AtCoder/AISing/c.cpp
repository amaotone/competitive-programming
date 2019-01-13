// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i = (a); (i) < (b); (i)++)
#define FORS(i, a, b) for (int i = (a); (i) <= (b); (i)++)
#define REP(i, n) for (int i = 0; (i) < (n); (i)++)
#define REPS(i, n) for (int i = 1; (i) <= (n); (i)++)
#define RREP(i, n) for (int i = (n - 1); (i) >= 0; (i)--)
#define RREPS(i, n) for (int i = n; (i) > 0; (i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout << (x) << "\n")

// LIBRARY

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) {}
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (data[y] < data[x])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

// SOLVE
void solve() {
  int H, W;
  cin >> H >> W;
  vvi C(H, vector<int>(W));
  UnionFind uf(H * W + 1);
  REP(i, H) {
    string str;
    cin >> str;
    REP(j, W) {
      if (str[j] == '.') {
        C[i][j] = 0;
      } else {
        C[i][j] = 1;
      }
    }
  }
  REP(i, H) {
    REP(j, W) {
      if (j != 0 && C[i][j] != C[i][j - 1]) {
        uf.unite(i * W + j, i * W + j - 1);
      }
      if (i != 0 && C[i][j] != C[i - 1][j]) {
        uf.unite((i - 1) * W + j, i * W + j);
      }
    }
  }
  set<ll> s;
  map<ll, ll> wc;
  map<ll, ll> bc;
  REP(i, H) {
    REP(j, W) {
      ll root = uf.root(i * W + j);
      s.insert(root);
      if (C[i][j] == 0) {
        wc[root]++;
      } else {
        bc[root]++;
      }
    }
  }
  ll ans = 0;
  for (set<ll>::iterator it = s.begin(), end = s.end(); it != end; ++it) {
    ans += wc[*it] * bc[*it];
  }
  print(ans);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
