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
		int n;
		string s;
		cin >> n >> s;

		int k = 1;
		string t = s;
		for (int i = 1; i < n; ++i) {
			string tt = "";
			for (int j = i; j < n; ++j) tt += s[j];

			int after = n - i;
			if (after % 2 == 0) {
				for (int j = 0; j < i; ++j) tt += s[j];
			} else {
				for (int j = i - 1; j >= 0; --j) tt += s[j];
			}

			if (tt < t) t = tt, k = i + 1;
		}

		cout << t << el << k << el;
	}

	return 0;
}
