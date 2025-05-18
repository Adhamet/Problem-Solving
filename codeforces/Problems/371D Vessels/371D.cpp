#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	int len;
	vector<int> par, curr, cap;

	DSU(int n): par(n), curr(n), cap(n), len(n) {
		iota(par.begin(), par.end(), 0);
	}

	int find(int v) { return v==par[v]? v:par[v] = find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) par[A] = B;
	}

	void pour(int v, int x) {
		int V = find(v);
		if (curr[V] == cap[V]) {
			if (V < len - 1) {
				unite(V, V+1);
				pour(V+1, x);
			}
		} else {
			if (curr[V] + x > cap[V]) {
				x -= (cap[V] - curr[V]);
				curr[V] = cap[V];
				if (V < len - 1) {
					unite(V, V+1);
					pour(V+1, x);
				}
			} else curr[V] += x;
		}
	}

	int getKthCurr(int k) { return curr[k]; }
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	/*cout << "TEST" << el;*/
	int n; cin >> n;
	DSU dsu(n);
	for (int i = 0, cap; i < n; ++i) {
		cin >> cap;
		dsu.cap[i] = cap;
	}

	int m; cin >> m;
	while (m--) {
		int type; cin >> type;
		if (type == 1) {
			int p, x; cin >> p >> x;
			dsu.pour(p - 1, x);
		} else {
			int k; cin >> k;
			cout << dsu.getKthCurr(k - 1) << el;
		}
	}

	return 0;
}
