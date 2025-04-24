#include <algorithm>
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
		int n, k;
		cin >> n >> k;

		vector<int> a(n), b(n), c;
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			if (b[i] != -1) c.push_back(a[i] + b[i]);
		}

		bool acc = true;
		for (int i = 0; i < (int)c.size() - 1; ++i) {
			if (c[i] != c[i + 1]) {
				acc = false;
				break;
			}
		}

		if (!acc) cout << 0 << el;
		else {
			if ((int)c.size() >= 1) {
				if (c[0] < *max_element(a.begin(), a.end())) {
					cout << 0 << el;
				} else if (*min_element(a.begin(), a.end()) + k >= c[0]) {
					cout << 1 << el;
				} else cout << 0 << el;
			} else {
				int mn = *min_element(a.begin(), a.end());
				int mx = *max_element(a.begin(), a.end());
				cout << mn + k - mx + 1 << el;
			}
		}
	}

	return 0;
}	
