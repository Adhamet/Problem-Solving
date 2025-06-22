#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	bool same(int u, int v) { return find(u) == find(v); }
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return false;
		par[v] = u;
		return true;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	vector<array<i64, 2>> p;
	p.reserve(n + q);
	for (int i = 0; i < n; ++i) {
		i64 x, y; cin >> x >> y;
		p.push_back({x, y});
	}

	using T = tuple<i64, int, int>;
	auto cmp = [](const T &a, const T &b) {
		return get<0>(a) > get<0>(b);
	};

	priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			i64 md = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
			pq.emplace(md, i, j);
		}
	}

	DSU dsu(n + q);
	while (q--) {
		int type;
		cin >> type;

		if (type == 1) {
			i64 x, y;
			cin >> x >> y;
			int id = (int)p.size();
			for (int i = 0; i < id; ++i) {
				i64 md = abs(p[i][0] - x) + abs(p[i][1] - y);
				pq.emplace(md, i, id);
			}

			p.push_back({x, y});
		} else if (type == 2) {
			i64 ans = -1;
			while (!pq.empty()) {
				auto [w, u, v] = pq.top();
				pq.pop();
				if (!dsu.same(u, v)) {
					ans = w;
					dsu.unite(u, v);
					while (!pq.empty() && get<0>(pq.top()) == w) {
						auto [_, u2, v2] = pq.top();
						pq.pop();
						dsu.unite(u2, v2);
					}

					break;
				}
			}

			cout << ans << el;
		} else if (type == 3) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			cout << (dsu.same(u, v) ? "Yes" : "No") << el;
		}
	}

	return 0;
}
