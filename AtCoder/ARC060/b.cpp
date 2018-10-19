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
#define FORS(i, a, b) for (int i=(a);(i)<=(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define REPS(i, n) for (int i=1;(i)<=(n);(i)++)
#define RREP(i, n) for (int i=(n-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")

// LIBRARY


// SOLVE
ll f(ll b, ll n) {
    if (n<b) return n;
    return f(b, n/b) + n%b;
}

signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll n; cin>>n;
    ll s; cin>>s;

    // 自明
    if (n==s) {
        print(n+1);
        return 0;
    }
    if (s > n) {
        print(-1);
        return 0;
    }
    // sqrt(n)までは全探索
    ll sq = sqrt(n) + 1;
    FOR(i, 2, sq) {
        if (f(i, n) == s) {
            print(i);
            return 0;
        }
    }
    // 残りは2桁 上の桁で探索
    ll ans = 1e18+1;
    FOR(i, 1, sq) {
        ll b = (n-s)/i + 1;
        if ((n-s)%i==0 && f(b, n) == s) {
            ans = min(ans, b);
        }
    }
    if (ans == 1e18+1) {
        print(-1);
        return 0;
    }
    print(ans);
}
