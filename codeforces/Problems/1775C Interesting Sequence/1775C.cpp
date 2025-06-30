#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		i64 n, x;	cin >> n >> x;
		i64 l = 0, r = INT64_MAX, ans = -1;

		auto solve = [](i64 l, i64 r) -> i64 {
			i64 cnt = 0;
			while (l != r) {
				l >>= 1, r >>= 1;
				++cnt;
			}

			return (l << cnt);
		};

		while (l <= r) {
			i64 md = (l + r) >> 1;
			i64 res = solve(n, n + md);
			if (res <= x) {
				if (res == x) ans = (ans==-1)? md: min(ans,md);
				r = md - 1;
			} else l = md + 1;
		}

		cout << (ans == -1? ans: n + ans) << el;
	}  return 0;
}
