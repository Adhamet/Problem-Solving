#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 5e5+10;				
struct DSU {
	vector<int> par, val;

	DSU(int n): par(n), val(n, -1) { 
		iota(par.begin(), par.end(), 0);
	}

	int find(int v) { return v == par[v] ? v: par[v] = find(par[v]); }
	void unite(int a, int b) {
		int A = find(a), B = find(b);
		if (A != B) par[B] = A;
	}

	void setVal(int v, int x) { val[v] = x; }
	int getVal(int idx) {
		int IDX = find(idx);
		return val[IDX];
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	DSU dsu(MAXN);

	int q, idx = 0; cin >> q;
	vector<int> last(MAXN, -1);
	while (q--) {
		int type, x, y; cin >> type;
		if (type == 1) {
			cin >> x;
			x -= 1;
			if (~last[x]) dsu.unite(last[x], idx);
			dsu.setVal(dsu.find(idx), x);
			last[x] = idx;
			idx += 1;
		} else {
			cin >> x >> y;
			x -= 1, y -= 1;
			if (x == y) continue;
			if (~last[x]) {
				dsu.setVal(dsu.find(last[x]), y);
				if (~last[y]) dsu.unite(last[y], last[x]);
				else last[y] = last[x];
				last[x] = -1;
			}
		}
	}

	for (int i = 0; i < idx; ++i)
		cout << dsu.getVal(i) + 1 << ' ';
	return 0;
}


