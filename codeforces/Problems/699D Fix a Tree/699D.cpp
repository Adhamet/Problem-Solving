#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	DSU(int n): par(n) { iota(par.begin(), par.end(), 0); }
	int find(int v) { return v==par[v]? v: par[v] = find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) par[A] = B;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, ans = 0, root = -1; cin >> n;
	DSU t(n+2);
	
	vector<int> a(n+1), fixpar(n+1), fix;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int I = t.find(i), AI = t.find(a[i]);
		if (I == AI) {
			fix.push_back(i);
			if (a[i] == i) root = i;
		} else t.unite(I, AI);
	}

	if (root == -1 && (int)fix.size()) {
		root = a[fix[0]] = fix[0];
		ans += 1;
	}

	for (auto& i: fix) if (a[i] != root) {
		ans += 1;
		a[i] = root;
	}

	cout << ans << el;
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	return 0;
}
