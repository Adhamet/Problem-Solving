#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i64 MOD = 1e9+7;
i64 binexp(i64 a, i64 b) {
	i64 res = 1;
	a %= MOD;
	while (b > 0) {
		if (b&1) res = (res*a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	i64 n, m, q; cin >> n >> m >> q;
	while (q--) {
		i64 a,b; cin >> a >> b;
		if (b < m) cout << 0 << el;
		else {
			b += 1;
			cout << binexp(2, n+m-(((a+b)%b)+1)) << el;
		}
	}

	return 0;
}
