#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5 + 5;
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = __gcd(t[v*2], t[v*2+1]);
	}
}

void update(int v, int tl, int tr, int idx) {
	if (tl == tr) t[v] = 1e9+7;
	else {
		int tm = (tl + tr) >> 1;
		if (idx <= tm) update(v*2, tl, tm, idx);
		else update(v*2+1, tm+1, tr, idx);
		t[v] = __gcd(t[v*2], t[v*2+1]);
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (l > r || l > tr || r < tl) return 0;
	if (l <= tl && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return __gcd(query(v*2, tl, tm, l, r), 
			query(v*2+1, tm+1, tr, l, r));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	int a[n];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(a, 1, 1, n);

	int curr = 0;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		bool found = false;

		while (l <= r) {
			int mid = (l + r) >> 1;
			int g = query(1, 1, n, mid, i);
			if (g > i - mid + 1) r = mid - 1;
			else if (g < i - mid + 1) l = mid + 1;
			else {
				found = true;
				break;
			}
		}

		if (found) ++curr, update(1, 1, n, i);
		cout << curr << ' ';
	}

	return 0;
}
