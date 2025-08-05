#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 2e5+5, MOD = 998244353;

i64 binexp(i64 b, i64 e) {
	i64 r = 1;
	b %= MOD;
	while (e) {
		if (e & 1) r = r * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return r;
}

struct Node {
	i64 sm, lazy;
} st[4 * MXN];

int a[MXN];

void push(int v, int tl, int tr) {
	if (tl == tr) return;
	if (st[v].lazy) {
		int tm = (tl + tr) >> 1;
		st[v*2].sm = ((tm - tl + 1) * st[v].lazy) % MOD;
		st[v*2+1].sm = ((tr - tm) * st[v].lazy) % MOD;
		st[v*2].lazy = st[v*2+1].lazy = st[v].lazy;
		st[v].lazy = 0;
	}
}

void build(int v, int tl, int tr) {
	st[v].sm = 0, st[v].lazy = 0;
	if (tl == tr) st[v].sm = i64(a[tl]);
	else {
		int tm = (tl + tr) >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		st[v].sm = (st[v*2].sm + st[v*2+1].sm) % MOD;
	}
}

void upd(int v, int tl, int tr, int l, int r, i64 x) {
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		st[v].sm = ((tr - tl + 1) * x) % MOD;
		st[v].lazy = x;
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	upd(v*2, tl, tm, l, r, x);
	upd(v*2+1, tm+1, tr, l, r, x);
	st[v].sm = (st[v*2].sm + st[v*2+1].sm) % MOD;
}

i64 qry(int v, int tl, int tr, int l, int r) {
	if (tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) return st[v].sm;
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	return (qry(v*2, tl, tm, l, r) +
			qry(v*2+1, tm+1, tr, l, r)) % MOD;
}

void propagateLazy(int v, int tl, int tr) {
	if (st[v].lazy) push(v, tl, tr); 
	if (tl == tr) {
		a[tl] = st[v].sm;
		return;
	}
	int tm = (tl + tr) >> 1;
	propagateLazy(v*2, tl, tm);
	propagateLazy(v*2+1, tm+1, tr);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(1, 1, n);

	while (m--) {
		int l, r;	cin >> l >> r;
		i64 sm = qry(1, 1, n, l, r);
		i64 len = binexp(r - l + 1, MOD - 2);
		i64 nsm = (sm * len) % MOD;
		upd(1, 1, n, l, r, nsm);
	}

	propagateLazy(1, 1, n);
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " \n"[i == n];
	return 0;
}
