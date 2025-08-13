#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

void solve() {
	int n;	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	bool allEq = true;
	int x = abs(a[0]);
	for (int i = 1; i < n; ++i) if (abs(a[i]) != x) {
		allEq = false;
		break;
	}

	if (allEq) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += (a[i] < 0);

		if (cnt == 0 || cnt == n || abs(n - 2*cnt) <= 1) {
			cout << "Yes" << el;
			return;
		} else {
			cout << "No" << el;
			return;
		}
	}

	sort(a.begin(), a.end(), [](auto &p, auto &q) {
		return abs(p) < abs(q);
	});

	for (int i = 0; i < n - 2; ++i) if (a[i+2]*a[i] != a[i+1]*a[i+1]) {
		cout << "No" << el;
		return;
	}

	cout << "Yes" << el;
	return;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int _tc = 1;
	cin >> _tc;
	while (_tc--) {
		solve();
	}

	return 0;
}
