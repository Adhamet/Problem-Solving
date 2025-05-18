#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;

	DSU(int n): par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v == par[v] ? v: par[v] = find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A, B);
			sz[A] += sz[B];
			par[B] = A;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	DSU dsu(n);

	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		dsu.unite(u - 1, v - 1);
	}

	int tot = 0;
	vector<bool> took(n, false);
	for (int i = 0; i < n; ++i) {
		int I = dsu.find(i);
		if (!took[I]) {
			took[I] = true;
			tot += dsu.sz[I] - 1;
		}
	}

	return cout << (1LL << tot), 0;
}

