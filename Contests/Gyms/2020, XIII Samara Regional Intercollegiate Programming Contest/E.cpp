#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	auto can = [&](i64 k) {
		for (int i = 0; i < n; ++i) {
			k += a[i];
			if (k < 0) return false;
		} return true;
	};

	i64 l = 0, r = 1e18, ans = 0;
	while (l<=r) {
		i64 md = (l+r)>>1;
		if (can(md)) r = md - 1, ans = md;
		else l = md + 1;
	}

	return cout << ans, 0;
}
