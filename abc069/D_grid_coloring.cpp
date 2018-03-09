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
    int h,w; cin>>h>>w;
    int n; cin>>n;
    vvi grid(h, vi(w));
    int color=1;
    int p=0;

    // 左上から塗りつぶす
    rep(i, n) {
        int a; cin>>a;
        rep(j, a) {
            grid[p/w][p%w] = color;
            p++;
        }
        color++;
    }

    // 1-indexでの偶数行目を折り返す
    rep(i, h) {
        if (i%2==0) continue;
        rep(j, w/2) {
            swap(grid[i][j], grid[i][w-1-j]);
        }
    }
    rep(i, h) {
        rep(j, w) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}