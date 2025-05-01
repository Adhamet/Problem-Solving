#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5+5;
int n, m;
struct Node {
	int mx = 0, lazy = 0;
};

Node t[4*MAXN];

void push(int v, int tl, int tr) {
	if (t[v].lazy == 0) return;
	t[v].mx += t[v].lazy;
	if (tl != tr)
		t[v*2].lazy+=t[v].lazy,t[v*2+1].lazy+=t[v].lazy;
	t[v].lazy = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l) return;
	if (l <= tl && tr <= r) {
		t[v].lazy += val;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, r, val);
		update(v*2+1, tm+1, tr, l, r, val);
		t[v].mx = max(t[v*2].mx, t[v*2+1].mx);
	}
}

int query(int v, int tl, int tr, int x, int l) {
	push(v, tl, tr);
	if (tr < l || t[v].mx < x) return -1;
	if (tl == tr) return tl;
	int tm = (tl + tr) >> 1;
	push(v*2, tl, tm);
	int left = query(v*2, tl, tm, x, l);
	if (~left) return left;
	else return query(v*2+1, tm+1, tr, x, l);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int q, l, r, v, x;
		cin >> q;
		if (q == 1) {
			cin >> l >> r >> v;
			update(1, 0, n - 1, l, r - 1, v);
		} else {
			cin >> x >> l;
			cout << query(1, 0, n - 1, x, l) << el;
		}
	}

	return 0;
}
