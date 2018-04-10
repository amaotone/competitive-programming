/**
* UnionFind木
* Veryfied: ATC001 B <https://atc001.contest.atcoder.jp/tasks/unionfind_a>
*/
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

void AtCoder_UnionFind() {
    int N, Q; cin>>N>>Q;
    UnionFind uf(N);
    REP(i, Q) {
        int P, A, B; cin>>P>>A>>B;
        if (P==0) uf.unite(A, B);
        if (P==1) print(uf.same(A, B) ? "Yes" : "No");
    }
}

int main() {
    AtCoder_UnionFind();
}