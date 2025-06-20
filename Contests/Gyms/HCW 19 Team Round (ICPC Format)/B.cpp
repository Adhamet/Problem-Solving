#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using ld = long double;
#define Youssef() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
#define unmap unordered_map
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvl vector<vll>
#define pii pair<int, int>
#define si(x) ll(x.size())
#define For(i, j, n) for(ll i = j; i < n; i++)
#define rFor(i, j, n) for(ll i = j; i >= n; i--)
#define read(a) For(i, 0, si(a)) cin >> a[i];
#define readd(a) For(i, 0, si(a)) For(j, 0, si(a[0])) cin >> a[i][j];
#define print(a) For(j, 0, si(a)) cout << a[j] << (j < si(a)-1 ? " " : ""); cout << endl;
#define fi first
#define se second
#define int ll
const int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

vector<vector<int>> g;
vector<int> depth;
vector<char> vis;
int dfs(int v, int V) {
	int best = 0;
	for (int vv: g[v]) if (vv != V)
		best = max(best, dfs(vv, v));
	return depth[v] = best + 1;
}

signed main() {
	Youssef();
	int n; 
	cin >> n;
	g.assign(n+1, {});
	for (int i = 1; i < n; i++) {
		int u, v; 
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	depth.assign(n+1, 0);
	dfs(1, 0);

	auto askDist = [&](int u) -> int {
		cout << "? 1 " << u << endl;
		cout.flush();
		int d; cin >> d;
		return d;
	};
	auto askNext = [&](int u) -> int {
		cout << "? 2 " << u << endl;
		cout.flush();
		int v; cin >> v;
		return v;
	};

	vis.assign(n+1, 0);
	int v = 1, dist = askDist(v);
	while (dist > 0) {
		vis[v] = 1;
		vector<int> vvs;
		for (int vv: g[v])
			if (!vis[vv] && depth[vv] >= dist)
				vvs.push_back(vv);
		if ((int)vvs.size() > 1) v = askNext(v);
		else v = vvs[0];
		dist--;
	}

	return cout << "! " << v << endl, 0;
}

