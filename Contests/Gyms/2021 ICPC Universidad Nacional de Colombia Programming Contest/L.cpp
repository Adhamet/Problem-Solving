#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q;	cin >> n >> q;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	i64 tot = 0;
	vector<int> upds(q);
	for (int i = 0; i < q; ++i) cin >> upds[i], tot += upds[i];

	const i64 MXSUM = 1e6+5;
	bitset<MXSUM> bs;
	bs.reset();
	bs[0] = 1;
	for (int i = 0; i < q; ++i) bs |= (bs << upds[i]);
	vector<i64> sums;
	for (int i = 0; i < MXSUM; ++i) if (bs[i]) sums.push_back(i);

	vector<i64> req(n), need(n);
	bool acc = true;
	function<void(int,int)> dfs = [&](int v, int V) {
		i64 mx = a[v];
		for (auto& vv: g[v]) if (vv != V) {
			dfs(vv, v);
			mx = max(mx, req[vv]);
		}

		req[v] = mx;
		need[v] = mx - a[v];
		auto val = lower_bound(sums.begin(), sums.end(), need[v]);
		if (val == sums.end()) {
			acc = false;
			return;
		} else a[v] += (*val), req[v] = a[v];
	};

	dfs(0, -1);
	i64 mxVal = *max_element(need.begin(), need.end());
	if (mxVal > tot || !acc) return cout << -1, 0;

	i64 ans = 0;
	for (int i = 0; i < n; ++i) ans += a[i];
	return cout << ans, 0;
}
