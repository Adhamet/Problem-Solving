#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < m; ++i) cin >> b[i];
	
		vector<int> l(m + 1, -1);
		l[0] = -1;
	
		for (int i = 0, j = 0; i < n; ++i) {
			if (j >= m) break;
			if (a[i] >= b[j]) {
				l[j + 1] = i;
				j += 1;
			}
		}

		if (l[m] != -1) {
			cout << 0 << el;
			continue;
		}

		vector<int> r(m + 1, -1);
		r[m] = n;

		int j = m - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (j < 0) break;
			if (a[i] >= b[j]) {
				r[j] = i;
				j -= 1;
			}
		}

		int mn = INT_MAX;
		for (int i = 0; i < m; ++i) {
			if (r[i + 1] != -1) {
				if (i == 0 || (l[i] != -1 && l[i] < r[i+1])) {
					mn = min(mn, b[i]);
				}
			}
		}

		cout << (mn == INT_MAX? -1: mn) << el;
	}
	
	return 0;
}
