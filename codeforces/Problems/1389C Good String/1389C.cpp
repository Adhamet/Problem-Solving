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
		int n = (int)s.size(), ans = n - 2;

		vector<int> freq(10, 0);
		for (int i = 0; i < n; ++i) {
			freq[s[i] - '0'] += 1;
			ans = min(ans, n - freq[s[i] - '0']);
		}

		for (int a = 0; a < 10; ++a) {
			for (int b = 0; b < 10; ++b) {
				int curr = 0;
				bool turn = true;
				for (char ch: s) {
					if (turn && ch - '0' == a) curr += 1, turn = !turn;
					else if (!turn && ch - '0' == b) curr += 1, turn = !turn;
				}

				if (curr % 2 != 0) curr -= 1;
				ans = min(ans, n - curr);
			}
		}

		cout << ans << el;
	}

	return 0;
}
