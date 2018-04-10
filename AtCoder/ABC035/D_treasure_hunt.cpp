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
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i=(a);(i)<(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define REPS(i, n) for (int i=1;(i)<=(n);(i)++)
#define RREP(i, n) for (int i=(x-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")
#define INF (1<<29)

// LIBRARY
using Weight = ll;
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
    vector<Weight> d(V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (not que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        REP(i, G[v].size()) {
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
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int n, m; ll t; cin>>n>>m>>t;
    vector<ll> A(n); REP(i, n) cin>>A[i];
    Graph G1(n);
    Graph G2(n);
    REP(i, m) {
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        G1[a].push_back(Edge(b, c));
        G2[b].push_back(Edge(a, c));
    }    
    auto d1 = dijkstra(G1, 0);
    auto d2 = dijkstra(G2, 0);
    ll ans=0;
    REP(i, n) {
        if (d1[i]+d2[i]>t) continue; 
        ans = max(ans, A[i]*(t-d1[i]-d2[i]));
    }
    print(ans);
}