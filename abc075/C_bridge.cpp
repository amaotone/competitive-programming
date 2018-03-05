#include<iostream>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define LIMIT 50

int n, m;
int a[LIMIT], b[LIMIT];
bool graph[LIMIT][LIMIT];
bool visited[LIMIT];

void dfs(int v) {
    visited[v] = true;
    rep(next, n) {
        if (graph[v][next] == false) continue;
        if (visited[next]) continue;
        dfs(next);
    }
}

int main(void) {
    cin >> n >> m;
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    int ans = 0;
    rep(i, m) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
        rep(j, n) visited[j] = false;
        dfs(0);

        bool bridge = false;
        rep(j, n) if (visited[j]==false) bridge = true;
        if (bridge) ans++;

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
    cout << ans << endl;
}