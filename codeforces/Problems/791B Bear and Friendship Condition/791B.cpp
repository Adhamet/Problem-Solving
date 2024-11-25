#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

const int MAXN = 1e6 + 10;
bool vis[MAXN];
vector<int> adjL[MAXN];
ll cnt, ans;
void dfs(int node) {
	vis[node] = true;
	for (auto child: adjL[node]) if (!vis[child]) {
		cnt += 1, dfs(child);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjL[--u].push_back(--v);
		adjL[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		cnt = 1;
		if (!vis[i]) {
			dfs(i);
			ans += cnt * (cnt - 1) / 2;
		}
	}

	if (ans == m) cout << "YES";
	else cout << "NO";
	return 0;
}
