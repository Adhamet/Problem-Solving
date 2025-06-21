#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, s; cin >> n >> s;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());

		if (abs(s - a[n-1]) <= abs(s - a[0])) {
			cout << abs(a[n-1] - s) + abs(a[n-1] - a[0]) << el;
		} else cout << abs(s - a[0]) + abs(a[n-1] - a[0]) << el;
	}

	return 0;
}
