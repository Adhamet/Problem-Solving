#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define pii pair<int,int>
#define fst first
#define scd second
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int dr[] = {0, 1, 0, 1}; // right, down, left, down
	const int dc[] = {1, 0, -1, 0};
	int n, m, k; cin >> n >> m >> k;
	auto valid = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };

	int eachTube = (n * m) / k, currdir = 0;

	int x = 0, y = 0, covered = 1;
	vector<vector<pii>> tubes(k);
	tubes[0].push_back({x, y});

	for (int i = 0; i < k; ++i) {
		int mv = eachTube;
		if (i == 0) mv -= 1;
		while (mv--) {
			int nx = x + dr[currdir];
			int ny = y + dc[currdir];
			if (!valid(nx, ny)) {
				currdir = (currdir + 1) % 4;
				mv += 1;
			} else {
				tubes[i].push_back({nx,ny});
				covered += 1;
				x = nx, y = ny;
				if (covered == n*m) break;
				if (currdir==1 || currdir==3)
					currdir = (currdir + 1) % 4;
				if (i == k - 1) mv+=1;
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		cout << (int)tubes[i].size() << ' ';
		for (auto& cd: tubes[i]) cout << cd.fst+1 << ' ' << cd.scd+1 << ' ';
		cout << el;
	}

	return 0;
}
