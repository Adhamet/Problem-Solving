#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

i64 binexp(i64 a, i64 b) {
	i64 res = 1;
	while (b > 0) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;  cin >> t;
	while (t--) {
		i64 n, k;
		cin >> n >> k;
		k++;

		vector<pair<i64,i64>> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i].fst;
		for (int i = 0; i < n - 1; ++i)
			a[i].scd = binexp(10, a[i+1].fst) / binexp(10, a[i].fst) - 1;

		i64 ans = 0;
		int i = 0;
		while (k > 0 && i < n - 1) {
			i64 use = min(k, a[i].scd);
			ans += use * binexp(10, a[i].fst);
			k -= use;
			++i;
		}

		if (k > 0) ans += k * binexp(10, a[n-1].fst);
		cout << ans << el;
	}

	return 0;
}

