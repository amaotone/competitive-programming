#include<iostream>
#include<climits>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define POINT_MAX 50
#define ll long long

int main(void) {
    int n, k;
    ll x[POINT_MAX], y[POINT_MAX];
    ll ans=LONG_LONG_MAX;
    cin >> n >> k;
    rep(i, n) cin >> x[i] >> y[i];
    rep(l, n) {
        rep(r, n) {
            if (x[l] >= x[r]) continue;
            rep(b, n) {
                rep(t, n) {
                    if (y[b] >= y[t]) continue;
                    int cnt = 0;
                    rep(i, n) {
                        if (x[i]>=x[l] and x[i]<=x[r] and y[i]>=y[b] and y[i]<=y[t]) cnt++;
                    }
                    if (cnt>=k) ans=min(ans, (x[r]-x[l])*(y[t]-y[b]));
                }
            }
        }
    }
    cout << ans << endl;
    return 0; 
}