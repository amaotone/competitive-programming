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
#define print(x) (cout<<x<<endl)
#define inf (ll)1e18;

int main() {
    int n; cin>>n;
    vvi a(n, vi(n)); rep(i,n) rep(j,n) cin>>a[i][j];
    
    // ワーシャルフロイドで更新されたらアウト
    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                if (a[i][j]>a[i][k]+a[k][j]) {
                    print(-1);
                    return 0;
                }
            }
        }
    }

    ll ans=0;
    rep(i,n) {
        rep(j,i) {
            ll tmp=inf;
            rep(k,n) {
                if (k==i or k==j) continue;
                tmp = min(tmp, (ll)a[i][k]+a[k][j]);
            }
            if (tmp>a[i][j]) ans+=a[i][j];
        }
    }
    print(ans);
}