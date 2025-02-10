#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

vector<int> a;
vector<vector<int>> graph;
vector<bool> vis;
int dfs(int node) {
	vis[node] = 1;
	int ret = 0;
	for (auto child: graph[node]) {
		if (!vis[child]) ret += dfs(child);
	}

	ret += 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		a = vector<int>(n + 1);
		vis = vector<bool>(n + 1, 0);
		graph = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i], graph[a[i]].push_back(i);

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;

			int tortoise = i, hare = i;
			do {
				tortoise = a[tortoise];
				hare = a[a[hare]];
			} while (tortoise != hare);

			do {
				vis[tortoise] = true;
				tortoise = a[tortoise];
			} while (tortoise != hare);

			do {
				for (int child: graph[tortoise]) {
					if (!vis[child]) ans = max(ans, dfs(child));
				}

				tortoise = a[tortoise];
			} while (tortoise != hare);
		}

		cout << ans + 2 << el;
	}

	return 0;
}
