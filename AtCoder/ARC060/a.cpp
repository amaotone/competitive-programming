// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i=(a);(i)<(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define print(x) (cout<<(x)<<"\n")

// LIBRARY


// SOLVE
ll dp[51][51][3001];

signed main() {
    ll n, a; cin>>n>>a;
    vector<ll> x(n);
    REP(i, n) {
        cin>>x[i];
    }
    dp[0][0][0] = 1;
    REP(i, n) {
        REP(j, n) {
            REP(k, 2501) {
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, n+1) {
        ans += dp[n][i][i*a];
    }
    print(ans);
}
