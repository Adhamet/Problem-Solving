#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int cnt = 0, i = 0;
		while (i <= n - k) {
			bool canHike = true;
			for (int j = 0; j < k; ++j) {
				if (a[i + j] != 0) {
					canHike = false;
					break;
				}
			}

			if (canHike) cnt++, i += k + 1;
			else i++;
		}

		cout << cnt << el;
	}

	return 0;
}

