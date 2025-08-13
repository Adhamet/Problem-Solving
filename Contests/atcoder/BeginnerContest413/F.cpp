#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int dr[4] = {-1, 1, 0, 0};
	const int dc[4] = {0, 0, -1, 1};

	int H, W, K;	cin >> H >> W >> K;
	vector<vector<int>> dist(H, vector<int>(W, 1e9));
	vector<vector<char>> seen(H, vector<char>(W, 0));
	queue<pair<int,int>> q;
	for (int k = 0; k < K; ++k) {
		int r, c;	cin >> r >> c;
		--r, --c;
		dist[r][c] = 0;
		q.push({r,c});
	}

	while (!q.empty()) {
		auto [i,j] = q.front();		q.pop();
		for (int d = 0; d < 4; ++d) {
			int ni = i + dr[d], nj = j + dc[d];

			if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
			if (dist[ni][nj] != 1e9) continue;

			if (!seen[ni][nj]) seen[ni][nj] = 1;
			else {
				dist[ni][nj] = dist[i][j] + 1;
				q.push({ni,nj});
			}
		}
	}

	i64 ans = 0;
	for (int i = 0; i < H; ++i) 
		for (int j = 0; j < W; ++j) 
			if (dist[i][j] != 1e9) ans += dist[i][j];
	return cout << ans, 0;
}

