#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	bool unite(int u, int v) {
		int U = find(u), V = find(v);
		if (U == V) return false;
		par[V] = U;
		return true;
	}
};

struct Edge {
	int u, v, w, idx;
	bool isCapital;
};

i32 main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i32 n, m, k; cin >> n >> m >> k;
	vector<Edge> edges;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		u--, v--;
		bool isCap = (u == 0 || v == 0);
		edges.push_back({u, v, w * 2, i, isCap});
	}

	auto buildMST = [&](i64 P, vector<int>* result = nullptr, bool use = false) {
		vector<Edge> edges2 = edges;
		for (auto& e : edges2) if (e.isCapital) e.w += P;

		sort(edges2.begin(), edges2.end(), [](const Edge& a, const Edge& b) {
			return a.w < b.w;
		});

		DSU dsu(n);
		i32 capCount = 0;
		i64 cost = 0;
		if (result) result->clear();

		for (auto& e: edges2) {
			if (dsu.unite(e.u, e.v)) {
				if (e.isCapital) capCount++;
				if (use) cost += e.w - P * e.isCapital;
				else cost += e.w;
				if (result) result->push_back(e.idx + 1);
			}
		}

		return pair(capCount, cost);
	};

	i64 l = -1e6, r = 1e6, bestP = -1, bestCost = LLONG_MAX;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		auto [cnt, cost] = buildMST(mid);
		if (cnt >= k) {
			if (cnt == k && cost < bestCost) bestCost = cost, bestP = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	if (bestP == -1) return cout << -1, 0;

	vector<int> ans;
	auto [cnt, _] = buildMST(bestP, &ans, true);
	if ((int)ans.size() != n - 1 || cnt != k) return cout << -1, 0;

	cout << ans.size() << el;
	for (int id : ans) cout << id << ' ';
}

