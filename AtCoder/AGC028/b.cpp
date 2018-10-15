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
const int MOD = 1e9+7;

int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b!=0) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    } else {
        x = 1; y= 0;
    }
    return d;
}

ll modpow(ll x, ll k, ll m) {
    ll ans=1, p=x;
    while (k) {
        if (k&1) ans=ans*p%m;
        p=p*p%m;
        k>>=1;
    }
    return ans;
}

ll modinv(ll x, ll m) {
    return modpow(x, m-2, m);
}

// test
// AGC028-B
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> a(n); REP(i, n) cin>>a[i];

    vector<ll> inv(n+1);
    FOR(i, 1, n+1) {
        inv[i] = (inv[i-1]+modinv(i, MOD))%MOD;
    }


    ll ans = 0;
    ll f = 1;
    REP(i, n) {
        ans = (ans + a[i]*(inv[i+1]+inv[n-i]-1)%MOD)%MOD;
        f = f*(i+1)%MOD;
    }

    print(ans*f%MOD);
}
