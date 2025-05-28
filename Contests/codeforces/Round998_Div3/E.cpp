#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
	int find(int v) { return v==par[v] ? v: par[v]=find(par[v]); }
	void unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U != V) par[U] = V;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n,m1,m2; cin >> n >> m1 >> m2;
		vector<pair<int,int>> f,g;
		DSU df(n+1), dg(n+1);

		for (int i = 0; i < m1; ++i) {
			int u,v; cin >> u >> v;
			f.push_back({min(u,v), max(u,v)});
		}

		for (int i = 0; i < m2; ++i) {
			int u,v; cin >> u >> v;
			g.push_back({min(u,v), max(u,v)});
			dg.unite(u,v);
		}

		int rem = 0, add = 0;
		for (auto& e: f) {
			if (dg.find(e.first) == dg.find(e.second))
				df.unite(e.first, e.second);
			else e.first = 0, e.second = 0, rem += 1;
		}

		for (auto& e: g) {
			if (df.find(e.first) != df.find(e.second)) {
				df.unite(e.first, e.second);
				add += 1;
			}
		}

		cout << rem+add << el;
	}

	return 0;
}

