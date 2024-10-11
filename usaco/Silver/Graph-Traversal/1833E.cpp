#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5+5;
/*const int oo = 1e9 + 20;*/
bool immergable = false, vis[N];
set<int> graph[N];

void clear(int n) {
	for (int i = 0; i <= n; i++) {
		graph[i].clear();
		vis[i] = 0;
	}
}

void dfs(int node) {
	vis[node] = true;
	if (graph[node].size() == 1) immergable = true;

	for (auto child: graph[node]) if (!vis[child]) {
		dfs(child);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int u = 1; u <= n; u++) {
			int v;
			cin >> v;
			graph[u].insert(v);
			graph[v].insert(u);
		}

		int mn = 0, mx = 0;
		for (int i = 1; i <= n; i++) if (!vis[i]) {
			immergable = false;
			dfs(i);
			
			if (!immergable) mn += 1;
			mx += 1;
		}

		cout << mn + min(1, mx - mn) << " " << mx << el;
		clear(n);
	}

	return 0;
}	
