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
#define MAX 100002
int main() {
    int n; cin>>n;
    vi a(MAX);
    rep(i, n) {
        int t; cin>>t;
        a[t]++;
        a[t+1]++;
        a[t+2]++;
    }
    int t = 0;
    int ans;
    rep(i, MAX) {
        if (a[i]>t) {
            ans=i;
            t=a[i];
        }
    }
    print(a[ans]);
}