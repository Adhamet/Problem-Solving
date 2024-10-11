#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 505;
/*const int oo = 1e9 + 20;*/
vector<int> graph[N], revgraph[N];
vector<bool> vis(N), vis2(N);
vector<int> path;
vector<bool> inComp(N);

void dfs(int node) {
	vis[node] = true;
	for (int child: graph[node]) if (!vis[child]) {
		dfs(child);
	}

	path.push_back(node);
}

void dfs2(int node, vector<int> &component) {
	vis2[node] = true;
	for (auto child: revgraph[node]) if (!vis2[child]) {
		dfs2(child, component);
	}

	inComp[node] = true;
	component.push_back(node);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		graph[i].resize(n);

		for (int j = 0; j < n; j++) cin >> graph[i][j];
		while (graph[i].back() != i) graph[i].pop_back();

		for (int j: graph[i]) revgraph[j].push_back(i);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) {
		dfs(i);
	}

	reverse(path.begin(), path.end());

	vector<int> ans(n + 1);
	for (int i: path) if (!vis2[i]) {
		vector<int> component;
		dfs2(i, component);

		for (int node: component) {
			for (int preference: graph[node]) {
				if (inComp[preference]) {
					ans[node] = preference;
					break;
				}
			}
		}

		for (int node: component) inComp[node] = false;
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << el;
	return 0;
}
