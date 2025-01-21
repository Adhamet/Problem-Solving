#include <algorithm>
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
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		for (int i = 0; i < n; ++i) {
			cout << abs(*lower_bound(b.begin(), b.end(), a[i]) - a[i]) << ' ';
		}
		cout << el;
		
		int l = 0, r = 0;
		vector<array<int, 3>> ranges;
		while (r < n) {
			if (r == n - 1 || (r < n - 1 && a[r + 1] > b[r])) {
				ranges.push_back({l, r, b[r]});
				l = r + 1;
			} r += 1;
		}

		for (auto rng: ranges) {
			for (int i = rng[0]; i <= rng[1]; ++i) {
				cout << rng[2] - a[i] << ' ';
			}
		}
		cout << el;
	}

	return 0;
}
