#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int steps(string s) {
	int n = (int)s.size();

	vector<int> dig(n);
	for (int i = 0; i < n; ++i) dig[i] = n - i - 1;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int k = s[i] - '0';
		if (k == 0) continue;

		if (i == n - 1) ans += k;
		else if (i == n - 2) {
			ans += (k * 9) + (k * 2);
		} else {
			int twos = (k * pow(10, dig[i + 2]) * 9 * 2);
			int threes = (k * pow(10, dig[i + 2]) * 1 * 3);
			ans += (k * pow(10, dig[i + 1]) * 9) + twos + threes;
		}
	}

	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		string s = to_string(r);
		string t = to_string(l);
		cout << steps(s) - steps(t) << el;
	}

	return 0;
}
