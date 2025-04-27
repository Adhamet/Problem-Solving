#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int long long
#define el '\n'

const int MAXN = 100005, MAXV = 41;
int n, q;

struct Node {
	int cnt[MAXV]; // cnt of each value in segment
	int inv;
	Node() { inv = 0, memset(cnt, 0, sizeof cnt); }
};

Node t[4 * MAXN];

Node combine(Node left, Node right) {
	Node res;
	res.inv = left.inv + right.inv;

	for (int i = 1; i <= 40; ++i) 
		for (int j = 1; j < i; ++j)
			res.inv += (left.cnt[i] * right.cnt[j]);

	for (int i = 1; i <= 40; ++i)
		res.cnt[i] = left.cnt[i] + right.cnt[i];
	return res;
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		memset(t[v].cnt, 0, sizeof(t[v].cnt));
		t[v].cnt[a[tl]] = 1, t[v].inv = 0;
	} else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		memset(t[v].cnt, 0, sizeof(t[v].cnt));
		t[v].cnt[val] = 1, t[v].inv = 0;
	} else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, val);
		else update(v*2+1, tm+1, tr, pos, val);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r) {
		Node empty;
        empty.inv = 0;
        memset(empty.cnt, 0, sizeof(empty.cnt));
        return empty;
	}
	if (l == tl && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	Node res;
	if (r <= tm) res = query(v*2, tl, tm, l, r);
	else if (l > tm) res = query(v*2+1, tm+1, tr, l, r);
	else res = combine(query(v*2, tl, tm, l, tm), query(v*2+1, tm+1, tr, tm+1, r));
	return res;
}


int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
	int a[n+1];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	build(a, 1, 1, n);
	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1)
			cout << query(1, 1, n, x, y).inv << el;
		else update(1, 1, n ,x ,y);
	}

	return 0;
}
