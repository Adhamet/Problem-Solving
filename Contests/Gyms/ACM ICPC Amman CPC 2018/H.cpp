#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(2*n+2);

		for (int i = 1; i <= 2*n; ++i) cin >> a[i];

		int ans = 0;
		for (int i = 1; i <= 2*n; ++i) {
			ans = max(ans, a[i]+a[2*n-i+1]);
		}

		cout << ans << el;
	}

	return 0;
}
