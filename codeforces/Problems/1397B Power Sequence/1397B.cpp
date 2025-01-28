#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	int mn = LLONG_MAX;
	if (n >= 40) {
		int cost = 0;
		for (int i = 0; i < n; ++i) cost += abs(a[i] - 1);
		cout << cost << el;
		return 0;
	}

	for (int c = 1; c <= 35000; ++c) {
		int curr = 0, power = 1;
		bool of = false;
		for (int i = 0; i < n; ++i) {
			curr += abs(a[i] - power);
			if (i < n - 1) {
				if (power > LLONG_MAX/c) {
					of = true;
					break;
				}

				power *= c;
			}
		}

		if (!of) mn = min(mn, curr);
	}

	return cout << mn, 0;
}
