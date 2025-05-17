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

	int n; cin >> n;
	DSU t(n+4);
	vector<int> ap(n+1), bp(n+1), d(n+1);
	iota(ap.begin(), ap.end(), 0);

	for (int i = 1; i <= n; ++i) cin >> bp[i];
	for (int i = 1; i <= n; ++i) cin >> d[i];
	for (int i = 1; i <= n; ++i) {
		if (i+d[i] <= n && !t.isConn(ap[i],ap[i+d[i]]))
			t.unite(ap[i],ap[i+d[i]]);
		if (i-d[i] >= 1 && !t.isConn(ap[i],ap[i-d[i]]))
			t.unite(ap[i],ap[i-d[i]]);
	}

	for (int i = 1; i <= n; ++i) if (!t.isConn(ap[i], bp[i]))
		return cout << "NO", 0;
	return cout << "YES", 0;
}
