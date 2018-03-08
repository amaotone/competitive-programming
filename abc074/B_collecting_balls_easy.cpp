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
#define INF (1<<29)
#define print(x) (cout<<x<<endl)

int main() {
    int n; cin>>n;
    int k; cin>>k;
    vi xs(n); rep(i, n) cin>>xs[i];
    int ans=0;
    rep(i, n) {
        ans += min(abs(xs[i])*2, abs(xs[i]-k)*2);
    }
    print(ans);
}