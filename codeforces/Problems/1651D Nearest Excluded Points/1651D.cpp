#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int dr[] = {-1, 0, 1, 0};
	const int dc[] = {0, -1, 0, 1};
	int n;
	cin >> n;
	set<array<int, 2>> vis;
	vector<array<int, 2>> a(n);
	for (int i = 0, x, y; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
		vis.insert(a[i]);
	}

	map<array<int, 2>, array<int, 2>> ans;
	queue<array<int, 2>> q;
	for (auto xy: a) {
		for (int i = 0; i < 4; ++i) {
			array<int, 2> nxny = {xy[0] + dr[i], xy[1] + dc[i]};
			if (!vis.count(nxny)) {
				ans[xy] = nxny;
				q.push(xy);
				break;
			}
		}
	}

	while (!q.empty()) {
		array<int, 2> xy = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			array<int, 2> nxny = {xy[0] + dr[i], xy[1] + dc[i]};
			if (vis.count(nxny) && !ans.count(nxny)) {
				ans[nxny] = ans[xy];
				q.push(nxny);
			}
		}
	}

	for (auto xy: a) cout << ans[xy][0] << ' ' << ans[xy][1] << el;
	return 0;
}
