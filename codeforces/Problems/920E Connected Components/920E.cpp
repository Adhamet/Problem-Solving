#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define el '\n'

struct DSU {
	vector<int> par, sz;
	DSU(int n): par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

	int find(int u) { return u==par[u] ? u:par[u] = find(par[u]); }
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		par[v] = u;
		return true;
	}

	int size(int u) { return sz[find(u)]; }
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	vector<set<int>> notConn(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		notConn[u].insert(v);
		notConn[v].insert(u);
	}

	DSU mst(n);
	int root = 0;
	for (int i = 1; i < n; ++i) 
		if ((int)notConn[i].size() < (int)notConn[root].size())
			root = i;

	vector<bool> vis(n, false);
	for (int i = 0; i < n; ++i) {
		if (i != root && !notConn[root].count(i)) {
			mst.unite(root, i);
			vis[i] = true;
		}
	}

	vis[root] = true;
	for (int u = 0; u < n; ++u) if (notConn[root].count(u)) {
		for (int v = 0; v < n; ++v) if (u != v && !notConn[u].count(v))
			mst.unite(u, v);
	}


	map<int, int> compSz;
	for (int i = 0; i < n; ++i) compSz[mst.find(i)]++;
	vector<int> szs;
	for (auto [_, sz] : compSz) szs.push_back(sz);
	sort(szs.begin(), szs.end());
	cout << (int)szs.size() << el;
	for (int sz: szs) cout << sz << ' ';
	return 0;
}
