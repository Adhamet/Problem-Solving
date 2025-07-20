#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;

	vector<vector<int>> d(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];

	vector<int> add(n);
	for (int i = 0; i < n; ++i) cin >> add[i], --add[i];

	vector<i64> ans;
	vector<bool> allow(n, false);
	reverse(add.begin(), add.end());

	for (int k = 0; k < n; ++k) {
		allow[add[k]] = true;

		i64 sm = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][add[k]] + d[add[k]][j]);
				if (allow[i] && allow[j]) sm += d[i][j];
			}
		}

		ans.push_back(sm);
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
	return 0;
}
