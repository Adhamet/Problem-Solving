#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 1e6 + 5;
int total, f = -1, s = - 1;
vector<int> temp(MAXN);
vector<vector<int>> graph(MAXN);
int dfs(int node, int par) {
	int subTreeSum = 0, backtrackSum = 0;
	for (auto child: graph[node]) if (child != par) {
		backtrackSum = dfs(child, node);
		subTreeSum += backtrackSum;
		if (backtrackSum == total) {
			if (f == -1) f = child + 1, subTreeSum -= backtrackSum;
			else s = child + 1;
		}
	}

	return subTreeSum + temp[node];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, root;
	cin >> n;
	for (int u = 0, v; u < n; ++u) {
		cin >> v >> temp[u];
		total += temp[u];
		if (v) {
			graph[u].push_back(v - 1);
			graph[v - 1].push_back(u);
		} else root = u;
	}

	if (total % 3 == 0) total /= 3, dfs(root, -1);
	if (f != -1 && s != -1) cout << f << " " << s;
	else cout << -1;
	return 0;
}
