#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 100005;
int n, t[4 * MAXN];

void update(int v, int tl, int tr, int idx) {
	if (tl == tr) t[v] += 1;
	else {
		int tm = (tl + tr) >> 1;
		if (idx <= tm) update(v*2, tl, tm, idx);
		else update(v*2+1, tm+1, tr, idx);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(v*2, tl, tm, l, min(r, tm)) +
		query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
	for (int i = 0; i < n; ++i) {
		int cnt = query(1, 0, n - 1, a[i] + 1, n - 1);
		cout << cnt << ' ';
		update(1, 0, n - 1, a[i]);
	}

	return 0;
}
