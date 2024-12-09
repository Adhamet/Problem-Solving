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
		string s;
		cin >> s;

		int n = s.size(), tot = 0;
		for (int i = 0; i < n; i++) tot += (s[i] - '0');

		if (tot % 9 == 0) cout << "YES" << el;
		else {
			int cnt2 = 0, cnt3 = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '2') cnt2 += 1;
				else if (s[i] == '3') cnt3 += 1;
			}

			bool ok = false;
			for (int two = 0; two <= cnt2; two++) {
				for (int three = 0; three <= cnt3; three++) {
					int tmp = tot;
					tmp = (tot + 2 * two + 6 * three);
					if (tmp % 9 == 0) {
						ok = true;
						break;
					}
				}

				if (ok) break;
			}
			
			cout << (ok ? "YES": "NO") << el;
		}
	}

	return 0;
}
