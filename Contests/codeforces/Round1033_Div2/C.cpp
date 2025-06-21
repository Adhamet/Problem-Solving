#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		i64 n, m; cin >> n >> m;
		i64 mxAns = n*(n+1)/2;
		if (m < n || m > mxAns) {
			cout << -1 << el;
			continue;
		}

		i64 l = 1, r = n, root = n;
		while (l <= r) {
			i64 md = (l+r)>>1;
			i64 tmd = md * (2 * n - md + 1) / 2;
			if (tmd >= m) root = md, r = md - 1;
			else l = md + 1;
		}

		vector<pair<i64, i64>> edges;
		for (i64 i = root; i > 1; --i) edges.push_back({i, i - 1});
		vector<i64> nodes;
		for (i64 i = root + 1; i <= n; ++i) nodes.push_back(i);

		vector<i64> par((int)nodes.size(), root);
		i64 tval = root * (2 * n - root + 1) / 2;
		i64 rem = tval - m;
		for (int i = 0; i < (int)nodes.size(); ++i) {
			if (rem == 0) break;
			i64 diff = min(i64(rem), i64(root - 1LL));
			par[i] = root - diff;
			rem -= diff;
		}

		for (int i = 0; i < (int)nodes.size(); ++i)
			edges.push_back({par[i], nodes[i]});

		cout << root << el;
		for (auto& e: edges) cout << e.first << ' ' << e.second << el;
	} return 0;
}
