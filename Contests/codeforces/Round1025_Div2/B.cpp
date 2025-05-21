#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		vector<pair<int, char>> cuts;
		cuts.push_back({a - 1, 'n'});
		cuts.push_back({n - a, 'n'});
		cuts.push_back({b - 1, 'm'});
		cuts.push_back({m - b, 'm'});

		auto mnCut = *min_element(cuts.begin(), cuts.end());
		if (mnCut.second == 'n') {
			if (a - 1 <= n - a) n -= (n - a);
			else n -= (a - 1);
		} else {
			if (b - 1 <= m - b) m -= (m - b);
			else m -= (b - 1);
		}

		int ans = 1;
		while (n != 1 || m != 1) {
			int newA = (n%2)? (n+1)/2: n/2;
			int newB = (m%2)? (m+1)/2: m/2;

			vector<pair<int, char>> cuts;
			if (n != 1) {
				cuts.push_back({newA, 'n'});
				cuts.push_back({n - newA, 'n'});
			}

			if (m != 1) {
				cuts.push_back({newB, 'm'});
				cuts.push_back({m - newB, 'm'});
			}

			auto mnCut = *min_element(cuts.begin(), cuts.end());
			if (mnCut.second == 'n') n = mnCut.first;
			else m = mnCut.first;
			ans++;
		}

		cout << ans << el;
	}

	return 0;
}

