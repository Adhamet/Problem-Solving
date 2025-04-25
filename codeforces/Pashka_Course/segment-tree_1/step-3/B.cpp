#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 100005;
int n, t[4 * MAXN];

void build(int v, int tl, int tr) {
	if (tl == tr) t[v] = 1;
	else {
		int tm = (tl + tr) >> 1;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int x) {
	if (tl == tr) t[v] = 0;
	else {
		int tm = (tl + tr) >> 1;
		if (x <= tm) update(v*2,tl,tm,x);
		else update(v*2+1,tm+1,tr,x);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int find(int v, int tl, int tr, int k) {
	if (tl == tr) return tl;
	int tm = (tl + tr) >> 1;
	if (t[v*2+1] > k) return find(v*2+1, tm+1 ,tr,k);
	else return find(v*2, tl, tm, k-t[v*2+1]);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	int res[n];
	build(1, 1, n);
	for (int i = n - 1; i >= 0; --i) {
		int val = find(1, 1, n, a[i]);
		res[i] = val;
		update(1, 1, n, val);
	}

	for (int i = 0; i < n; ++i) cout << res[i] << ' ';
	return 0;
}
