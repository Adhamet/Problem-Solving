#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int mx = *max_element(a.begin(), a.end());
		int mn = *min_element(a.begin(), a.end());

		if (mx - mn > k + 1) cout << "Jerry" << el;
		else {
			int sum = accumulate(a.begin(), a.end(), 0LL);
			if (sum % 2 == 0) cout << "Jerry" << el;
			else cout << "Tom" << el;
		}
	}

	return 0;
}
