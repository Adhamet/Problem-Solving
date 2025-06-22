#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e5+5;
i64 ans = 0;
vector<int> x;
vector<vector<array<i64,2>>> g;
void dfs(int v, int V) {
	for (auto &[vv, w]: g[v]) if (vv != V) {
		dfs(vv, v);
		ans += w * abs(x[vv]);
		x[v] += x[vv];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	g.resize(n), x.resize(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0, u, v; i < n - 1; ++i) {
		i64 w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	dfs(0, -1);
	return cout << ans, 0;
}
