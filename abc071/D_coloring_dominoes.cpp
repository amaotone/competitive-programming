#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>
#include <numeric>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i=0;(i)<(n);(i)++)
#define repi(i, n) for (int i=0;(i)<=(n);(i)++)
#define repr(i, n) for (int i=n;(i)>=0;(i)--)
#define print(x) (cout<<x<<endl)
#define MOD 1000000007

int main() {
    int n; cin>>n;
    string upper; cin>>upper;
    string lower; cin>>lower;

    int p=0;
    ll ans=1;
    bool last_port=false;
    while (p<n) {
        bool port = (upper[p]==lower[p]);
        if (p==0) {
            ans *= (port ? 3 : 6);
        } else {
            if (last_port) ans=(ans*2)%MOD;
            else if (not port) ans=(ans*3)%MOD;
        }
        last_port = port;
        p += (last_port ? 1 : 2);
    }
    print(ans);
}