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
		array<int, 2> curr = {0, 0};
		map<array<int, 2>, int> mp;
		mp[curr] = 0;

		int l, r, mnAns = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'L') curr[0] += 1;
			else if (s[i] == 'R') curr[0] -= 1;
			else if (s[i] == 'U') curr[1] += 1;
			else if (s[i] == 'D') curr[1] -= 1;

			if (mp.count(curr)) {
				int currAns = i - mp[curr] + 1;
				if (mnAns == -1 || currAns < mnAns) {
					mnAns = currAns;
					l = mp[curr], r = i;
				}
			}

			mp[curr] = i + 1;
		}

		if (mnAns == -1) cout << -1 << el;
		else cout << l + 1 << ' ' << r + 1 << el;
	}

	return 0;
}
