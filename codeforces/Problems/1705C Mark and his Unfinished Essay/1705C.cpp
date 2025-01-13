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
		int n, c, q;
		string s;
		cin >> n >> c >> q >> s;

		vector<int> left(c + 1), right(c + 1), diff(c + 1);
		left[0] = 0, right[0] = n;
		for (int i = 1, l, r; i <= c; ++i) {
			cin >> l >> r;
			l -= 1, r -= 1;
			left[i] = right[i - 1];
			right[i] = left[i] + (r - l + 1);
			diff[i] = left[i] - l;
		}

		int k, i;
		while (q--) {
			cin >> k;
			k -= 1, i = 0;
			for (int i = c; i >= 0; i--) {
				if (k < left[i]) continue;
				else k -= diff[i];
			}

			cout << s[k] << el;
		}
	}

	return 0;
}
