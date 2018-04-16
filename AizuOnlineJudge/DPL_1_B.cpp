// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i=(a);(i)<(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define REPS(i, n) for (int i=1;(i)<=(n);(i)++)
#define RREP(i, n) for (int i=(x-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")

// LIBRARY

// SOLVE
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, W; cin>>N>>W;
    vvi dp(N+1, vector<int>(W+1));

    FOR(i, 1, W+1) dp[0][i] = 0;
    FOR(i, 1, N+1) {
        int v, w; cin>>v>>w;
        FOR(j, 1, W+1) {
            if (w>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
        }
    }
    print(dp[N][W]);
}