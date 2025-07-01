#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, j, k;	cin >> n >> j >> k;
		vector<int> a(n+1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];

		int cnt = 0;
		vector<bool> vis(n+1, false);
		vis[j] = true;
		for (int i = 1; i <= n; ++i) if (i != j) {
			if (a[j] >= a[i]) {
				cnt += 1;
				vis[i] = true;
			}
		}

		if (n - cnt <= k) {
			cout << "YES" << el;
			continue;
		}

		int mxIdx = max_element(a.begin(), a.end()) - a.begin();

		for (int i = 1; i <= n; ++i) if (i != mxIdx && !vis[i]) {
			cnt += 1;
		}

		if (n - cnt <= k) {
			cout << "YES" << el;
			continue;
		} else cout << "NO" << el;
	}

	return 0;
}
