#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5+5;
int n, m;
struct Node {
	int sum = 0, pref = 0, suff = 0, ans = 0, lazyop = 0;
	bool marked = false;
};

Node t[4*MAXN];

Node combine(Node a, Node b) {
	Node res;
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum + b.pref);
	res.suff = max(b.suff, b.sum + a.suff);
	res.ans = max({a.ans, b.ans, a.suff + b.pref});
	return res;
}

void apply(int v, int tl, int tr, int val) {
	t[v].sum = (tr - tl + 1) * val;
	if (val > 0) t[v].pref = t[v].suff = t[v].ans = t[v].sum;
	else t[v].pref = t[v].suff = t[v].ans = 0;
	t[v].lazyop = val;
	t[v].marked = true;
}

void push(int v, int tl, int tr) {
	if (t[v].marked) {
		t[v].marked = false;
		int tm = (tl + tr) >> 1;
		apply(v*2, tl, tm, t[v].lazyop);
		apply(v*2+1, tm+1, tr, t[v].lazyop);
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r || tr < l || tl > r) return;
	if (tl >= l && tr <= r) apply(v, tl, tr, val);
	else {
		push(v, tl, tr);
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, min(r, tm), val);
		update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int l, r, v; cin >> l >> r >> v;
		update(1, 0, n - 1, l, r - 1, v);
		cout << t[1].ans << el;
	} return 0;
}

