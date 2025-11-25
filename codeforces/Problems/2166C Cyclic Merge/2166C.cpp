#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	std::vector<int> par, sz, mx;

	DSU(int n, std::vector<int> input): par(n), sz(n, 1), mx(input) { 
		iota(par.begin(), par.end(), 0);
	}

	int root(int v) { return v == par[v] ? v : par[v] = root(par[v]); }

	bool unite(int u, int v) {
		u = root(u), v = root(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) std::swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
		mx[u] = std::max(mx[u],mx[v]);
		return true;
	}
};

void solve() {
	int n;	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::array<int,2>> vec;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		vec.push_back({a[i], i});
	}
	std::sort(vec.begin(), vec.end());

	i64 ans = 0;
	DSU dsu(n, a);
	bool mark[n];	std::fill(mark, mark+n, false);
	for (auto [x, i]: vec) {
		mark[i] = true;
		if (mark[(i - 1 + n) % n] && dsu.unite(i, (i-1+n)%n))
			ans += dsu.mx[dsu.root(i)];
		if (mark[(i + 1) % n] && dsu.unite(i, (i+1)%n))
			ans += dsu.mx[dsu.root(i)];
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
