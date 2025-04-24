#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MAXN = 10000000;
int n;
i64 t[4 * MAXN];

void build(i64 a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

i64 _get(int v, int tl, int tr, int l, int r) {
	if (l > r) return LLONG_MAX;
	else if (tl == l && tr == r) return t[v];
	else {
		int tm = (tl + tr) >> 1;
		return min(_get(v*2, tl, tm, l, min(r, tm)),
				_get(v*2+1, tm+1, tr, max(l, tm+1), r));
	}
}

void update(int v, int tl, int tr, int pos, int nval) {
	if (tl == tr) t[v] = nval;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, nval);
		else update(v*2+1, tm+1, tr, pos, nval);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	i64 a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	build(a, 1, 0, n - 1);
	while (m--) {
		int x;
		cin >> x;

		if (x == 1) {
			int i, v;
			cin >> i >> v;
			update(1, 0, n - 1, i, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << _get(1, 0, n - 1, l, r - 1) << el;
		}
	}

	return 0;
}
