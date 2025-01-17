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
		int n, k;
		string s;
		cin >> n >> k >> s;
		int first = n, last = -1, ones = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') {
				if (first == n) first = i;
				last = i, ones++;
			}
		}

		if (ones == 0) {
			cout << 0 << el;
			continue;
		}

		int change = 0;
		if ((n - 1 - last) <= k) {
			k -= (n - 1 - last);
			change += 1, ones--;
		}
		if (ones > 0 && first <= k) k -= first, change += 10, ones--;
		int ans = 11 * ones + change;
		cout << ans << el;
	}

	return 0;
}
