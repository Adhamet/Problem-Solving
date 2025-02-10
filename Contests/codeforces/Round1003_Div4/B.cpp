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

		int n = (int)s.size();
		bool found = false;
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == s[i + 1]) {
				found = true;
				break;
			}
		}

		if (found) cout << 1 << el;
		else cout << n << el;
	}

	return 0;
}
