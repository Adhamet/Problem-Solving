#include <algorithm>
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
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n - 1; ++i) {
			int diff = min(a[i], a[i+1]);
			a[i] -= diff, a[i+1] -= diff;
		}

		bool ok = true;
		for (int i = 0; i < n - 1; ++i) if (a[i] > a[i+1])
			ok = false;
		if (ok) cout << "YES" << el;
		else cout << "NO" << el;
	}

	return 0;
}
