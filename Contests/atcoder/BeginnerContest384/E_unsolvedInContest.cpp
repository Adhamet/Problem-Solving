#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ull = unsigned long long;
#define int long long
#define fst first
#define scd second
#define el '\n'

const int MAXN = 505;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int h, w, d, p, q, strength = 0;
int grid[MAXN][MAXN];
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN, false));
bool valid(int x, int y) {
	return (x >= 0 && x < h && y >= 0 && y < w);
}

void bfs(int f, int s) {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({-grid[f][s], {f, s}});
	vis[f][s] = true;

	while (!pq.empty()) {
		int currStrength = -pq.top().first;
		auto [x, y] = pq.top().second;
		pq.pop();

		if (strength > 0 & (__int128)currStrength * (__int128)d >= (__int128)strength) break;
		strength += currStrength;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (valid(nx, ny) && !vis[nx][ny]) {
				vis[nx][ny] = true;
				pq.push({-grid[nx][ny], {nx, ny}});
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> h >> w >> d;
	cin >> p >> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
		}
	}

	p -= 1, q -= 1;
	bfs(p, q);
	cout << strength << el;
	return 0;
}
