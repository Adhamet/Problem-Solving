#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define el '\n'
#define int long long

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;

		vector<int> a(n), b(n), aff(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		int tot = 0;
		for (int i = 0; i < n; i++) {
			aff[i] = a[i] * b[i];
			tot += a[i] * b[i];
		}

		if (tot < x) {
			cout << -1 << el;
			continue;
		}
		
		int ans = n;
		sort(aff.begin(), aff.end());
		for (int i = 0; i < n; i++) {
			if (tot > x) {
				tot -= aff[i];
				if (tot < x) break;
				ans -= 1;
				if (tot == x) break;
			}
		}

		cout << ans << el;
	}

	return 0;
}
