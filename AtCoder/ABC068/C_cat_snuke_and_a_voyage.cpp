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
    int n, m; cin>>n>>m;
    vector<bool> route(n);
    rep(i, m) {
        int a, b; cin>>a>>b;
        a--; b--;
        if (a==0) {
            if (route[b]==true) {
                print("POSSIBLE");
                return 0;
            }
            route[b] = true;
        } else if (b==n-1) {
            if (route[a]==true) {
                print("POSSIBLE");
                return 0;
            }
            route[a] = true;
        }
    }
    print("IMPOSSIBLE");
}