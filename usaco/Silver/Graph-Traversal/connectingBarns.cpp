#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

void dfs(const vector<vector<int>>& edges, vector<int>& component, const int currV, const int id) {
	for (int child: edges[currV]) {
		if (component[child] != id) {
			component[child] = id;
			dfs(edges, component, child, id);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<int> component(n);
	iota(component.begin(), component.end(), 0);
	for (int i = 0; i < n; i++) if (component[i] == i) {
		dfs(edges, component, i, i);
	}

	if (component[0] == component[n - 1]) {
		cout << 0 << el;
		return;
	}

	vector<vector<int>> componentToVertices(n);
	for (int i = 0; i < n; i++) componentToVertices[component[i]].push_back(i);

	ll ans = 1e18;
	vector<ll> srccost(n, 1e9);
	vector<ll> dstcost(n, 1e9);

	int srcidx = 0, dstidx = 0;
	for (int i = 0; i < n; i++) {
		while (srcidx < componentToVertices[component[0]].size()) {
			srccost[component[i]] = min(srccost[component[i]], (ll)abs(i - componentToVertices[component[0]][srcidx]));
			if (componentToVertices[component[0]][srcidx] < i) srcidx++;
			else break;
		}

		if (srcidx) srcidx--;

		while (dstidx < componentToVertices[component[n-1]].size()) {
			dstcost[component[i]] = min(dstcost[component[i]], (ll)abs(i - componentToVertices[component[n-1]][dstidx]));
			if (componentToVertices[component[n-1]][dstidx] < i) dstidx++;
			else break;
		}

		if (dstidx) dstidx--;
	}

	for (int i = 0; i < n; i++) ans = min(ans, srccost[i] * srccost[i] + dstcost[i] * dstcost[i]);
	cout << ans << el;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}
