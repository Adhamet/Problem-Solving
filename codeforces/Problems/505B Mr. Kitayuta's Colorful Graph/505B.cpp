#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	int len;
	vector<int> par;

	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }

	int find(int v) { return v==par[v]? v:par[v] = find(par[v]); }
	bool isConn(int a, int b) { return find(a) == find(b); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) par[A] = B;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<DSU> colDSU(m, DSU(n));

	set<int> cols;
	for (int i = 0, u, v, c; i < m; ++i) {
		cin >> u >> v >> c;
		u -= 1, v -= 1, c -= 1;
		cols.insert(c);
		colDSU[c].unite(u, v);
	}

	int q; cin >> q;
	while (q--) {
		int u, v, ans = 0; cin >> u >> v;
		u -= 1, v -= 1;
		for (auto& c: cols) if (colDSU[c].isConn(u, v)) 
			ans += 1;
		cout << ans << el;
	}

	return 0;
}
