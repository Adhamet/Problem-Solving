#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MOD = 1e9 + 7;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n, m, tot = 0;	cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int l, r, x;	cin >> l >> r >> x;
			tot |= x;
		}

		int res = 1;
		for (int i = 1; i < n; ++i) res = (res << 1) % MOD;
		cout << (1LL * res * tot) % MOD << el;
	} return 0;
}
