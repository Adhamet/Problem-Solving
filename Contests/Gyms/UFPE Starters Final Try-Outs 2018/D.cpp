#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n, m, t; cin >> n >> m >> t;
	i64 dx = 0, dy = 0;
	i64 dxMin = 0, dxMax = 0, dyMin = 0, dyMax = 0;
	while (t--) {
		char c; cin >> c;
		if (c == 'C') dx += 1;
		else if (c == 'B') dx -= 1;
		else if (c == 'D') dy += 1;
		else if (c == 'E') dy -= 1;

		dxMin = min(dxMin, dx);
		dxMax = max(dxMax, dx);
		dyMin = min(dyMin, dy);
		dyMax = max(dyMax, dy);
	}

	vector<array<i64, 2>> ans;
	for (i64 i = 1; i <= n; ++i) {
		if (i + dxMin < 1 || i + dxMax > n) continue;
		for (i64 j = 1; j <= m; ++j) {
			if (j + dyMin < 1 || j + dyMax > m) continue;
			ans.push_back({i + dx, j + dy});
		}
	}

	cout << (int)ans.size() << el;
	for (auto &[x, y]: ans) cout << x << ' ' << y << el;
	return 0;
}

