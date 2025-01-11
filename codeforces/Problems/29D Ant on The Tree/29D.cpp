#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int leafsCnt = 0;
vector<int> path;
vector<vector<int>> graph;
map<int, vector<int>> pathToLeaf;
map<pair<int, int>, int> edgeVisits;
void dfs(int node, int parent) {
	path.push_back(node);
	bool isLeaf = true;
	for (auto child : graph[node]) {
		if (child != parent) {
			isLeaf = false;
			edgeVisits[{min(node, child), max(node, child)}] = 0;
			dfs(child, node);
		}
	}

	if (isLeaf && node != 1) {
		leafsCnt += 1;
		pathToLeaf[node] = path;
	}

	path.pop_back();
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	graph.assign(n + 1, vector<int>());
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, -1);

	int leaf;
	vector<int> leafsOrder;
	for (int i = 0; i < leafsCnt; ++i) {
		cin >> leaf;
		leafsOrder.push_back(leaf);
	}

	vector<int> lastPath, ans;
	for (int i = 0; i < leafsCnt; ++i) {
		if (i == 0) {
			for (auto ele : pathToLeaf[leafsOrder[i]]) {
				ans.push_back(ele);
				lastPath.push_back(ele);
			}

			for (int j = 0; j < lastPath.size() - 1; ++j) {
				int u = lastPath[j], v = lastPath[j + 1];
				edgeVisits[{min(u, v), max(u, v)}]++;
			}
		} else {
			vector<int> currPath = pathToLeaf[leafsOrder[i]];
			int sz1 = lastPath.size(), sz2 = currPath.size(), j;
			for (j = 0; j < min(sz1, sz2); ++j) {
				if (lastPath[j] != currPath[j]) break;
			}

			for (int k = sz1 - 1; k >= j; --k) {
				int u = lastPath[k], v = lastPath[k - 1];
				if (++edgeVisits[{min(u, v), max(u, v)}] > 2) {
					cout << "-1";
					return 0;
				}

				ans.push_back(lastPath[k - 1]);
			}

			for (int k = j; k < sz2; ++k) {
				if (k > 0) {
					int u = currPath[k - 1], v = currPath[k];
					if (++edgeVisits[{min(u, v), max(u, v)}] > 2) {
						cout << "-1";
						return 0;
					}
				}

				ans.push_back(currPath[k]);
			}

			lastPath = currPath;
		}
	}

	for (int i = lastPath.size() - 1; i > 0; --i) {
		int u = lastPath[i], v = lastPath[i - 1];
		if (++edgeVisits[{min(u, v), max(u, v)}] > 2) {
			cout << "-1";
			return 0;
		}

		ans.push_back(lastPath[i - 1]);
	}

	for (auto ele : ans) cout << ele << ' ';
	return 0;
}
