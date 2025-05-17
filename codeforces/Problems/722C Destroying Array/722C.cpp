#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct DSU {
	vector<int> par;
	vector<i64> sm;

	DSU(int n): par(n), sm(n, 0) {
		for(int i = 0; i < n; ++i) par[i] = i;
	}

	int find(int v) { return v==par[v]?v:par[v]=find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) {
			if (sm[A] < sm[B]) swap(A,B);
			sm[A]+=sm[B];
			par[B]=A;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	i64 x;

	DSU t(n+4);
	vector<int> p(n+1);
	for (int i = 1; i <= n; ++i) cin >> x, t.sm[i]=x;
	for (int i = 1; i <= n; ++i) cin >> p[i];

	set<int> node;
	vector<i64> ans;
	ans.push_back(0);
	node.insert(p[n]);

	i64 mx = 0;
	for (int i = n; i>=1; --i) {
		if (node.count(p[i]+1)) t.unite(p[i], p[i]+1);
		if (node.count(p[i]-1)) t.unite(p[i], p[i]-1);
		node.insert(p[i]);

		int I = t.find(p[i]);
		mx = max(mx, t.sm[I]);
		ans.push_back(mx);
	}

	for (auto i = ans.rbegin() + 1; i != ans.rend(); i++)
		cout << *i << el;
	return 0;
}
