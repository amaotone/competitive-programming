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
