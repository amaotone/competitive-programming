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
#define RREP(i, n) for (int i=(x-1);(i)>=0;(i)--)
#define RREPS(i, n) for (int i=n;(i)>0;(i)--)
#define len(x) ((int)(x).size())
#define print(x) (cout<<(x)<<"\n")

// LIBRARY
// Union-Find
struct UnionFind {
    vector<int> data;
    UnionFind(int size):data(size, -1){}
    void unite(int x, int y) {
        x = root(x); y = root(y);
        if (x==y) return;
        if (data[y]<data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }
    bool same(int x, int y) {
        return root(x)==root(y);
    }
    int root(int x) {
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

// SOLVE
signed main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int N, K, L; cin>>N>>K>>L;
    UnionFind road(N);
    UnionFind train(N);
    REP(i, K) {
        int p, q; cin>>p>>q; p--; q--;
        road.unite(p, q);
    }
    REP(i, L) {
        int p, q; cin>>p>>q; p--; q--;
        train.unite(p, q);
    }
    map<pair<int, int>, int> cnt;
    REP(i, N) {
        cnt[make_pair(road.root(i), train.root(i))]++;
    }
    REP(i, N) {
        print(cnt[make_pair(road.root(i), train.root(i))]);
    }
}