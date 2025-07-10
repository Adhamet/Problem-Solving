#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,char>>> g(n);
	for (int i = 0, u, v; i < m; ++i) {
		char c;
		cin >> u >> v >> c;
		--u; --v;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
	}

	auto bfs = [&](int start) {
		vector<int> dist(n, INT_MAX);
		queue<int> q;
		vector<bool> vis(n, false);
		dist[start] = 0;
		vis[start] = true;
		q.push(start);

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &[v, _]: g[u]) {
				if (!vis[v]) {
					vis[v] = true;
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}

		return dist;
	};

	auto distFrom1 = bfs(0);
	auto distFromN = bfs(n-1);
	const int SL = distFrom1[n-1];
	cout << SL << el;

	vector<int> par(n, -1);
	vector<int> cur{0}, nxt;
	string ans;
	ans.reserve(SL);
	for (int l = 0; l < SL; ++l) {
		char best = 'z'+1;
		for (auto& v: cur) {
			for (auto &[vv, c]: g[v]) {
				if (distFrom1[v]+1 == distFrom1[vv])
					if (distFrom1[vv]+distFromN[vv]==SL)
						best = min(best, c);
			}
		}
		ans.push_back(best);
		
		nxt.clear();
		for (auto& v: cur) {
			for (auto &[vv, c]: g[v]) {
				if (c == best && distFrom1[v]+1==distFrom1[vv])
					if (distFrom1[vv]+distFromN[vv]==SL)
						if (par[vv]==-1) {
							par[vv]=v;
							nxt.push_back(vv);
				}
			}
		}

		cur.swap(nxt);
	}

	vector<int> path;
	for (int v = n - 1; v != -1; v = par[v])
		path.push_back(v);
	reverse(path.begin(), path.end());

	for (auto& v: path) cout << v+1 << ' ';
	return cout << el << ans, 0;
}

