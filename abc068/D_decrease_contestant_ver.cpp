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
#define print(x) (cout<<(x)<<"\n")

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    const int n=50;
    ll k; cin>>k;
    ll a=k/n;
    ll b=k%n;
    vector<ll> A(n); rep(i, n) A[i]=(ll)i+a;
    rep(i, n) {
        if (i<b) A[i]+=n-b+1;
        else A[i]-=b;
    }
    print(50);
    rep(i, A.size()) {
        cout << (i ? " " : "") << A[i];
    }
    cout << endl;
}