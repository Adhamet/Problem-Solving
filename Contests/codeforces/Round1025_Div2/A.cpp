#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		bool acc = true;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == 0 && a[i+1] == 0) acc = false;
		}

		int sm = accumulate(a.begin(), a.end(), 0);
		if (sm == n || sm == 0 || !acc) {
			cout << "YES" << el;
		} else cout << "NO" << el;
	}

	return 0;
}
