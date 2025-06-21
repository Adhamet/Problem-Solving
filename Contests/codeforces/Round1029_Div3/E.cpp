#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];

		if (a.back() == b.back()) {
			cout << n << el;
			continue;
		}

		int ans = -1;
		vector<bool> seen(n+1);
		for (int i = n - 2; i >= 0; --i) {
			if (a[i]==b[i] || a[i]==a[i+1] || b[i]==b[i+1] || seen[a[i]] || seen[b[i]]) {
				ans = i;
				break;
			}

			seen[a[i+1]] = seen[b[i+1]] = true;
		}

		cout << ans + 1 << el;
	}

	return 0;
}
