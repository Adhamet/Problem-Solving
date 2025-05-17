#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par, sz;

	DSU(int n): par(n), sz(n, 1) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}

	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); };
	void unite(int a, int b) {
		int A = find(a);
		int B = find(b);
		if (A != B) {
			if (sz[A] < sz[B]) swap(A,B);
			sz[A] += sz[B];
			par[B] = A;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	DSU forest(n+1);

	while (m--) {
		int k; cin >> k;
		vector<int> vec(k);
		for (int i = 0; i < k; ++i) cin >> vec[i];
		for (int i = 0; i < k - 1; ++i) forest.unite(vec[i], vec[i+1]);
	}

	for (int i = 1; i <= n; ++i) {
		int par = forest.find(i);
		cout << forest.sz[par] << ' ';
	}

	return 0;
}

