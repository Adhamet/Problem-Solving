#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64

const int MAXN = 1e5 + 5;
int n, m;
struct Node {
	int sum = 0, lazyval = 0;
	bool marked = false;
};

Node t[4*MAXN];

void push(int v, int tl, int tr) {
	if (t[v].marked) {
		t[v].marked = false;
		t[v].sum = (tr - tl + 1) * t[v].lazyval;
		if (tl != tr) {
			t[v*2].lazyval = t[v*2+1].lazyval = t[v].lazyval;
			t[v*2].marked = t[v*2+1].marked = true;
		}
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		t[v].lazyval = val;
		t[v].marked = true;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) / 2;
		update(v*2, tl, tm, l, r, val);
		update(v*2+1, tm+1, tr, l, r, val);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
	}
}

int query(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return t[v].sum;
	int tm = (tl + tr) / 2;
	return query(v*2, tl, tm, l, r) + query(v*2+1, tm+1, tr, l, r);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int qry, l, r; cin >> qry >> l >> r;
		if (qry == 1) {
			int v; cin >> v;
			update(1, 0, n - 1, l, r - 1, v);
		} else cout << query(1, 0, n - 1, l, r - 1) << '\n';
	}

	return 0;
}
