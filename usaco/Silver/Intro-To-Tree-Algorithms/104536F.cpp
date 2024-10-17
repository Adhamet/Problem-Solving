#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

pi dfs(const vector<vector<int>> &tree, int node = 1, int prev = 0,  int dist = 0) {
    pi farthest = {node, dist};

    for (auto child: tree[node]) if (child != prev) {
        auto candidate = dfs(tree, child, node, dist + 1);
        if (candidate.second > farthest.second) farthest = candidate;
    }

    return farthest;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	vector<vector<int>> tree1(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree1[u].push_back(v);
		tree1[v].push_back(u);
	}

	int m;
	cin >> m;
	vector<vector<int>> tree2(m + 1);
	for (int i = 0; i < m - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree2[u].push_back(v);
		tree2[v].push_back(u);
	}

	int tree1_start = dfs(tree1).first;
	int tree2_start = dfs(tree2).first;
	int tree1_diameter = dfs(tree1, tree1_start).second;
	int tree2_diameter = dfs(tree2, tree2_start).second;
	
	int added_edge_diameter = (tree1_diameter + 1) / 2 + (tree2_diameter + 1) / 2 + 1;
	cout << max({added_edge_diameter, tree1_diameter, tree2_diameter});
	return 0;
}
