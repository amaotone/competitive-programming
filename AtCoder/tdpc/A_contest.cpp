#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i=0;(i)<(n);(i)++)
#define repi(i, n) for (int i=0;(i)<=(n);(i)++)
#define repr(i, n) for (int i=n;(i)>=0;(i)--)

#define MAXSUM 10000+1

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vi p(n); rep(i, n) cin >> p[i];

    vector<bool> dp(MAXSUM, false);
    dp[0] = true;
    rep(i, n) {
        repr(j, MAXSUM) {
            dp[j+p[i]] = dp[j+p[i]] or dp[j];
        }
    }
    cout << count(all(dp), true) << endl;
}