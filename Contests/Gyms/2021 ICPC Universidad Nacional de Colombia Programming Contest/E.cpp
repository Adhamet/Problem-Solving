#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<vector<int>> g(n);
	vector<int> deg(n), edges(n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		deg[u]++, deg[v]++;
		edges[u]++, edges[v]++;
	}

	vector<int> cur, nxt;
	vector<bool> done(n, false);
	for (int i = 0; i < n; ++i) if (deg[i] % 2 == 0) {
		cur.push_back(i);
		break;
	}

	map<pair<int,int>, bool> processed;

	int nodesDone = 0;
	deque<int> ans;
	while (nodesDone < n) {
		nxt.clear();

		for (auto& v: cur) if (!done[v]) {
			ans.push_back(v);
			if (deg[v] % 2 == 0) {
				for (auto &vv: g[v]) {
					pair<int,int> edg = {min(v,vv), max(v,vv)};
					if (!processed[edg]) {
						processed[edg] = true;
						edges[v] -= 1;
						if (edges[v] <= (deg[v] / 2)) {
							ans.push_back(vv);
						} else ans.push_front(vv);
						nxt.push_back(vv);
					}
				}
			} else {
				for (auto &vv: g[v]) {
					pair<int,int> edg = {min(v,vv), max(v,vv)};
					if (!processed[edg]) {
						edges[v] -= 1;
						processed[edg] = true;
						edges[vv]--;
						nxt.push_back(vv);
					}
				}
			}

			if (edges[v] == 0) done[v] = true, nodesDone += 1;
		}

		cur.swap(nxt);
	}

	for (auto& x: ans) cout << x << ' ';
	return 0;
}
