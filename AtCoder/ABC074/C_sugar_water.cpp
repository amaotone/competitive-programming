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
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    int ans_sugar=0;
    int ans_total=100*a;
    double conc_max = 0.0;
    repi(wi, f/(100*a)) {
        repi(wj, f/(100*b)) {
            int water = (wi*a+wj*b)*100;
            if (water==0 or water>f) break;
            repi(si, f/c) {
                repi(sj, f/d) {
                    int sugar = si*c+sj*d;
                    if (water+sugar>f) break;
                    double conc = 100.0*sugar/(sugar+water);
                    if (conc>conc_max and 1.0*water*e/100>=sugar) {
                        conc_max = conc;
                        ans_sugar = sugar;
                        ans_total = sugar+water;
                    }
                }
            }
        }
    }
    printf("%d %d\n", ans_total, ans_sugar);
}