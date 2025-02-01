#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, testcase = 1;
	while (cin >> n >> m) {
		set<char> forbidden;
		vector<bool> vis(n, false);
		for (int i = 0; i < m; ++i) {
			char digit;
			cin >> digit;
			forbidden.insert(digit);
		}

		queue<pair<string, int>> q;
		for (char digit = '1'; digit <= '9'; ++digit) {
			if (!forbidden.count(digit)) {
				int rem = (digit - '0') % n;
				q.push({string(1, digit), rem});
			}
		}

		string ans = "-1";
		while (!q.empty()) {
			string curr = q.front().first;
			int rem = q.front().second;
			q.pop();

			if (rem == 0) {
				ans = curr;
				break;
			}

			for (char digit = '0'; digit <= '9'; ++digit) {
				if (!forbidden.count(digit)) {
					string next = curr + digit;
					int nextRem = (rem * 10 + (digit - '0')) % n;
					if (!vis[nextRem]) {
						vis[nextRem] = true;
						q.push({next, nextRem});
					}
				}
			}
		}

		cout << "Case " << testcase++ << ": " << ans << el;
	}

	return 0;
}
