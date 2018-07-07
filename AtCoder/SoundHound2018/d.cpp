// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i=(a);(i)<(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define REPS(i, n) for (int i=1;(i)<=(n);(i)++)
#define RREP(i, n) for (int i=(n-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")
#define INF (1<<29)

// LIBRARY
using Weight = ll;
struct Edge{ ll to; Weight cost; };
using Graph = vector<vector<Edge>>;

vector<Weight> dijkstra(Graph& G, ll s) {
    using P = pair<Weight, ll>;
    vector<Weight> d(G.size(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    fill(ALL(d), INF);
    d[s] = 0;
    que.push(P{0, s});
 
    while(!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(ll i=0; i<G[v].size(); ++i) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P{d[e.to], e.to});
            }
        }
    }
    return d;
}


// SOLVE
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n, m, s, t; cin>>n>>m>>s>>t;
    s--; t--;

    Graph Yen(n);
    Graph Snu(n);
    REP(i, m) {
        ll u, v, a, b; cin>>u>>v>>a>>b;
        u--; v--;
        Yen[u].push_back((Edge){v, a});
        Yen[v].push_back((Edge){u, a});
        Snu[u].push_back((Edge){v, b});
        Snu[v].push_back((Edge){u, b});
    }
    auto d_yen = dijkstra(Yen, s);
    auto d_yen2 = dijkstra(Yen, t);
    auto d_snu = dijkstra(Snu, t);
    
    vector<ll> ans(n);
    REP(i, n) ans[i] = d_yen[i] + d_snu[i];
    RREP(i, n-1) ans[i] = min(ans[i], ans[i+1]);
    REP(i, n) {
        cout << max((ll)(1e15)-ans[i], 0LL) << endl;
    }
}