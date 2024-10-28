#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'
#define MOD 1000000007
using i64 = long long;
using pi = pair<int, int>;
vector<int> a, v;
vector<bool> vis;
vector<vector<int>> rev_graph;
void dfs(int n) {
	if (vis[n]) return;
	vis[n] = true;
	for (int ch: rev_graph[n]) dfs(ch);
}

int min_in_cycle(int curr) {
	int t = a[curr], h = a[a[curr]];
	while (t != h) {
		t = a[t];
		h = a[a[h]];
	}

	int min_v = v[t];
	t = a[t];
	while (t != h) {
		min_v = min(min_v, v[t]);
		t = a[t];
	}

	dfs(t);
	return min_v;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int nsz;
	cin >> nsz;
	v.resize(nsz), a.resize(nsz);
	vis.resize(nsz), rev_graph.resize(nsz);

	i64 max_moos = 0;
	for (int i = 0; i < nsz; i++) {
		cin >> a[i] >> v[i];
		a[i] -= 1;
		rev_graph[a[i]].push_back(i);
		max_moos += v[i];
	}

	for (int i = 0; i < nsz; i++) if (!vis[i]) {
		max_moos -= min_in_cycle(i);
	}

	cout << max_moos << el;
	return 0;
}
