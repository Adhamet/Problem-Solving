#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MOD = 1e9+7;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i32 t; cin >> t;
	while (t--) {
		i32 n; cin >> n;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		i64 cnt = 0;
		bool acc = true;
		i64 mn = *min_element(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			if (mn == a[i]) ++cnt;
			if ((mn&a[i]) != mn) {
				acc = false;
				break;
			}
		}

		if (!acc) {
			cout << 0 << el;
			continue;
		} else {
			i64 f = 1;
			for (i64 x = 2; x <= (n - 2); ++x) f = (f * x) % MOD;
			i64 ccnt = (1LL * cnt * (cnt - 1)) % MOD;
			i64 ans = (1LL * ccnt * f) % MOD;
			cout << ans << el;
		}
	}

	return 0;
}
