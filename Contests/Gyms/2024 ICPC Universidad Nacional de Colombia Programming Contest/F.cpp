#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
bool valid(int r, int c, int n, int m) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int r, c;	cin >> r >> c;
	vector<vector<char>> g(r, vector<char>(c));

	array<int,2> gh, pac;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> g[i][j];
			if (g[i][j] == 'P') pac = {i,j};
			else if (g[i][j] == 'G') gh = {i,j};
		}
	}

	string path;	cin >> path;
	vector<array<int,2>> pacD;
	pacD.push_back(pac);
	for (char move : path) {
		int nx = pac[0], ny = pac[1];
		if (move == 'L') ny = (pac[1] - 1 + c) % c;
		else if (move == 'R') ny = (pac[1] + 1) % c;
		else if (move == 'U') nx = (pac[0] - 1 + r) % r;
		else if (move == 'D') nx = (pac[0] + 1) % r;
		if (g[nx][ny] != '#') {
			pac[0] = nx;
			pac[1] = ny;
		}

		pacD.push_back(pac);
	}

	queue<array<int, 2>> q;
	q.push({gh[0], gh[1]});
	vector<vector<int>> distG(r, vector<int>(c, -1));
	distG[gh[0]][gh[1]] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dr[i];
			int ny = y + dc[i];

			if (valid(nx, ny, r, c) && g[nx][ny] != '#' && distG[nx][ny] == -1) {
				distG[nx][ny] = distG[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}

	for (int t = 0; t < (int)pacD.size(); ++t) {
		auto [x, y] = pacD[t];
		if (distG[x][y] != -1 && distG[x][y] <= t) return cout << "Yes", 0;
	}

	return cout << "No", 0;
}

