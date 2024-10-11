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
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("wormsort");

	int n, m;
	cin >> n >> m;

	int numToSort = 0;
	vector<bool> to_sort(n + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (i + 1 != x) to_sort[i + 1] = true, numToSort += 1;
		else to_sort[i + 1] = false;
	}

	vector<int> widths(m);
	vector<pi> adjL[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		widths[i] = w;
		adjL[u].push_back({v, w});
		adjL[v].push_back({u, w});
	}

	if (numToSort == 0) {
			cout << -1 << el;
			return 0;
	}

	sort(widths.begin(), widths.end());
	
	int sortedNodes = 0;
	vector<bool> vis(n + 1);
	function<void(int, int)> dfs = [&](int node, int width) -> void {
		vis[node] = true;

		if (to_sort[node]) sortedNodes += 1;
		for (auto child: adjL[node]) {
			if (!vis[child.first] && child.second >= width) {
				dfs(child.first, width);
			}
		}
	};

	int l = 0, r = m - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;

		sortedNodes = 0;
		fill(vis.begin(), vis.end(), false);
		dfs(1, widths[mid]);
		
		if (sortedNodes == numToSort) l = mid + 1, ans = mid;
		else r = mid - 1;
	}

	cout << widths[ans] << el;

	return 0;
}
