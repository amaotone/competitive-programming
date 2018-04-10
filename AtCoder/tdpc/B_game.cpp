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

#define MAX 1000+1

bool isFirst(int i, int j, int A, int B) {
    return (A+B)-(i+j)%2==0;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int A, B; cin >> A >> B;
    vi Ad(A); rep(i, A) cin >> Ad[i];
    vi Bd(B); rep(i, B) cin >> Bd[i];

    vvi dp(MAX, vi(MAX));  // Aがi個、Bがj個あるときの先手の最大利益
    repi(i, A) {
        repi(j, B) {
            if (i==0 and j==0) {
                dp[i][j] = 0;
            } else if (i==0) {
                if (isFirst(i, j, A, B)) dp[i][j] = dp[i][j-1] + Bd[B-j];
                else dp[i][j] = dp[i][j-1];
            } else if (j==0) {
                if (isFirst(i, j, A, B)) dp[i][j] = dp[i-1][j] + Ad[A-i];
                else dp[i][j] = dp[i-1][j];
            } else {
                if (isFirst(i, j, A, B)) dp[i][j] = max(dp[i-1][j] + Ad[A-i], dp[i][j-1] + Bd[B-j]);
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[A][B] << endl;
}
