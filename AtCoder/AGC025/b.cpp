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
#define MOD 998244353

// LIBRARY
// n^m%MOD を求める。O( log(m) )
ll modpow(ll n, int m){
	ll ret=1;
	for(int i=1; i<=m; i<<=1, (n*=n)%=MOD){
		if( m&i ) (ret *= n) %= MOD;
	}
	return ret;
}

// 逆元を求める
ll modinv(ll n){
	return modpow( n, MOD-2 );
}

// 階乗を求める。O(1)  準備O( n*log(n) )
// fact[n]     : nの階乗
// fact.inv[n] : nの階乗の逆元
class FACTORIAL{
public:
	vector<ll> fact, inv;
	FACTORIAL(int MAX_NUM): fact(MAX_NUM), inv(MAX_NUM) {
		fact[0] = inv[0] = 1;
		for(ll i=1; i<MAX_NUM; i++){
			fact[i] = (fact[i-1] * i) % MOD;
			inv[i] = modinv( fact[i] );
		}
	}
	const ll& operator [ ] ( const int i ) const {
		return fact[i];
	}
} fact(300000); // nの最大値を指定

// 組み合わせ(Combinationを求める) O(1)
ll cmb(unsigned int n, unsigned int r){
	if( n < r ) return 0;
	return fact[n] * fact.inv[r] % MOD * fact.inv[n-r] % MOD;
}

ll gcd(ll n, ll m){
  if(m==0)return n;
  return gcd(m,n%m);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a,b)
}

ll diophantine(ll a, ll b, ll c) {
    ll q = a/b;
    ll r = a%b;
    if (r==0) return make_pair(0, c/b);
    else {
        auto u, v = diophantine(b, r, c);
        return make_pair(v, u-q*v);
    }
}

// SOLVE
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    ll N, A, B, K; cin >> N >> A >> B >> K;

}