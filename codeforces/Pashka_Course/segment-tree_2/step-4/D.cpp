#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5+5;
int n, m;
struct Node {
	int sum=0, wsum=0, lazy=0;
};

Node t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v].sum = a[tl];
		t[v].wsum = a[tl] * tl;
	} else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
		t[v].wsum = t[v*2].wsum + t[v*2+1].wsum;
	}
}

void apply(int v, int tl, int tr, int val) {
	t[v].lazy += val;
	int len = tr-tl+1;
	t[v].sum += (val * len);
	t[v].wsum += (val * len * (tr+tl) / 2);
}

void push(int v, int tl, int tr) {
	if (t[v].lazy) {
		int tm = (tl + tr) >> 1;
		apply(v*2, tl, tm, t[v].lazy);
		apply(v*2+1, tm+1, tr, t[v].lazy);
		t[v].lazy = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r || tr < l || tl > r) return;
	else if (tl >= l && tr <= r) apply(v, tl, tr, val);
	else {
		push(v, tl, tr);
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, min(r, tm), val);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
		t[v].wsum = t[v*2].wsum + t[v*2+1].wsum;
	}
}

Node get(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || tl > r) return {0,0,0};
	else if (tl >= l && tr <= r) return t[v];
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	Node left = get(v*2, tl, tm, l, min(r, tm));
	Node right = get(v*2+1, tm+1, tr, max(l, tm+1), r);
	return {left.sum + right.sum, left.wsum + right.wsum, 0};
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(a, 1, 1, n);
	while (m--) {
		int qry; cin >> qry;
		if (qry == 1) {
			int l, r, d;
			cin >> l >> r >> d;
			update(1, 1, n, l, r, d);
		} else {
			int l, r;
			cin >> l >> r;
			Node res = get(1, 1, n, l, r);
			cout << res.wsum - (res.sum * (l - 1)) << el;
		}
	}

	return 0;
}
