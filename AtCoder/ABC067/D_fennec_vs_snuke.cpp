// お互いの場所を目指して幅優先探索
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
#define print(x) (cout<<(x)<<"\n")
#define MAX 100000
#define INF (1<<29)
vvi edge(MAX, vi(0));
vector<bool> visited(MAX);

void bfs(int start, vi &d) {
    queue<P> q;
    q.push(P(start, 0));
    while (q.size()) {
        P p = q.front(); q.pop();
        visited[p.first] = true;
        d[p.first] = p.second;
        for (int next: edge[p.first]) {
            if (next==p.first) continue;
            if (visited[next]) continue;
            q.push(P(next, p.second+1));
        }
    }
}

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int n; cin>>n;
    vi black(n);
    vi white(n);
    rep(i, n-1) {
        int a, b; cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    rep(i, n) visited[i] = false;
    bfs(0, black);
    rep(i, n) visited[i] = false;
    bfs(n-1, white);
    int f=0, s=0;
    rep(i, n) {
        if (black[i]<=white[i]) f++;
        else s++;
    }
    if (f>s) print("Fennec");
    else print("Snuke");
}