#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<bool> vis(n);
		vector<pair<ll, int>> adjL[n];
		for (int u = 0; u < n; u++) {
			string trash;	cin >> trash;

			int neighs;
			cin >> neighs;
			while (neighs--) {
				ll w;
				int v;
				cin >> v >> w;
				adjL[u].push_back({w, --v});
			}
		}

		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({0, 0});

		ll minW = 0;
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();

			if (!vis[p.second]) {
				minW += p.first;
				vis[p.second] = true;

				for (auto child: adjL[p.second]) {
					if (!vis[child.second]) pq.push(child);
				}
			}
		}

		cout << minW << el;
	}

	return 0;
}
