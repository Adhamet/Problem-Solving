#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const i64 MOD = 1e9+7, MXN = 1e5+5;

	vector<vector<int>> divisors(MXN);
	for (int i = 1; i < MXN; ++i)
		for (int j = i; j < MXN; j += i)
			divisors[j].push_back(i);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<vector<int>> pos(MXN + 1);
		for (int i = 0; i < n; ++i) pos[a[i]].push_back(i);

		i64 ans = 0;
		for (int x = 1; x < MXN; ++x) {
			if ((int)pos[x].size() < 2) continue;

			i64 cursm = 0;
			for (int i = 0; i < (int)pos[x].size(); ++i) {
				int ii = pos[x][i];
				i64 cntAfter = 0;
				for (int d: divisors[x]) {
					auto it = lower_bound(pos[d].begin(), pos[d].end(), ii + 1);
					cntAfter += pos[d].end() - it;
				}

				ans = (ans + cursm * cntAfter % MOD) % MOD;

				i64 cntBefore = 0;
				for (int d: divisors[x]) {
					auto it = lower_bound(pos[d].begin(), pos[d].end(), ii);
					cntBefore += it - pos[d].begin();
				}

				cursm = (cursm + cntBefore) % MOD;
			}
		}

		cout << ans << el;
	}

	return 0;
}

