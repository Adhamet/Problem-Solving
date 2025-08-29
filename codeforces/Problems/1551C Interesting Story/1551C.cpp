#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; ++i) cin >> s[i];

		int ans = 0;
		for (char ch = 'a'; ch <= 'e'; ch++) {
			vector<int> scores;
			for (auto &w: s) {
				int cntCh = 0;
				for (auto &c: w) if (c == ch) ++cntCh;
				scores.push_back(2 * cntCh - (int)w.size());
			}

			sort(scores.rbegin(), scores.rend());
			int accuScore = 0, cntW = 0;
			for (auto &csc: scores) {
				accuScore += csc;
				if (accuScore > 0) ++cntW;
				else break;
			}

			ans = max(ans, cntW);
		}

		cout << ans << '\n';
	}

	return 0;
}
