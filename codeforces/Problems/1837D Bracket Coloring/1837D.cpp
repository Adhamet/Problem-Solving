#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define fst first
#define scd second
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> ans(n, 0);
		deque<pair<char, int>> dq;
		for (int i = 0; i < n; i++) {
			dq.push_back({s[i], i});
			if (dq.front().fst == '(' && dq.back().fst == ')') {
				ans[dq.front().scd] = 1, ans[dq.back().scd] = 1;
				dq.pop_back(), dq.pop_front();
			} else if (dq.front().fst == ')' && dq.back().fst == '(') {
				ans[dq.front().scd] = 2, ans[dq.back().scd] = 2;
				dq.pop_back(), dq.pop_front();
			}
		}

		if (!dq.empty()) cout << -1 << el;
		else {
			int mx = *max_element(ans.begin(), ans.end());
			int mn = *min_element(ans.begin(), ans.end());
			if (mx == mn) {
				cout << 1 << el;
				for (auto itm: ans) cout << 1 << " ";
			} else {
				cout << 2 << el;
				for (auto itm: ans) cout << itm << " ";
			}

			cout << el;
		}
	}

	return 0;
}
