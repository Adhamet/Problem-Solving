#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int MAXN = 2e5 + 5;
int n, m, k, mxSz, curr;
vector<bool> vis(MAXN);
vector<int> adjL[MAXN], ans[MAXN];
void add(int child) {
	if (ans[curr].size() == mxSz) curr += 1;
	ans[curr].push_back(child);
}

void dfs(int node) {
	add(node);
	vis[node] = true;
	for (int child: adjL[node]) if (!vis[child]) {
		dfs(child);
		add(node);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	
	mxSz = (2 * n + k - 1) / k;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	dfs(0);
	for (int i = 0; i < k; ++i) {
		if (ans[i].empty()) ans[i].push_back(0);
		cout << ans[i].size();
		for (auto val: ans[i]) cout << " " << val + 1;
		cout << el;
	}

	return 0;
}
