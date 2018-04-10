/*
* ワーシャルフロイドと全探索
*/

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
#define INF (1<<29);

int main() {
    int n,m,r; cin>>n>>m>>r;
    vi rs(r); rep(i, r) cin>>rs[i];
    vvi d(n, vi(n));
    rep(i, n) rep(j, n) if (i!=j) d[i][j]=INF;
    rep(i, m) {
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        d[a][b] = d[b][a] = c;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int ans = INF;
    sort(all(rs));
    do {
        int t = 0;
        rep(i, r-1) {
            t += d[rs[i]-1][rs[i+1]-1];
        }
        if (t < ans) ans = t;
    } while (next_permutation(all(rs)));
    cout << ans << endl;
}