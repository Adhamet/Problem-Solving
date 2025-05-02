#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 2e5+20;
int n, m;
struct Node {
	int sum = 0, lazyA = 0, lazyD = 0;
	bool islazy = false;
};

Node t[4*MAXN];

void apply(int v, int tl, int tr, int a, int d) {
	int len = tr-tl+1;
	t[v].sum += (len * a) + (len * (len-1) * d / 2);
	t[v].lazyA += a, t[v].lazyD += d;
	t[v].islazy= true;
}

void push(int v, int tl, int tr) {
	if (t[v].islazy) {
		int tm = (tl + tr) >> 1;
		int leftlen = (tm-tl+1);
		apply(v*2, tl, tm, t[v].lazyA, t[v].lazyD);
		apply(v*2+1, tm+1, tr, (t[v].lazyA + (t[v].lazyD*leftlen)), t[v].lazyD);
		t[v].lazyA = t[v].lazyD = 0;
		t[v].islazy = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int a, int d) {
	if (l > r || r < tl || tr < l) return;
	if (tl >= l && tr <= r) {
		int ele = a + d * (tl - l); // where am i 
		apply(v, tl, tr, ele, d);
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	update(v*2, tl, tm, l, r, a, d);
	update(v*2+1, tm+1, tr, l, r, a, d);
	t[v].sum = t[v*2].sum + t[v*2+1].sum;
}

int query(int v, int tl, int tr, int k) {
	if (tl == tr) return t[v].sum;
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	if (k <= tm) return query(2*v, tl, tm, k);
	else return query(2*v+1, tm+1, tr, k);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int qry, l, r, a, d; cin >> qry;
		if (qry == 1) {
			cin >> l >> r >> a >> d;
			update(1, 1, n, l, r, a, d);
		} else {
			cin >> l;
			cout << query(1, 1, n, l) << el;
		}
	}

	return 0;
}
