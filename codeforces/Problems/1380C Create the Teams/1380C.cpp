#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;
		i64 x;	cin >> n >> x;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		sort(a.begin(), a.end());

		int lst = n, tms = 0;
		for (int i = n - 1; i >= 0; --i)
			if (a[i] * (lst - i) >= x) lst = i, tms += 1;

		cout << tms << el;
	}

	return 0;
}
