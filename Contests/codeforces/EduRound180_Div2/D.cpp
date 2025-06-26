#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;		cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<vector<int>> g(n+1);
		vector<int> deg(n+1, 0);
		for (int i = 0; i < n-1; i++) {
			int a,b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
			deg[a]++; deg[b]++;
		}

		int pick = -1;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 2) {
				pick = i;
				break;
			}
		}

		if (pick == -1) {
			cout << "NO" << el;
			continue;
		}

		vector<pair<int,int>> ans;
		function<void(int,int,int)> dfs = [&](int v, int V, int x) {
			for(int vv: g[v]) {
				if (vv == V || vv == pick) continue;
				if (x == 0) ans.emplace_back(v,vv);
				else ans.emplace_back(vv, v);
				dfs(vv, v, x ^ 1);
			}
		};

		int u = g[pick][0], v = g[pick][1];
		dfs(u, 0, 0), dfs(v, 0, 1);
		ans.emplace_back(u, pick);
		ans.emplace_back(pick, v);

		cout << "YES" << el;
		for(auto &ed: ans) cout << ed.fst << ' ' << ed.scd << el;
	} return 0;
}


