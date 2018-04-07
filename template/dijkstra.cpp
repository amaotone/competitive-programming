// TEMPLATE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i=(a);(i)<(b);(i)++)
#define REP(i, n) for (int i=0;(i)<(n);(i)++)
#define REPS(i, n) for (int i=1;(i)<=(n);(i)++)
#define RREP(i, n) for (int i=(x-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define print(x) (cout<<(x)<<"\n")
#define INF (1<<29)

//--------------------------------------------------
// ダイクストラ

using Weight = int;
struct Edge{ int to; Weight cost; };
using Graph = vector<vector<Edge>>;

vector<Weight> dijkstra(Graph& G, int s) {
    using P = pair<Weight, int>;
    vector<Weight> d(G.size(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    fill(ALL(d), INF);
    d[s] = 0;
    que.push(P{0, s});
 
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) {
            continue;
        }
        for(int i=0; i<G[v].size(); ++i) {
            Edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P{d[e.to], e.to});
            }
        }
    }
    return d;
}



// TEST
void AOJ_GRL_1_A() {
    int V, E, r; cin>>V>>E>>r;
    Graph G(V);
    REP(i, E) {
        int s, t; Weight d; cin>>s>>t>>d;
        G[s].push_back((Edge){t, d});
    }
    auto d = dijkstra(G, r);
    REP(i, V) {
        if (d[i]==INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
} 

signed main() {
    AOJ_GRL_1_A();
}