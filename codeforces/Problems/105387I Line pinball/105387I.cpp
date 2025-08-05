#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	vector<vector<int>> s(n + 1);
	for (int x = 1; x <= n; ++x) s[0].push_back(x);

	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		if (s[i].empty()) p[i] = n;
		else {
			int cur = INT_MAX;
			for (auto &x: s[i])
				cur = min(cur, x * (n - i + 1) - 1);
			p[i] = cur;
			for (auto &x: s[i]) {
				int j = i + p[i] / x;
				if (j < n) s[j].push_back(x);
			}
		}
	}

	for (int i = 0; i < n; ++i) cout << p[i] << ' ';
	return 0;
}
