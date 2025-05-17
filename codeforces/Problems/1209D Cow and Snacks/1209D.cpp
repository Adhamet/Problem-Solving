#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;

	DSU(int n): par(n), sz(n,1) {
		for (int i = 0; i < n; ++i) par[i]=i;
	}

	int find(int v) { return v==par[v]?v:par[v]=find(par[v]); }
	bool isConn(int a, int b) { return find(a)==find(b); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A,B);
			sz[A]+=sz[B];
			par[B]=A;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k, ans = 0;
	cin >> n >> k;

	DSU t(n+5);
	while (k--) {
		int u, v; cin >> u >> v;
		if (t.isConn(u,v)) ans += 1;
		t.unite(u,v);
	}

	return cout << ans, 0;
}
