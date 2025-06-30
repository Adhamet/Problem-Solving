#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		i64 p, q;	cin >> p >> q;
		if (p < q) {
			cout << p << el;
			continue;
		} else if (p % q != 0) {
			cout << p << el;
			continue;
		}

		i64 qq = q;
		vector<i64> factors;
		for (i64 d = 2; d * d <= qq; ++d) {
			if (qq % d == 0) {
				factors.push_back(d);
				while (qq % d == 0) qq /= d;
			}
		}

		if (qq > 1) factors.push_back(qq);

		i64 ans = 1;
		for (i64 pr: factors) {
			i64 curr = p;
			while (curr % q == 0) curr /= pr;
			ans = max(ans, curr);
		}

		cout << ans << el;
	}

	return 0;
}
