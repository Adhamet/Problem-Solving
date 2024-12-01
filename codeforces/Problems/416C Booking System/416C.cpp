#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1], v[i][2] = i + 1;
	sort(v.begin(), v.end(), [](auto &a, auto &b) {
			if (a[1] == b[1]) return a[0] < b[0];
			return a[1] > b[1];
	});

	int m;
	cin >> m;
	vector<array<int, 2>> t(m);
	for (int i = 0; i < m; i++) cin >> t[i][0], t[i][1] = i + 1;
	sort(t.begin(), t.end());

	ll tot = 0;
	vector<bool> used(m, false);
	vector<pair<int, int>> ans;

	for (auto &req: v) {
		int c = req[0], p = req[1], id = req[2];
		for (int i = 0; i < m; i++) {
			if (!used[i] && t[i][0] >= c) {
				used[i] = true;
				tot += p;
				ans.push_back({id, t[i][1]});
				break;
			}
		}
	}

	cout << ans.size() << " " << tot << el;
	for (auto &pr: ans) cout << pr.first << " " << pr.second << el;
	return 0;
}
