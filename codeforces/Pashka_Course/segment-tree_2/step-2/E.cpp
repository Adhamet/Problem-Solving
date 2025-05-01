#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5 + 5, oo = 1e18;
int n;

struct Node {
	int val = 0, lazyval = 0;
	bool mark = false;
};

Node t[4 * MAXN];

void push(int v, int tl, int tr) {
	if (t[v].mark) {
		t[v].mark = false;
		t[v].val = t[v].lazyval;
		if (tl != tr) {
			t[v*2].lazyval = t[v*2+1].lazyval = t[v].lazyval;
			t[v*2].mark = t[v*2+1].mark = true;
		}
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (tr < l || tl > r) return;
	else if (tl >= l && tr <= r) {
		t[v].lazyval = val, t[v].mark = true;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, l, r, val);
		update(2 * v + 1, tm + 1, tr, l, r, val);
		t[v].val = min(t[2 * v].val, t[2 * v + 1].val);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (tr < l || tl > r) return oo;
	if (tl >= l && tr <= r) return t[v].val;
	int tm = (tl + tr) / 2;
	return min(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	while (m--) {
		int qry, l, r; cin >> qry >> l >> r;
		if (qry == 1) {
			int v; cin >> v;
			update(1, 0, n - 1, l, r - 1, v);
		} else cout << query(1, 0, n - 1, l, r - 1) << el;
	}

	return 0;
}

