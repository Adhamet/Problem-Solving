#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 1005;
vector<bool> blocked(MAXN, false);
void dfs(int node, vector<vector<int>>& list) {
	blocked[node] = true;
	for (auto child: list[node]) if (!blocked[child]) {
		dfs(child, list);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, u, v;
	cin >> n;
	cin.ignore();
	vector<vector<int>> parents(n), children(n);
	
	string s;
	while (getline(cin, s)) {
		if (s == "BLOOD") break;
		istringstream iss(s);
		iss >> u >> v;
		parents[--u].push_back(--v);
		children[v].push_back(u);
	}

	int dead;
	while (cin >> dead) {
		if (!blocked[dead - 1]) {
			dfs(dead - 1, parents);
			dfs(dead - 1, children);
		}
	}

	bool ok = false;
	for (int i = 0; i < n; i++) if (!blocked[i]) {
		ok = true;
		cout << i + 1 << " ";
	}

	if (!ok) cout << 0;
	return 0;
}
