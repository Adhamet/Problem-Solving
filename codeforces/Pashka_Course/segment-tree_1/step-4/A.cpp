#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct Node {
	int sum0, sum1;
};

const int MAXN = 1e5+5;
Node t[4*MAXN];
int n;

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v].sum0 = a[tl], t[v].sum1 = -a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		int len = tm - tl + 1;
		if (len % 2 == 0) {
			t[v].sum0 = t[2*v].sum0 + t[2*v+1].sum0;
			t[v].sum1 = t[2*v].sum1 + t[2*v+1].sum1;
		} else {
			t[v].sum0 = t[2*v].sum0 + t[2*v+1].sum1;
			t[v].sum1 = t[2*v].sum1 + t[2*v+1].sum0;
		}
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[v].sum0 = val;
		t[v].sum1 = -val;
	} else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(2*v, tl, tm, pos, val);
		else update(2*v+1, tm+1, tr, pos, val);
		int len = tm - tl + 1;
		if (len % 2 == 0) {
			t[v].sum0 = t[2*v].sum0 + t[2*v+1].sum0;
			t[v].sum1 = t[2*v].sum1 + t[2*v+1].sum1;
		} else {
			t[v].sum0 = t[2*v].sum0 + t[2*v+1].sum1;
			t[v].sum1 = t[2*v].sum1 + t[2*v+1].sum0;
		}
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	if (r <= tm) return query(2 * v, tl, tm, l, r);
    if (l > tm) return query(2 * v + 1, tm + 1, tr, l, r);
	Node LEFT = query(2*v, tl, tm, l, tm);
	Node RIGHT = query(2*v+1, tm+1, tr, tm+1, r);
	Node res;
	int len = tm - l + 1;
	if (len % 2 == 0) {
		res.sum0 = LEFT.sum0 + RIGHT.sum0;
		res.sum1 = LEFT.sum1 + RIGHT.sum1;
	} else {
		res.sum0 = LEFT.sum0 + RIGHT.sum1;
		res.sum1 = LEFT.sum1 + RIGHT.sum0;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	build(a, 1, 0, n - 1);

	int m;
	cin >> m;
	while (m--) {
		int qry, i, val, l, r;
		cin >> qry;
		if (qry == 0) {
			cin >> i >> val;
			update(1, 0, n - 1, i - 1, val);
		} else {
			cin >> l >> r;
			Node res = query(1, 0, n - 1, --l, --r);
			cout << res.sum0 << el;
		}
	}

	return 0;
}
