#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

static i64 mem[1<<15][15];
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<i64> a(n), c(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> c[i];
		for (int msk = 0; msk <= (1<<n)-1; ++msk)
			for (int lst = 0; lst < n; ++lst)
				mem[msk][lst] = -1;

		function<i64(int,int)> go = [&](int msk, int lst) -> i64 {
			if (msk == (1<<n)-1) return 0;

			i64 &ret = mem[msk][lst];
			if (ret != -1) return ret;
			ret = 1e18;

			int ci = __builtin_popcount(msk);
			for (int i = 0; i < n; ++i) if (!(msk & (1<<i))) {
				i64 cost = llabs(a[i] - a[lst]) * c[ci];
				ret = min(ret, cost + go(msk | (1<<i), i));
			}

			return ret;
		};


		i64 ans = 1e18;
		for (int i = 0; i < n; ++i)
			ans = min(ans, go(1ll<<i, i));
		cout << ans << el;
	}

	return 0;
}
