#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 n, t;
	cin >> n >> t;
	vector<i64> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];

	auto can = [&](int k) -> bool {
		if (k == 0) return true;
		for (int i = 0; i + k - 1 < n; i++) {
			i64 lft = x[i], rgt = x[i + k - 1];
			i64 rng = rgt - lft;
			i64 cost1 = abs(lft) + rng;
			i64 cost2 = abs(rgt) + rng;
			if (min(cost1, cost2) <= t) return true;
		} return false;
	};

	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int md = (l + r) >> 1;
		if (can(md)) l = md + 1, ans = md;
		else r = md - 1;
	}

	return cout << ans, 0;
}

