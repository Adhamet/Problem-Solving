#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const i64 MAXN = 1e5 + 5, oo = 1e18 + 7;
int n;
struct Node {
	int op, min;
};

Node t[4 * MAXN];

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		t[v].op += val;
		t[v].min += val;
		return;
	}
	int tm = (tl + tr) / 2;
	update(2 * v, tl, tm, l, r, val);
	update(2 * v + 1, tm + 1, tr, l, r, val);
	t[v].min = min(t[2 * v].min, t[2 * v + 1].min) + t[v].op;
}

int query(int v, int tl, int tr, int l, int r)	{
	if (tr < l || tl > r) return oo;
	if (tl >= l && tr <= r) return t[v].min;
	int tm = (tl + tr) / 2;
	return min(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r)) + t[v].op;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	while (m--) {
		int qry, l, r, val;
		cin >> qry >> l >> r;
		if (qry == 1) {
			cin >> val;
			update(1, 0, n - 1, l, r - 1, val);
		} else cout << query(1, 0, n - 1, l, r - 1) << el;
	}

	return 0;
}
