// Kを始点とした深さ優先探索
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
    int n; cin>>n;
    int c4 = 0;
    int c2 = 0;
    rep(i, n) {
        int a; cin>>a;
        if (a%4==0) c4++;
        else if (a%2==0) c2++;
    }
    n -= c4*2+1;
    n -= (c2/2)*2;
    if (n<=0) print("Yes");
    else print("No");
}