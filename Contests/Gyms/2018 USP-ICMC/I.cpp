#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q;	cin >> n >> q;
	vector<vector<int>> g;
	vector<int> indeg(n);
	for (int u = 0, v; u < n; ++u) {
		cin >> v;
		if (v != -1) {
			g[u].push_back(v); // ->
			indeg[v]++;
		}
	}

	vector<int> roots;
	for (int i = 0; i < n; ++i) if (indeg[i] == 0) {
		roots.push_back(i);
	}

	vector<set<int>> cnt((int)roots.size());
	function<void(int,int,unordered_set)> dfs = [&](int v, int V, unordered_set<int>& st) {
		st.insert(v);
		for (auto &vv: g[v]) if (vv != V) {
			dfs(vv, v, st);
		}
	};

	int id = 0;
	for (auto &r: roots) {
		dfs(r, -1, cnt[id++]);
	}



	return 0;
}
