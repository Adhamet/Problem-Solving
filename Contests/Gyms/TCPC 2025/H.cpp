#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 20;

int n, l, finalLC[(1<<MXN)][MXN];
vector<int> par;
vector<vector<int>> g;
i64 mem[(1<<MXN)], c[MXN];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : g[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int getLCA(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void precompute() {
	for (int msk = 0; msk < (1 << n); ++msk) {
		for (int v = 0; v < n; ++v) {
			int nv = v;
			while ((msk & (1 << nv)) == 0) {
				nv = par[nv];
				if (nv == -1) break;
			}

			finalLC[msk][v] = nv;
		}
	}
}

i64 go(int msk) {
	int bts = __builtin_popcount(msk);
	if (bts <= 1) return 0;

	if (bts == 2) {
		int u = __builtin_ctz(msk);
		int v = __builtin_ctz(msk & ~(1<<u));
		int currLC = getLCA(u, v);
		return c[finalLC[msk][currLC]];
	}

	i64 &ret = mem[msk];
	if (~ret) return ret;
	ret = 1e18;

	for (int u = 1; u < n; ++u) if (msk & (1<<u)) {
		for (int v = u+1; v < n; ++v) if (msk & (1<<v)) {
			int currLC = getLCA(u,v);
			currLC = finalLC[msk][currLC];
			if (currLC == -1) continue;

			i64 cost = c[currLC];
			ret = min(ret, cost + go(msk ^ (1 << u) ^ (1 << v)));
		}
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> c[i];

	g.assign(n, {});
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u,--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	par.assign(n, -1);
	queue<int> q;
	vector<bool> vis(n);
	q.push(0);	vis[0] = true;
	while (!q.empty()) {
		int v = q.front();	q.pop();
		for (auto &vv: g[v]) if (!vis[vv]) {
			vis[vv] = true;
			par[vv] = v;
			q.push(vv);
		}
	}

	preprocess(0);
	precompute();
	memset(mem, -1, sizeof mem);
	return cout << go((1<<n) - 1), 0;
}
