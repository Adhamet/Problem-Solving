#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr i64 oo = INT64_MAX/4;
	struct Edge { int u, v;	i64 w;};
	
	while (true) {
		int n, b;	cin >> n >> b;
		if (n == 0 && b == 0) break;

		vector<Edge> edges;
		for (int i = 0, u, v; i < b; ++i) {
			i64 w;	cin >> u >> v >> w;
			edges.push_back({u,v,w});
			edges.push_back({v,u,-w});
		}

		vector<i64> d(n + 1, oo);	d[1] = 0;
		for (int i = 1; i < n; ++i) {
			bool upd = false;
			for (auto &[u,v,w]: edges) if (d[u] < oo && d[u] + w < d[v])
				d[v] = d[u] + w, upd = true;
			if (!upd) break;
		}

		bool negcyc = false;
		for (auto [u,v,w]: edges) if (d[u] < oo && d[u] + w < d[v]) {
			negcyc = true;
			break;
		}

		cout << (negcyc? 'Y': 'N') << el;
	}

	return 0;
}
