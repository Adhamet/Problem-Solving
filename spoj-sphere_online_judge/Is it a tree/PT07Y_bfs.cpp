#include <bits/stdc++.h>
using namespace std;
 
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'
 
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
// const int mx = 1e5+5;
// const int oo = 1e9 + 20;
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adjL[n + 1];
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		vis[node] = true;
		q.pop();

		for (auto child: adjL[node]) if (!vis[child]) {
			q.push(child);
		}
	}

	for (int i = 1; i <= n; i++) if (vis[i] == false) {
		return cout << "NO" << el, 0;
	}

	cout << (n == m + 1 ? "YES": "NO") << el;
	return 0;
}
