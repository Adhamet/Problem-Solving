#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 100005;
int n, t[4*MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) t[v] = 0;
	else {
		int tm = (tl + tr) >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) t[v] += val;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, val);
		else update(v*2+1, tm+1, tr, pos, val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(v*2, tl, tm, l, min(r, tm)) +
		query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	build(1, 0, n - 1);
	while (m--) {
		int qry, l, r, v, idx;
		cin >> qry;
		if (qry == 1) {
			cin >> l >> r >> v;
			update(1, 0, n - 1, l, v);
			if (r < n) update(1, 0, n - 1, r, -v);
		} else {
			cin >> idx;
			cout << query(1, 0, n - 1, 0, idx) << el;
		}
	}

	return 0;
}
