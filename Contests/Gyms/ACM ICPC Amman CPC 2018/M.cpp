#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 25e5+5;
i64 ans;
vector<vector<int>> g;
set<pair<int,int>> vis;
map<pair<int,int>, i64> cost;

bool found;
void dfs1(int u, int end) {
	if (u == end) return;
	for (auto& v: g[u]) {
		if (!vis.count({u,v})) {
			vis.insert({u,v});
			ans += cost[{u,v}];
			dfs1(v, end);

			if (v == end) {
				vis.insert({v, u});
				found = true;
			}

			if (!found) ans += cost[{v,u}];
		}
	}
}

void dfs2(int u) {
	for (auto& v: g[u]) {
		if (!vis.count({u,v})) {
			vis.insert({u,v});
			ans += cost[{u,v}];
			dfs2(v);
			vis.insert({v,u});
			ans += cost[{v,u}];
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		g.clear();
		cost.clear();
		
		int n; cin >> n;
		g.resize(n);
		for (int i = 0; i < n; ++i) g[i].clear();
		for (int i = 0, u, v, c1, c2; i < n; ++i) {
			cin >> u >> v >> c1 >> c2;
			u -= 1, v -= 1;
			g[u].push_back(v), g[v].push_back(u);
			cost[{u,v}] = c1;
			cost[{v,u}] = c2;
		}

		int q; cin >> q;
		while (q--) {
			ans = 0;
			int start, end;
			found = false;
			dfs1(start, end);
			dfs2(end);
			cout << ans << el;
			vis.clear();
		}
	}

	return 0;
}#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 20;

int up[MAXN][LOG], depth[MAXN];
long long upCoins[MAXN][LOG], downCoins[MAXN][LOG];
vector<tuple<int, int, int>> adj[MAXN]; // (v, c1, c2)

void dfs(int u, int p, int c1, int c2) {
    up[u][0] = p;
    upCoins[u][0] = c2;
    downCoins[u][0] = c1;

    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        upCoins[u][i] = upCoins[u][i - 1] + upCoins[up[u][i - 1]][i - 1];
        downCoins[u][i] = downCoins[u][i - 1] + downCoins[up[u][i - 1]][i - 1];
    }

    for (auto &[v, a, b] : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, a, b);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[up[u][i]] >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

long long get_up(int u, int d) {
    long long res = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if ((1 << i) <= d) {
            res += upCoins[u][i];
            u = up[u][i];
            d -= (1 << i);
        }
    }
    return res;
}

long long get_down(int u, int d) {
    long long res = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if ((1 << i) <= d) {
            res += downCoins[u][i];
            u = up[u][i];
            d -= (1 << i);
        }
    }
    return res;
}

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        depth[i] = 0;
        for (int j = 0; j < LOG; j++) {
            up[i][j] = 0;
            upCoins[i][j] = 0;
            downCoins[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        reset(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v, c1, c2;
            cin >> u >> v >> c1 >> c2;
            adj[u].emplace_back(v, c1, c2);
            adj[v].emplace_back(u, c2, c1); // reversed edge
        }

        dfs(1, 0, 0, 0);

        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            int l = lca(x, y);
            long long res = get_up(x, depth[x] - depth[l]) + get_down(y, depth[y] - depth[l]);
            cout << res << '\n';
        }
    }

    return 0;
}

