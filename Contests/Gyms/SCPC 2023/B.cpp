#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<vector<int>> g(n);
		for (int i = 0, j; i < n; ++i) {
			cin >> j;
			--j;
			if (i != j) g[i].push_back(j);
		}

		bool lying = false;
		vector<int> vis(n, 0);

		function<bool(int)> dfs = [&](int v) {
			vis[v] = 1;
			for (auto &vv : g[v]) {
				if (vis[vv] == 1) return true;
				if (vis[vv] == 0 && dfs(vv)) return true;
			}

			vis[v] = 2;
			return false;
		};

		for (int i = 0; i < n; ++i) {
			if (vis[i] == 0 && dfs(i)) {
				lying = true;
				break;
			}
		}

		cout << (lying ? "Definitely Lying" : "Not Definitely Lying") << el;
	}

	return 0;
}

