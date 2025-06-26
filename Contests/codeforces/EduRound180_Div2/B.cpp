#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		bool acc = false;
		for (int i = 0; i < n - 1; ++i) if (abs(a[i]-a[i+1]) <= 1) {
			acc = true;
			break;
		}

		if (acc) {
			cout << 0 << el;
			continue;
		}

		bool inc = 0, dec = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] < a[i+1]) inc = true;
			if (a[i] > a[i+1]) dec = true;
		}

		cout << (inc && dec? 1: -1) << el;
	}  return 0;
}
