#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 200005;
int r, n;

struct Node {
	int x0, x1;
	int x2, x3;
};

Node t[4 * MAXN];

Node produce(Node a, Node b) {
	Node res;
	res.x0 = (((a.x0 * b.x0) % r) + ((a.x1 * b.x2) % r)) % r;
	res.x1 = (((a.x0 * b.x1) % r) + ((a.x1 * b.x3) % r)) % r;
	res.x2 = (((a.x2 * b.x0) % r) + ((a.x3 * b.x2) % r)) % r;
	res.x3 = (((a.x2 * b.x1) % r) + ((a.x3 * b.x3) % r)) % r;
	return res;
};

void build(Node a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = produce(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r) return {0, 0, 0, 0};
	else if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	if (r <= tm) return query(v*2, tl, tm, l, r);
	else if (l > tm) return query(v*2+1, tm+1, tr, l, r);
	else {
		Node left = query(2*v, tl, tm, l, tm);
		Node right = query(2*v+1, tm+1, tr, tm+1, r);
		return produce(left, right);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> r >> n >> m;

	Node a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x0 >> a[i].x1;
		cin >> a[i].x2 >> a[i].x3;
	}

	build(a, 1, 0, n - 1);
	while (m--) {
		int l, r;
		cin >> l >> r;
		Node res = query(1, 0, n - 1, l - 1, r - 1);
		cout << res.x0 << ' ' << res.x1 << el;
		cout << res.x2 << ' ' << res.x3 << el;
		cout << el;
	}

	return 0;
}
