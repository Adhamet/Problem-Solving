#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MAXN = 100000;

struct Data {
	i64 sum, pref, suff, ans;

	Data(): sum(0), pref(0), suff(0), ans(0) {}
	Data(i64 val) {
		sum = val;
		pref = suff = ans = max(val, (i64)0);
	};
	Data(Data x, Data y) {
		sum = x.sum + y.sum;
		pref = max(x.pref, x.sum + y.pref);
		suff = max(y.suff, x.suff + y.sum);
		ans = max({x.ans, y.ans, x.suff + y.pref});
	}
};

int n;
Data t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = Data(a[tl]);
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = Data(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int idx, int val) {
	if (tl == tr) t[v] = Data(val);
	else {
		int tm = (tl + tr) >> 1;
		if (idx <= tm) update(v*2, tl, tm, idx, val);
		else update(v*2+1, tm+1, tr, idx, val);
		t[v] = Data(t[v*2], t[v*2+1]);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	build(a, 1, 0, n - 1);
	cout << t[1].ans << el;
	while (m--) {
		int i, v;
		cin >> i >> v;
		update(1, 0, n - 1, i, v);
		cout << t[1].ans << el;
	}

	return 0;
}
