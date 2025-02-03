#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int N = 1e5+20, M = 4e5+10, oo = 1e18+10;
int n, m, k, dist[N], ans;
bool mark[N];
vector<array<int, 2>> g[N], t[N];

void DIJK() {
	set<array<int, 2>> st;
	for (int i = 0; i < n; ++i) st.insert({dist[i], i});

	while (!st.empty()) {
		int u = (*st.begin())[1]; st.erase(st.begin());
		for (const auto& edge: g[u]) {
			int v = edge[0], w = edge[1];
			if (dist[v] > dist[u] + w || (dist[v] == dist[u] + w && mark[v])) {
				st.erase({dist[v], v});
				dist[v] = dist[u] + w;
				if (mark[v]) mark[v] = 0, --ans;
				st.insert({dist[v], v});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w; u--, v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	fill(dist, dist + n, oo);
	dist[0] = 0;
	for (int i = 0, v, w; i < k; ++i) {
		cin >> v >> w; v--;
		dist[v] = min(dist[v], w);
		if (!mark[v]) mark[v] = 1, ans += 1;
	}

	DIJK();
	return cout << k - ans, 0;
}
