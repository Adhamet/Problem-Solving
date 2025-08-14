#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << el;*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());

		i64 cand1 = (a[n - 1] - a[0]) + (a[1] - a[0]);
		i64 cand2 = (a[n - 1] - a[0]) + (a[n - 1] - a[n - 2]);
		cout << max(cand1, cand2) << el;
	}

	return 0;
}
