#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5+5;
int n, m;
struct Node {
	int sum = 0, ladd = 0, lassign = -1;	
};

Node t[4*MAXN];

void push(int v, int tl, int tr) {
	if (t[v].lassign != -1) {
		t[v].sum = t[v].lassign * (tr-tl+1);
		if (tl != tr) {
			t[v*2].ladd = t[v*2+1].ladd = 0;
			t[v*2].lassign = t[v*2+1].lassign = t[v].lassign;
		}
		t[v].lassign = -1;
	}

	if (t[v].ladd != 0) {
		t[v].sum += t[v].ladd * (tr-tl+1);
		if (tl != tr) {
			if (t[v*2].lassign != -1) t[v*2].lassign += t[v].ladd;
			else t[v*2].ladd += t[v].ladd;
			if (t[v*2+1].lassign != -1) t[v*2+1].lassign += t[v].ladd;
			else t[v*2+1].ladd += t[v].ladd;
		}
		t[v].ladd = 0;
	}
}

void opAdd(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l) return;
	if (l <= tl && tr <= r) {
		t[v].ladd += val;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) >> 1;
		opAdd(v*2, tl, tm, l, r, val);
		opAdd(v*2+1, tm+1, tr, l, r, val);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
	}
}

void opAssign(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l) return;
	if (l <= tl && tr <= r) {
		t[v].lassign = val, t[v].ladd = 0;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) >> 1;
		opAssign(v*2, tl, tm, l, r, val);
		opAssign(v*2+1, tm+1, tr, l, r, val);
		t[v].sum = t[v*2].sum + t[v*2+1].sum;
	}
}

i64 query(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l) return 0;
	if (l <= tl && tr <= r) return t[v].sum;
	int tm = (tl + tr) >> 1;
	return query(v*2,tl,tm,l,r) + query(v*2+1,tm+1,tr,l,r);
}


int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	while (m--) {
		int q, l, r, v;
		cin >> q;
		if (q == 1) {
			cin >> l >> r >> v;
			opAssign(1, 0, n-1, l, r-1, v);
		} else if (q == 2) {
			cin >> l >> r >> v;
			opAdd(1, 0, n-1, l, r-1, v);
		} else {
			cin >> l >> r;
			cout << query(1, 0, n-1, l, r-1) << el;
		}
	}

	return 0;
}
