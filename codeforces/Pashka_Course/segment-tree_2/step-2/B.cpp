#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const i64 MAXN = 1e5 + 5, MOD = 1e9+7;
int n;
struct Node {
	int op, sums;
};

Node t[4 * MAXN];

void build(int v, int tl, int tr) {
	t[v].op = 1;
	if (tl == tr) t[v].sums = 1;
	else {
		int tm = (tl + tr) / 2;
		build(2 * v, tl, tm);
		build(2 * v + 1, tm + 1, tr);
		t[v].sums = (t[2 * v].sums + t[2 * v + 1].sums) % MOD;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		t[v].op = (t[v].op * val) % MOD;
		t[v].sums = (t[v].sums * val) % MOD;
		return;
	}
	int tm = (tl + tr) / 2;
	update(2 * v, tl, tm, l, r, val);
	update(2 * v + 1, tm + 1, tr, l, r, val);
	t[v].sums = (((t[2 * v].sums + t[2 * v + 1].sums) % MOD) * t[v].op) % MOD;
}

int query(int v, int tl, int tr, int l, int r)	{
	if (tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return t[v].sums;
	int tm = (tl + tr) / 2;
	int left = query(2 * v, tl, tm, l, r);
	int right = query(2 * v + 1, tm + 1, tr, l, r);
	return (((left + right) % MOD) * t[v].op) % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	build(1, 0, n - 1);
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
