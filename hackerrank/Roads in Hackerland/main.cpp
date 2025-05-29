#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
    vector<int> par;
    DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
    
    int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
    bool unite(int u, int v) {
        int U = find(u), V = find(v);
        if (U == V) return false;
        par[V] = U;
        return true;
    }
};

struct Edge {
    int u, v;
	i64 w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int n,m;
vector<i64> cnt;
vector<vector<pair<int,i64>>> g;
i64 dfs(int v, int V) {
    i64 me = 1;
    for (auto& [vv,w]: g[v]) {
        if (vv != V) {
            i64 subtreeCnt = dfs(vv, v);
            cnt[w] += 1LL * subtreeCnt * (n - subtreeCnt); 
            me += subtreeCnt;
        } 
    }
    
    return me;
}


int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    DSU mst(n);
	g.resize(n), cnt.assign(m, 0);
    vector<Edge> edges;
    
    for (int i = 0, u, v; i < m; ++i) {
		i64 w;
		cin >> u >> v >> w;
		u -= 1, v -= 1;
        edges.push_back({u,v,w});
	}
    
    sort(edges.begin(), edges.end());
    for (auto& e: edges) if (mst.unite(e.u, e.v)) {
        g[e.u].push_back({e.v, e.w});
        g[e.v].push_back({e.u, e.w});
    }
    
    dfs(0, -1);
    
    int idx = 0;
    while (idx < m || cnt[idx]) {
		if (idx+1 >= m) cnt.push_back(0);
        cnt[idx+1] += (cnt[idx] / 2);
        cnt[idx] %= 2;
        idx += 1;
    }
    
    while (cnt.size() > 1 && cnt.back() == 0) cnt.pop_back();
    reverse(cnt.begin(), cnt.end());
	for (auto& x: cnt) cout << x;
	return 0;
}
