// TEMPLATE
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <utility>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> P;
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (int i=0;(i)<(n);(i)++)
#define repi(i, n) for (int i=0;(i)<=(n);(i)++)
#define repr(i, n) for (int i=n;(i)>=0;(i)--)
#define INF (1<<29)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")

// LIBRARY
using Weight = int;
struct Edge{
    int to; 
    Weight cost;
    Edge(int to, Weight cost):to(to),cost(cost){}
};
using Graph = vector<vector<Edge>>;

vector<Weight> dijkstra(const Graph &G, int s) {
    // P=(cost, vertex)
    priority_queue<P, vector<P>, greater<P>> que;
    int V = G.size();
    vector<Weight> d(V); d.assign(V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (not que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()) {
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d;
}

// SOLVE
const ll MOD = 1e9 + 7;

using wpair = pair<int, Weight>;  // (index, distance)
bool lessWpair(const wpair &i, const wpair &j){return i.second < j.second;}
vector<ll> countPath(const Graph &graph, const vector<Weight> &d) {
    int n = d.size();
    vector<wpair> v;
    vector<ll> dp(n);
    rep(i, n) {
        v.push_back(wpair(i, d[i]));
    }
    sort(all(v), lessWpair);
    rep(i, d.size()) {
        int id = v[i].first;
        if (i==0) dp[id]=1;  // 始点は1通り
        rep(j, graph[id].size()) {
            Edge e = graph[id][j];
            if (d[id]+e.cost==d[e.to]) (dp[e.to]+=dp[id])%=MOD;
        }
    }
    return dp;
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    int s, t; cin>>s>>t;
    s--; t--;

    // グラフを作る
    vector<vector<Edge>> G(n);
    rep(i, m) {
        int u, v; Weight d; cin>>u>>v>>d;
        u--; v--;
        G[u].push_back(Edge(v, d));
        G[v].push_back(Edge(u, d));
    }

    // Sからの距離、Tからの距離を出す
    auto ds = dijkstra(G, s);
    auto dt = dijkstra(G, t);
    
    // 動的計画法で場合の数を出す
    auto dps = countPath(G, ds);
    auto dpt = countPath(G, dt);

    // カウント
    ll cnt = dps[t]*dpt[s];
    rep(a, n) {
        // 頂点で出会う場合
        if (ds[a]*2==ds[t]) cnt-=dps[a]*dpt[a];
        // 辺で出会う場合
        rep(i, G[a].size()) {
            int b = G[a][i].to;
            if (ds[a]*2<ds[t] and dt[b]*2<dt[s] 
                and ds[a]+G[a][i].cost==ds[b]) cnt -= dps[a]*dpt[b];
        }
    }
    print(cnt);
} 