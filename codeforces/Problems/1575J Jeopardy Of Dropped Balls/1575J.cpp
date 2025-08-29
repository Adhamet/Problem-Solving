#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m, k;	cin >> n >> m >> k;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];

	auto isInside = [&](auto cur) { return cur[0]>=0 && cur[0]<n && cur[1]>=0 && cur[1]<m; };

	for (int i = 0; i < k; ++i) {
		int x;	cin >> x;
		--x;

		array<int,2> cur = {0, x};
		while (isInside(cur)) {
			int dir = g[cur[0]][cur[1]];
			if (dir == 1) g[cur[0]][cur[1]] = 2, cur[1]++;
			else if (dir == 3) g[cur[0]][cur[1]] = 2, cur[1]--;
			else g[cur[0]][cur[1]] = 2, cur[0]++;
		}
		
		cout << cur[1] + 1 << ' ';
	}	

	return 0;
}

