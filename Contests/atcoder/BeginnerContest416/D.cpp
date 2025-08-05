#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, m;	cin >> n >> m;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];

		int j = 0, c = 0;
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; ++i) {
			while (j < n && a[i] + b[j] < m) j += 1;
			if (j == n) break;
			++j, ++c;
		}

		i64 sm = 0;
		for (int i = 0; i < n; ++i) sm += a[i] + b[i];
		cout << sm - i64(m) * c << el;
	}

	return 0;
}
