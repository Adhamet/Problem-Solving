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
		int k, l1, r1, l2, r2, cnt = 0, os = 1;
		cin >> k >> l1 >> r1 >> l2 >> r2;

		if (l2 <= l1 && r2 >= r1) cnt += r1 - l1 + 1;
		else if (l1 <= l2 && r1 >= r2) cnt += r2 - l2 + 1;
		else if (l2 <= l1 && l1 <= r2) cnt += r2 - l1 + 1;
		else if (l1 <= l2 && l2 <= r1) cnt += r1 - l2 + 1;

		while (true) {
			int currK = pow(k, os);
			if (currK > r2) break;

			int l = max(l1, (l2 + currK - 1) / currK);
			int r = min(r2 / currK, r1);
			if (r - l + 1 > 0) cnt += (r - l + 1);
			os += 1;
		}

		cout << cnt << el;
	}

	return 0;
}
