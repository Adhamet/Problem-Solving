#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1 ,1};

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
bool dfs(int x, int y, int px, int py, char col) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (grid[nx][ny] == col) {
				if (vis[nx][ny] && !(nx == px && ny == py)) return true;
				else if (!vis[nx][ny]) {
					if (dfs(nx, ny, x, y, col)) return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; i++) cin >> grid[i];
	vis.assign(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				if (dfs(i, j, -1, -1, grid[i][j])) {
					return cout << "Yes", 0;
				}
			}
		}
	}

	return cout << "No", 0;
}
