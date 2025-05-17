#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;
	
	DSU(int n): par(n+1), sz(n+1, 1) {
		for (int i = 0; i < n; ++i) par[i] = i;
	};

	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A,B);
			sz[A] += sz[B];
			par[B] = A;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	DSU forest(n+1);

	int k, m;
	cin >> k;
	while (k--) {
		int u, v; cin >> u >> v;
		forest.unite(u, v);
	}

	cin >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		int U = forest.find(u), V = forest.find(v);
		if (U == V) forest.sz[U] = -123;
	}

	int mxSz = 0;
	for (int i = 1; i <= n; ++i) mxSz = max(mxSz, forest.sz[forest.par[i]]);
	return cout << mxSz, 0;
}
