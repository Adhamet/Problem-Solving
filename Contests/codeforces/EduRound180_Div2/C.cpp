#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<i64> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		i64 last = a.back();

		i64 ans = 0;
		for (int k = 2; k < n; ++k) {
			i64 th;
			if (a[k] == last) th = last;
			else th = max(last - a[k], a[k]);

			int i = 0, j = k - 1;
			i64 curr = 0;
			while (i < j) {
				if (a[i]+a[j] > th) curr+=(j-i), j--;
				else ++i;
			}

			ans += curr;
		}

		cout << ans << el;
	}  return 0;
}
