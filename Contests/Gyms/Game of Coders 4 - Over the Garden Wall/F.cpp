#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

const int MXN = 1e5;

struct Node {
	vector<int> a;
};

int a[MXN];
Node t[4*MXN];

void build(int v, int tl, int tr) {
	if (tl == tr) t[v].a = { a[tl] };
	else {
		int tm = (tl + tr) >> 1;
		build(v*2, tl, tm);
		build(v*2+1, tm+1, tr);
		t[v].a.insert(t[v].a.end(),
				t[v*2].a.begin(), t[v*2].a.end());
		t[v].a.insert(t[v].a.end(),
				t[v*2+1].a.begin(), t[v*2+1].a.end());
		sort(t[v].a.begin(), t[v].a.end());
	}
}

int query(int v, int tl, int tr, int l, int r, int x, int y) {
	if (tr < l || tl > r) return 0;
	if (tl >= l && tr <= r) {
		int rr = upper_bound(t[v].a.begin(),t[v].a.end(), y)
						- t[v].a.begin();
		int ll = lower_bound(t[v].a.begin(),t[v].a.end(), x)
						- t[v].a.begin();
		return rr - ll;
	}
	int tm = (tl+tr)>>1;
	return query(v*2,tl,tm,l,r,x,y)+query(v*2+1,tm+1,tr,l,r,x,y);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, q;	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> a[i];

	build(1, 0, n - 1);
	while (q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		l--,r--;
		cout << query(1,0,n-1,l,r,x,y) << el;
	}

	return 0;
}
