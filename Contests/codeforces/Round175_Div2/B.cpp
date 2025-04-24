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
		int n, x, k, steps = -1;
		cin >> n >> x >> k;

		string s;
		cin >> s;

		bool first = true;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			if (i == 0) a[i] = (s[i] == 'L'? -1: 1);
			else a[i] = (a[i - 1] + (s[i] == 'L'? -1: 1));
			if (first && x + a[i] == 0) {
				first = false;
				steps = i + 1;
			}
		}

		if (steps > k) {
			cout << 0 << el;
			continue;
		} else if (steps == -1) {
			cout << 0 << el;
			continue;
		}

		bool found = false;
		for (int i = 0; i < n; ++i) if (a[i] == 0) {
			cout << 1 + ((k - steps) / (i + 1)) << el;
			found = true;
			break;
		}

		if (!found) cout << 1 << el;
	}

	return 0;
}
