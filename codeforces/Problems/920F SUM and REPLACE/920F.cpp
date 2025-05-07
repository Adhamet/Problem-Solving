#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 1e5+5, MXD = 1e6+5;
vector<int> D(MXD);
int t[4*MAXN];

void build(vector<int> a, int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || tl > r) return;
	if (tl == tr) t[v] = D[t[v]];
	else {
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, r);
		update(v*2+1, tm+1, tr, l, r);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(v*2, tl, tm, l, r) +
		query(v*2+1, tm+1, tr, l, r);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	for (int i = 1; i < MXD; ++i)
		for (int j = i; j < MXD; j += i)
			++D[j];

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	build(a, 1, 0, n - 1);

	while (m--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r; cin >> l >> r;
			update(1, 0, n - 1, l - 1, r - 1);
		} else {
			int l, r; cin >> l >> r;
			cout << query(1, 0, n - 1, l - 1, r - 1) << el;
		}
	}

	return 0;
}
