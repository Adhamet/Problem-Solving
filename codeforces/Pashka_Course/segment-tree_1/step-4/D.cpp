#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int MAXN = 100005;
int n, q;
int a[MAXN];

struct Node {
	uint64_t mask;
	Node() : mask(0) {}
};

Node t[4 * MAXN];

Node combine(Node l, Node r) {
	Node res;
	res.mask = l.mask | r.mask;
	return res;
}

void build(int v, int tl, int tr) {
	if (tl == tr) t[v].mask = (1ULL << a[tl]);
	else {
		int tm = (tl + tr) >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) t[v].mask = (1ULL << val);
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, val);
		else update(v*2+1, tm+1, tr, pos, val);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r) return Node();
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return combine(query(v*2, tl, tm, l, min(r, tm)),
			query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	build(1, 1, n);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) {
			Node res = query(1, 1, n, x, y);
			cout << __builtin_popcountll(res.mask) << el;
		} else update(1, 1, n, x, y);
	}

	return 0;
}
