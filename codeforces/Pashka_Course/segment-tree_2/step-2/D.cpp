#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const i64 MAXN = 1e5 + 5;
int n;
struct Node {
	int op1, op2;
};

Node t[4 * MAXN];

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {	
		t[v].op1 = t[v].op1 + val;
		t[v].op2 = t[v].op2 + (val * (tr - tl + 1));
		return;
	}
	int tm = (tl + tr) / 2;
	update(2 * v, tl, tm, l, r, val);
	update(2 * v + 1, tm + 1, tr, l, r, val);
	t[v].op2 = t[2 * v].op2 + t[2 * v + 1].op2 + (t[v].op1 * (tr - tl + 1));
}

int query(int v, int tl, int tr, int l, int r)	{
	if (tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return t[v].op2;
	int tm = (tl + tr) / 2;	
	int left = query(2 * v, tl, tm, l, r);
	int right = query(2 * v + 1, tm + 1, tr, l, r);
	return left + right + (t[v].op1 * (min(tr, r) - max(tl, l) + 1));
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
