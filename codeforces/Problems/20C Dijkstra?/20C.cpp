#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);

    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    vector<int> dist(n, oo), par(n, -1);
    priority_queue<array<int, 2>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
		int d = -pq.top()[0], v = pq.top()[1];
        pq.pop();

		if (v == n - 1) break;
        if (d > dist[v]) continue;
        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                par[u] = v;
                pq.push({-dist[u], u});
            }
        }
    }

    if (dist[n - 1] == oo) {
        cout << -1 << el;
        return 0;
    }

    vector<int> path;
    for (int v = n - 1; v != -1; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    for (auto v : path) cout << v + 1 << ' ';
    return 0;
}

