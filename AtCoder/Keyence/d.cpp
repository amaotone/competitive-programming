// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i = (a); (i) < (b); (i)++)
#define FORS(i, a, b) for (int i = (a); (i) <= (b); (i)++)
#define REP(i, n) for (int i = 0; (i) < (n); (i)++)
#define REPS(i, n) for (int i = 1; (i) <= (n); (i)++)
#define RREP(i, n) for (int i = (n - 1); (i) >= 0; (i)--)
#define RREPS(i, n) for (int i = n; (i) > 0; (i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout << (x) << "\n")
#define MOD 1000000007

// LIBRARY

// SOLVE
void solve()
{
    int N, M; cin>>N>>M;
    vi A(N); REP(i, N) cin>>A[i];
    vi B(M); REP(i, M) cin>>B[i];
    set<int> setA(A.begin(), A.end());
    set<int> setB(B.begin(), B.end());
    if (A.size() != setA.size() || B.size() != setB.size()) {
        print(0);
        return;
    }
    vi inA(N*M+1);
    vi inB(N*M+1);
    vi lA(N*M+1);
    vi lB(N*M+1);
    REP(i, A.size()) {
        inA[A[i]]= 1;
        REP(j, A[i]) {
            lA[j] += 1;
        }
    }
    REP(i, B.size()){
        inB[B[i]] = 1;
        REP(j, B[i]) {
            lB[j] += 1;
        }
    }
    ll ans = 1;
    RREPS(x, N*M) {
        int checked = N*M-x;
        if (inA[x] && inB[x]) continue;
        else if (inA[x]) ans = ans * lB[x] % MOD;
        else if (inB[x]) ans = ans * lA[x] % MOD;
        else ans = ans * (lA[x] * lB[x] - checked) % MOD;
        // print(x);
        // print(ans);
    }
    print(ans);
}
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
