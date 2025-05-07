#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 1e5+5;
struct Node {
	int max1, max2;
};

Node t[4*MAXN];

Node combine(Node left, Node right) {
	int vals[] = {left.max1, left.max2, right.max1, right.max2};
	sort(vals, vals+4, greater<>());
	return {vals[0], vals[1]};
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = {a[tl], 0};
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) t[v] = {val, 0};
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, val);
		else update(v*2+1, tm+1, tr, pos, val);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || tl > r) return {0, 0};
	if (tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return combine(query(v*2, tl, tm, l, min(r, tm)), 
			query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	int a[n];
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(a, 1, 1, n);

	int m; cin >> m;
	while (m--) {
		char type; cin >> type;
		if (type == 'U') {
			int i, x; cin >> i >> x;
			update(1, 1, n, i, x);
		} else {
			int x, y; cin >> x >> y;
			Node z = query(1, 1, n, x, y);
			cout << z.max1 + z.max2 << el;
		}
	}

	return 0;
}
