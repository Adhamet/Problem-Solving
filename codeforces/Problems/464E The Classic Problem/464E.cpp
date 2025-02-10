#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int oo = 1e18+10, MOD = 1000000007;
int _pow(int a, int b) {
	int res = 1;
	a %= MOD;
	while (b > 0) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<array<int, 2>>> g(n);
	for (int i = 0, u, v, x; i < m; ++i) {
		cin >> u >> v >> x;
		u--, v--;

		int w = _pow(2, x);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	int s, f;
	cin >> s >> f;
	s--, f--;

	vector<int> dist(n, oo), par(n, -1);
	priority_queue<array<int, 2>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while (!pq.empty()) {
		int d = -pq.top()[0], v = pq.top()[1];
		pq.pop();

		if (v == f) break;
		if (dist[v] < d) continue;
		for (auto& [u, w]: g[v]) {
			if (dist[u] > dist[v] + w) {
				dist[u] = (dist[v] + w) % MOD;
				par[u] = v;
				pq.push({-dist[u], u});
			}
		}
	}

	if (dist[f] == oo) return cout << -1, 0;
	
	vector<int> path;
	for (int v = f; v != -1; v = par[v]) path.push_back(v);
	reverse(path.begin(), path.end());

	cout << dist[f] << el;
	cout << (int)path.size() << el;
	for (auto& v: path) cout << v + 1 << ' ';
	return 0;
}
