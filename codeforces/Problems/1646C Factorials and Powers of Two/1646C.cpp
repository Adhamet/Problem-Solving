#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<i64> fct(17);
	fct[0] = 1;
	for (int i = 1; i <= 16; ++i)
		fct[i] = fct[i - 1] * i;

	int t; cin >> t;
	while (t--) {
		i64 n; cin >> n;
		int ans = __builtin_popcountll(n);
		for (int msk = 1; msk < (1 << 17); ++msk) {
			i64 sm = 0;
			for (int i = 0; i < 17; ++i)
				if (msk >> i & 1)
					sm += fct[i];

			if (sm > n) continue;

			int cost = __builtin_popcountll(n-sm) + __builtin_popcount(msk);
			ans = min(ans, cost);
		}

		cout << (ans > 60 ? -1 : ans) << el;
	}
	return 0;
}

