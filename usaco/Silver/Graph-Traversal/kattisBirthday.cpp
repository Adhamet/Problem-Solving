#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
const int N = 105/*, oo = 1e9+7, mod = 1e9+7*/;

int n,m;
bool vis[N];
bool adj[N][N];
void dfs(int node) {
	vis[node]=true;
	for(int to=0; to < n; to++) {
		if(adj[node][to] && !vis[to]) dfs(to);
	}
}

void solve() {
	memset(adj, false, sizeof(adj));
	vector<pi> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = true;
		adj[v][u] = true;
		edges.push_back(mp(u, v));
	}
	for (pi x : edges) {
		adj[x.F][x.S] = false;
		adj[x.S][x.F] = false;
		memset(vis, false, sizeof(vis));
		dfs(0);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cout << "Yes" << '\n';
				return;
			}
		}
		adj[x.F][x.S] = true;
		adj[x.S][x.F] = true;
	}
	cout << "No" << '\n';
}

int main()	{
	adhamet;
	while(cin >> n >> m && (n || m))
		solve();
	return 0;
}

