#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, ex, ey;
bool acc;
vector<vector<bool>> vis;
vector<vector<int>> adjmtx;
bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y, vector<int>& subset) {
	if (!valid(x, y) || vis[x][y] || acc) return;
	if (x == ex && y == ey) {
		acc = true;
		return;
	};
	if (find(subset.begin(), subset.end(), adjmtx[x][y]) == subset.end()) return;

	vis[x][y] = true;
	for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i], subset);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		adjmtx.assign(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> adjmtx[i][j];
			}
		}

		int sx, sy;
		cin >> sx >> sy >> ex >> ey;

		int totSubsets = (1 << 10), mn = LLONG_MAX;
		int reqMask = (1 << adjmtx[sx][sy]) | (1 << adjmtx[ex][ey]);
		for (int mask = 0; mask < totSubsets; ++mask) {
			if ((mask & reqMask) == reqMask) {
				acc = false;

				vector<int> subset;
				for (int i = 0; i < 10; ++i) if (mask & (1 << i)) {
					subset.push_back(nums[i]);
				}

				vis.assign(n, vector<bool>(n, false));
				dfs(sx, sy, subset);
				if (acc) mn = min(mn, (int)subset.size());
			}
		}

		cout << mn << el;
	}

	return 0;
}
