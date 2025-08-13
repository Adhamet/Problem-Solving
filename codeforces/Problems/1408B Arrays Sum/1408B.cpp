#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

void solve() {
	int n, k;	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	set<int> st(a.begin(), a.end());
	if (k == 1) {
		if ((int)st.size() == 1) cout << 1 << el;
		else cout << -1 << el;
		return;
	}

	int rem = max(0, (int)st.size() - k);
	int m = 1 + (rem + (k - 2)) / (k - 1);
	cout << m << el;
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
