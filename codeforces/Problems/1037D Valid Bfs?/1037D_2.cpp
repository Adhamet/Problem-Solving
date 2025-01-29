#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<bool> vis(n, false);
	vector<vector<int>> graph(n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		u -= 1, v -= 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> givenSeq(n);
	for (int i = 0; i < n; ++i) cin >> givenSeq[i], givenSeq[i] -= 1;
	if (givenSeq[0] != 0) return cout << "No", 0;

	vector<int> order(n);
	for (int i = 0; i < n; ++i) order[givenSeq[i]] = i;
	for (int i = 0; i < n; ++i) {
		sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
				return order[a] < order[b];
		});
	}

	int idx = 1;
	queue<int> q;
	q.push(0);
	vis[0] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto child: graph[node]) if (!vis[child]) {
			if (idx >= n || child != givenSeq[idx]) return cout << "No", 0;
			vis[child] = true;
			q.push(child);
			idx += 1;
		}
	}

	return cout << "Yes", 0;
}
