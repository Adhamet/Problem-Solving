#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
#define MOD 1000000007

struct edge {
	int from, to, w;
};

const int MAXN = 123456, oo = 1e18+10;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, st, fini;
	cin >> n >> m >> st >> fini;
	--st, --fini;

	vector<vector<edge>> edges(MAXN), redges(MAXN);
	vector<edge> gen(m);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u, --v;
		edges[u].push_back({u, v, w});
		redges[v].push_back({v, u, w});
		gen[i] = {u, v, w};
	}

	auto djikstra = [&](int start, vector<int>& dist, vector<int>& ways) {
		dist[start] = 0, ways[start] = 1;
		set<pair<int, int>> q;
		q.insert({0, start});

		while (!q.empty()) {
			auto [_, v] = *q.begin();
			q.erase(q.begin());

			for (edge& e: edges[v]) {
				if (dist[e.to] > dist[e.from] + e.w) {
					q.erase({dist[e.to], e.to});
					ways[e.to] = ways[e.from];
					dist[e.to] = dist[e.from] + e.w;
					q.insert({dist[e.to], e.to});
				} else if (dist[e.to] == dist[e.from] + e.w) {
					ways[e.to] = (ways[e.to] + ways[e.from]) % MOD;
				}
			}
		}
	};

	vector<int> distS(n, oo), waysS(n);
	djikstra(st, distS, waysS);
	edges.swap(redges);
	vector<int> distF(n, oo), waysF(n);
	djikstra(fini, distF, waysF);
	edges.swap(redges);
	
	int shortest = distS[fini], totWays = waysS[fini];
	for (int i = 0; i < m; ++i) {
		edge& e = gen[i];
		if (distS[e.from] + distF[e.to] + e.w == shortest && ((waysS[e.from]%MOD) * (waysF[e.to]%MOD))%MOD == totWays%MOD) {
			cout << "YES" << el;
		} else {
			int required = (shortest - 1) - distS[e.from] - distF[e.to];
			if (required >= 1) cout << "CAN " << e.w - required << el;
			else cout << "NO" << el;
		}
	}

	return 0;
}
