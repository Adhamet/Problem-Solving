#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int> c(n);
	int sign = (n % 2 ? +1: -1);
	for (int i = 0; i < n; ++i) {
		c[i] = sign;
		sign = -sign;
	}

	vector<i64> pref(n+1, 0);
	for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + c[i-1];

	i64 tot = 0;
	for (int i = 0; i < n; ++i) tot += i64(c[i]) * a[i];

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		i64 v;
		cin >> l >> r >> v;
		--l; --r;
		tot += (v * (pref[r+1] - pref[l]));
		cout << tot << el;
	}

	return 0;
}

