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

int main() {
    int n; cin>>n;
    vi p(n); rep(i,n) cin>>p[i];
    rep(i,n) p[i]--;  // 0-origin

    int cnt=0;
    rep(i,n) {
        if (i==p[i]) {
            cnt++;
            if (i<n-1) swap(p[i], p[i+1]);
        }
    }
    print(cnt);
}