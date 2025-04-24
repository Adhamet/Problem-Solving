#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 100000;
int n, t[4 * MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = (a[tl] == 1);
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

void update(int v, int tl, int tr, int idx) {
	if (tl == tr) t[v] ^= 1;
	else {
		int tm = (tl + tr) >> 1;
		if (idx <= tm) update(v*2, tl, tm, idx);
		else update(v*2+1, tm+1, tr, idx);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int find(int v, int tl, int tr, int k) {
	if (k >= t[v]) return -1;
	if (tl == tr) return tl;

	int tm = (tl + tr) >> 1;
	if (k < t[v*2]) return find(v*2, tl, tm, k);
	else return find(v*2+1, tm+1, tr, k - t[v*2]);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	build(a, 1, 0, n - 1);
	while (m--) {
		int q;
		cin >> q;

		if (q == 2) {
			int k;
			cin >> k;
			cout << find(1, 0, n - 1, k) << el;
		} else {
			int idx;
			cin >> idx;
			update(1, 0, n - 1, idx);
		}
	}

	return 0;
}
