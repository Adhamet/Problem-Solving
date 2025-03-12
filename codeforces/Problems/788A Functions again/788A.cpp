#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t n;
	cin >> n;
	vector<int64_t> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<int64_t> pref(n - 1, 0);

	for (int i = 0; i < n - 1; ++i) {
		pref[i] = abs(a[i] - a[i + 1]);
		if (i % 2 != 0) pref[i] = -pref[i];
	}

	int64_t mx = 0;
	auto kadane = [&](vector<int64_t> &a) {
		int64_t curr = 0;
		for (int64_t x: pref) {
			curr = max(x, curr + x);
			mx = max(mx, curr);
		}
	};

	kadane(pref);
	for (int i = 0; i < n - 1; ++i) pref[i] = -pref[i];
	kadane(pref);
	return cout << mx, 0;
}
