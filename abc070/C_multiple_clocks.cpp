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

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a,b)*b;
}

int main() {
    int N; cin>>N;
    ll t=1LL;
    rep(i,N) {
        ll T; cin>>T;
        t = lcm(t, T);
    }
    print(t);
}