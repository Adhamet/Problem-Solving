#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

const i64 MXN = 1e5+5, oo = 1e18;

struct Node {
	i64 mn = oo;
} t[4*MXN];
i64 n, a[MXN], k, pref[MXN];

void upd(int v, int tl, int tr, int l, int r, i64 val) {
	if (r < tl || tr < l) return;
	if (l <= tl && tr <= r) {
		t[v].mn = min(t[v].mn, val);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v*2, tl, tm, l, r, val);
	upd(v*2+1, tm+1, tr, l, r, val);
}

i64 findKth(int v, int tl, int tr, int k) {
	if (tl == tr) return t[v].mn;
	int tm = (tl + tr) >> 1;
	if (k <= tm) return min(t[v].mn, findKth(v*2, tl, tm, k));
	else return min(t[v].mn, findKth(v*2+1, tm+1, tr, k));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	pref[0] = 0;
	for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + a[i];

	int l = 0, r = 0;
	while (l < n) {
		while (r < n && pref[r+1] - pref[l] < k) ++r;
		if (r < n) upd(1,0,n-1,l,r,pref[r+1]-pref[l]);
		++l;
		if (r < l) r = l;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		i64 x = findKth(1, 0, n - 1, i);
		if (x == oo || x - a[i] >= k) ++cnt;
	}

	return cout << cnt, 0;
}
