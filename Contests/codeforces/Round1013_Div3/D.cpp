#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	auto can = [](i64 n, i64 m, i64 k) -> i64 {
		i64 gaps = (m+1) / (k+1);
		i64 mxPerRow = max(gaps*k, m-gaps);
		return n * mxPerRow;
	};

	int t;
	cin >> t;
	while (t--) {
		i64 n, m, k;
		cin >> n >> m >> k;
		i64 l = 1, r = m, ans = m;
		while (l <= r) {
			i64 md = (l + r) >> 1;
			if (can(n, m, md) >= k)
				ans = md, r = md - 1;
			else l = md + 1;
		}

		cout << ans << el;
	}

	return 0;
}

