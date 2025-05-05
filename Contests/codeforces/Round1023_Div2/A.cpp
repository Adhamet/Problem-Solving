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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		int mxIdx = max_element(a.begin(), a.end()) - a.begin();

		int gcdRes;
		if (mxIdx == 0) {
			gcdRes = a[1];
			for (int i = 2; i < n; ++i) gcdRes = __gcd(gcdRes, a[i]);
			if (gcdRes == a[mxIdx]) cout << "No" << el;
			else {
				cout << "Yes" << el;
				for (int i = 0; i < n; ++i) {
					if (mxIdx == i) cout << 2 << ' ';
					else cout << 1 << ' ';
				}
				
				cout << el;
			}
		} else {
			gcdRes = a[0];
			for (int i = 1; i < n; ++i) {
				if (mxIdx == i) continue;
				gcdRes = __gcd(gcdRes, a[i]);
			}

			if (gcdRes == a[mxIdx]) cout << "No" << el;
			else {
				cout << "Yes" << el;
				for (int i = 0; i < n; ++i) {
					if (mxIdx == i) cout << 2 << ' ';
					else cout << 1 << ' ';
				}

				cout << el;
			}
		}
	}

	return 0;
}
