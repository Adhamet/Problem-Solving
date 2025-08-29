#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc;	cin >> tc;
	while (tc--) {
		int n;	cin >> n;
		string a, b;	cin >> a >> b;

		string xoring = a;
		string ones = a, zeros = a;

		for (int i = 0; i < n; ++i) {
			xoring[i] = (a[i] == b[i] ? '0': '1');
			ones[i] = '1';
			zeros[i] = '0';
		}

		if (xoring != ones && xoring != zeros) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		if (a == zeros && b == zeros) {
			cout << 0 << "\n";
			continue;
		}

		vector<pair<int,int>> ans;

		if (xoring == zeros) {
			ans.emplace_back(1, n);
			xoring = ones;
			for (auto &x: a) x = (x == '1'? '0': '1');
		}

		vector<pair<char, int>> freq = {{a[0], 1}};
		for (int i = 1; i < n; ++i) {
			if (a[i] == freq.back().first) freq.back().second++;
			else freq.emplace_back(a[i], 1);
		}

		int idx = 0, cnt_rep = 0;
		for (auto &x: freq) {
			if (x.first == '1') {
				ans.emplace_back(idx + 1, idx + x.second);
				cnt_rep += 1;
			}
			idx += x.second;
		}

		if (cnt_rep % 2 == 0) {
			ans.emplace_back(1, 1);
			ans.emplace_back(1, n);
			ans.emplace_back(2, n);
		}

		cout << (int)ans.size() << "\n";
		for (auto &x: ans) cout << x.first << ' ' << x.second << "\n";
	}

	return 0;
}
