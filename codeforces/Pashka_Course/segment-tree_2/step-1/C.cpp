#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int long long
#define el '\n'

const int MAXN = 100005, oo = 1e9+7;
int n, t[4*MAXN];

void update(int v, int tl, int tr, int l, int r, int val) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		t[v] = val;
		return;
	}
	
	if (t[v] != oo) t[v*2] = t[v*2+1] = t[v];
	t[v] = oo;
	int tm = (tl + tr) >> 1;
	return update(v*2, tl, tm, l, min(r,tm), val),
 			update(v*2+1, tm+1, tr, max(l, tm+1), r, val);
}

int query(int v, int tl, int tr, int idx) {
	if (tl == tr || t[v] != oo) return t[v];
	int tm = (tl + tr) >> 1;
	if (idx <= tm) return query(v*2, tl, tm, idx);
	else return query(v*2+1, tm+1, tr, idx);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	
	while (m--) {
		int qry;
		cin >> qry;
		if (qry == 1) {
			int l, r, val; cin >> l >> r >> val;
			update(1, 0, n - 1, l, r - 1, val);
		} else {
			int idx; cin >> idx;
			cout << query(1, 0, n - 1, idx) << el;
		}
	}

	return 0;
}
