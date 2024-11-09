#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

vector<int> par, sz;
void init(int size) {
	par = vector<int>(size);
	sz = vector<int>(size, 1);
	for (int i = 0; i < size; i++) par[i] = i;
}

int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
void unite(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot != yRoot) {
		if (sz[xRoot] < sz[yRoot]) swap(x, y);
		sz[xRoot] += sz[yRoot], par[yRoot] = xRoot;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		init(n);
		vector<pair<ll, ll>> c(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			c[i] = {x, y};
		}

		int m;
		cin >> m;
		bool taken[755][755] = {0};
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			unite(--u, --v);
			taken[u][v] = true;
		}
		
		set<tuple<ll, int, int>> e;
		for (int u = 0; u < n; u++) {
			for (int v = u + 1; v < n; v++) {
				if (!taken[u][v]) {
					ll w = 0;
					w += (c[u].fst - c[v].fst) * (c[u].fst - c[v].fst);
					w += (c[u].scd - c[v].scd) * (c[u].scd - c[v].scd);
					e.insert({w, u, v});
				}
			}
		}

		vector<pair<int, int>> ans;
		for (auto const &[w, u, v]: e) {
			if (find(u) != find(v)) {
				unite(u, v);
				ans.push_back({u + 1, v + 1});
			}
		}

		if (ans.size() == 0) cout << "No new highways need" << el;
		else for (auto pr: ans) cout << pr.fst << " " << pr.scd << el;
		if (t > 0) cout << el;
	}

	return 0;
}
