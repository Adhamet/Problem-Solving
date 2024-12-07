#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

set<pair<int, int>> solve(int h, int w, pair<int, int> pt, int d, vector<string>& grid) {
	set<pair<int, int>> currRes;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '.' && abs(i - pt.first) + abs(j - pt.second) <= d) currRes.insert({i, j});
		}
	}

	return currRes;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int h, w, d;
	cin >> h >> w >> d;
	
	vector<string> grid(h);
	for (int i = 0; i < h; i++) cin >> grid[i];

	vector<pair<int, int>> floor;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '.') floor.push_back({i, j});
		}
	}

	int mx = 0, n = floor.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto pt1 = floor[i], pt2 = floor[j];

			auto calc1 = solve(h, w, pt1, d, grid);
			auto calc2 = solve(h, w, pt2, d, grid);

			set<pair<int, int>> currRes = calc1;
			currRes.insert(begin(calc2), end(calc2));

			mx = max(mx, (int)currRes.size());
		}
	}

	cout << mx << el;
	return 0;
}
