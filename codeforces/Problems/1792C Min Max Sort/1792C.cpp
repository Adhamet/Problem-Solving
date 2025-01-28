#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int l = 0, r = n / 2, ans = n / 2;
		while (l <= r) {
			int mid = (l + r) >> 1, curr = mid + 1;

			for (int i = 0; i < n; ++i) if (curr == a[i]) curr += 1;
			if (curr > n - mid) ans = mid, r = mid - 1;
			else l = mid + 1;
		}

		cout << ans << el;
	}

	return 0;
}
