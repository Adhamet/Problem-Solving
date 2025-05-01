#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 100005;
int n, m;
struct Data {
	int cnt = 0;
	bool lazy = 0;
};

Data t[4*MAXN];

void push(int v, int tl, int tr) {
	if (t[v].lazy) {
		t[v].cnt = (tr - tl + 1) - t[v].cnt;
		if (tl != tr) t[v*2].lazy^=1, t[v*2+1].lazy^=1;
		t[v].lazy = 0;
	}
}

void update(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r || r < tl || tr < l) return;
	if (tl >= l && tr <= r) {
		t[v].lazy = 1;
		push(v, tl, tr);
	} else {
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, min(r, tm));
		update(v*2+1, tm+1, tr, max(l, tm+1), r);
		t[v].cnt = t[v*2].cnt + t[v*2+1].cnt;
	}
}

int query(int v, int tl, int tr, int k) {
	push(v, tl, tr);
	if (tl == tr) return tl;
	int tm = (tl + tr) >> 1;
	push(v*2, tl, tm);
	if (k < t[v*2].cnt) return query(v*2, tl, tm, k);
	else return query(v*2+1, tm+1, tr, k-t[v*2].cnt);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int q, l, r, k;
		cin >> q;
		if (q == 1) {
			cin >> l >> r;
			update(1, 0, n - 1, l, r - 1);
		} else {
			cin >> k;
			cout << query(1, 0, n - 1, k) << el;
		}
	}
	return 0;
}
