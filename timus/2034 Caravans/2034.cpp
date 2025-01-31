#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> settlements(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		settlements[u].push_back(v);
		settlements[v].push_back(u);
	}

	int s, f, r;
	cin >> s >> f >> r;
	s--, f--, r--;

	auto bfs = [&](int start, vector<int>& dist) {
		queue<int> q;
		q.push(start);
		dist[start] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto child: settlements[node]) if (dist[child] == -1) {
				dist[child] = dist[node] + 1;
				q.push(child);
			} 
		}
	};

	vector<int> distS(n + 1, -1);
	bfs(s, distS);
	vector<int> distR(n + 1, -1);
	bfs(r, distR);

	auto can = [&](int restrict) -> bool {
		if (distR[s] < restrict) return false;

		vector<bool> vis(n, false);
		queue<int> q;
		q.push(s);
		vis[s] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			if (node == f) return true;
			for (auto child: settlements[node]) {
				if (distS[child] != distS[node] + 1) continue;
				if (!vis[child] && distR[child] >= restrict) {
					vis[child] = true;
					q.push(child);
				}
			}
		}
		return false;
	};

	int low = 0, high = 0, worstcase = 0;
	for (int i = 1; i <= n; ++i) high = max(high, distR[i]); 
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (can(mid)) low = mid + 1, worstcase = mid;
		else high = mid - 1;
	}

	return cout << worstcase, 0;
}
