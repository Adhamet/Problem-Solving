#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		i64 n; cin >> n;
		i64 ans = 0;
		while (n) {
			ans += n;
			n >>= 1;
		}

		cout << ans << el;
	}

	return 0;
}
