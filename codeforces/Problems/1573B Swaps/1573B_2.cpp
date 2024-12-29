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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		vector<int> pos(2 * n + 1, 0);
		for (int i = 0; i < n; i++) pos[a[i]] = i + 1;
		for (int i = 0; i < n; i++) pos[b[i]] = i + 1;

		int ans = INT_MAX, minPosB = INT_MAX;
		for (int i = 2 * n; i >= 1; i--) {
			if (i % 2 == 0) minPosB = min(minPosB, pos[i]);
			else ans = min(ans, pos[i] + minPosB - 2);
		}

		cout << ans << el;
	}

	return 0;
}

