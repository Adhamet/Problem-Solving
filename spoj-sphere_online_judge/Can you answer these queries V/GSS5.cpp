#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

const int MAXN = 50005;
const i64 oo = 1e18;
struct Node {
	int sum, pref, suff, ans;
};

Node t[4*MAXN];

Node combine(Node left, Node right) {
	Node res;
	res.sum = left.sum + right.sum;
	res.pref = max(left.pref, left.sum + right.pref);
	res.suff = max(right.suff, right.sum + left.suff);
	res.ans = max({left.ans, right.ans, left.suff + right.pref});
	return res;
}

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = {a[tl], a[tl], a[tl], a[tl]};
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = combine(t[v*2], t[v*2+1]);
	}
}

Node query(int v, int tl, int tr, int l, int r) {
	if (l > r || tr < l || tl > r) return {0, -oo, -oo, -oo};
	if (tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	Node left = query(v*2, tl, tm, l, min(r, tm));
	Node right = query(v*2+1, tm+1, tr, max(l, tm+1), r);
	return combine(left, right);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		build(a, 1, 0, n - 1);

		cin >> m;
		while (m--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--, y1--, x2--, y2--;
	
			int res;
			if (x2 > y1) {
				Node mid = query(1, 0, n - 1, y1 + 1, x2 - 1);
				Node left = query(1, 0, n - 1, x1, y1);
				Node right = query(1, 0, n - 1, x2, y2);
				res = left.suff + mid.sum + right.pref;
			} else {
				Node mid = query(1, 0, n - 1, x2, y1);
				Node opt1 = query(1, 0, n - 1, x1, x2 - 1);
				Node opt2 = query(1, 0, n - 1, x1, y1);
				Node opt3 = query(1, 0, n - 1, x2, y2);
				Node opt4 = query(1, 0, n - 1, y1 + 1, y2);
				res = max({mid.ans, opt1.suff + opt3.pref, opt2.suff + opt4.pref});
			}

			cout << res << el;
		}
	}

	return 0;
}

