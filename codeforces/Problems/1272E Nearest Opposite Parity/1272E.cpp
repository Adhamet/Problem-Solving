#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int oo = 1e18+10;
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> graph(n);

	vector<int> even, odd;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] & 1) odd.push_back(i);
		else even.push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		int left = i - a[i], right = i + a[i];
		if (left >= 0) graph[left].push_back(i);
		if (right < n) graph[right].push_back(i);
	}

	vector<int> ans(n, -1);
	auto bfs = [&](const vector<int>& start, const vector<int>& end) {
		vector<int> d(n, oo);
		queue<int> q;
		for (auto& v: start) d[v] = 0, q.push(v);

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto& to: graph[v]) if (d[to] == oo) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}

		for (auto& v: end) if (d[v] != oo) ans[v] = d[v];
	};

	bfs(odd, even), bfs(even, odd);
	for (auto it: ans) cout << it << ' ';
	return 0;
}
